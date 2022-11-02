/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstringf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:50:00 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 13:30:38 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRINGF_H
# define LIBSTRINGF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/types.h>

# define IOBUF_MAX 4096

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

/* writes output to stdout */
size_t	putstr(const char *format, ...);

/* writes output to fd */
size_t	fputstr(int fd, const char *format, ...);

/**
 * @brief copies a maximum of 'n' bytes of 'format' into 'dst'.
 * The result will be truncated if the format string is larger than
 * IOBUF_MAX or 'n'. the result is not null terminated.
 * @param dst The destination buffer
 * @param n Number of bytes to copy
 * @param format The format string
 * @param ... 
 * @return number of bytes copied + number of bytes truncated
 */
size_t	cpyf(void *dst, size_t n, const char *format, ...);

/**
 * @brief copies the 'format' into 'str'.
 * The result will be truncated if the format string is larger than
 * IOBUF_MAX. The result is always null terminated.
 * 
 * @param str The destination string
 * @param format The format string
 * @param ... 
 * @return number of bytes copied + number of bytes truncated
 */
size_t	scpyf(char *str, const char *format, ...);

size_t	slcpyf(char *str, size_t dstsize, const char *format, ...);

/**
 * @brief copies the format string into a new allocated buffer placed into 'dst'.
 * If the allocation fails, 'buf' is null and the return value is -1.
 * In any other case, 'buf' is guaranteed to be null terminated.
 * The result will be truncated if the format string is larger than
 * IOBUF_MAX.
 * @param dst pointer to the destination buffer
 * @param format the format string
 * @param ... 
 * @return the number of bytes copied + the number of bytes truncated
 */
ssize_t	ssavef(char **dst, const char *format, ...);

void	__int(t_iobuf *iob, const int32_t c);
void	__str(t_iobuf *iob, const char *s);
void	__hex(t_iobuf *iob, const uint32_t n);
void	__ptr(t_iobuf *iob, const uint64_t *p);

void	iob_format_str(t_iobuf *iob, const char *format, va_list *ap);

void	iob_write(t_iobuf *iob, const char *src, size_t n);
void	field_pad(t_iobuf *iob, size_t size);
size_t	write_all(int fd, const void *buf, size_t s);
char	*str_to_uint(char *str, int *result);
void	mem_copy(void *dst, const void *src, size_t len);
void	mem_set(void *p, char byte, size_t n);

#endif
