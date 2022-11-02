/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstringf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:50:00 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 00:56:56 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRINGF_H
# define LIBSTRINGF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>

# define IOBUF_SIZE 4096

typedef struct s_iobuf {
	void	*data;
	size_t	cap;
	size_t	len;
	size_t	disc;
	struct	s_field
	{
		size_t	width;
		bool	color;
	}	field;
}	t_iobuf;

void	__int(t_iobuf *iob, int32_t c);
void	__str(t_iobuf *iob, char *s);
void	__hex(t_iobuf *iob, uint32_t n);
void	__ptr(t_iobuf *iob, uint64_t *p);

void	iob_format_str(t_iobuf *iob, const char *format, va_list *ap);

void	iob_write(t_iobuf *iob, const char *src, size_t n);
void	field_pad(t_iobuf *iob, size_t size);
size_t	write_all(int fd, const void *buf, size_t s);
char	*str_to_uint(char *str, int *result);

size_t	stringf(const char *format, ...);
size_t	fstringf(int fd, const char *format, ...);
size_t	sstringf(char *str, const char *format, ...);
size_t	snstringf(char *str, size_t n, const char *format, ...);
size_t	cnstringf(char **ptr, const char *format, ...);

#endif
