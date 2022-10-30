/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libIO.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:50:00 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 20:53:42 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIO_H
# define LIBIO_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

# define BUFFER_SIZE 4096

typedef struct s_iobuf {
	uint8_t *dst;
	size_t	cap;
	size_t	size;
	size_t	trunc;
}	t_iobuf;

size_t	fstringf(int fd, const char *fmt, ...);
size_t	stringf(const char *fmt, ...);
char	*cnstringf(size_t n, const char *fmt, ...);
size_t	sstringf(char *str, const char *fmt, ...);
size_t	snstringf(char *str, size_t n, const char *fmt, ...);
void	vsnstringf(t_iobuf *iob, const char *fmt, va_list *ap);

void	__int(t_iobuf *iob, const int64_t c);
void	__str(t_iobuf *iob, const char *s);
void	__hex(t_iobuf *iob, const uint64_t n);
void	__ptr(t_iobuf *iob, const uint64_t *p);

void	init_iob(t_iobuf *iob);
void	writer(t_iobuf *iob, const uint8_t *src, size_t n);
size_t	write_all(int fd, const void *buf, size_t s);

#endif
