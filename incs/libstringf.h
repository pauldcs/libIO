/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstringf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:50:00 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 08:59:18 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRINGF_H
# define LIBSTRINGF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

# define BUFFER_SIZE 4096

typedef struct s_iobuf {
	char	*dst;
	size_t	cap;
	size_t	size;
	size_t	trunc;
}	t_iobuf;

void	__int(t_iobuf *iob, int32_t c);
void	__str(t_iobuf *iob, char *s);
void	__hex(t_iobuf *iob, uint64_t n, char *base);
void	__ptr(t_iobuf *iob, uint64_t *p);

void	do_formatting(t_iobuf *iob, const char *fmt, va_list *ap);

/**
 * @brief tries to write 'n' bytes into iob->dst.
 * If iob->size have reached iob->cap, iob->trunc will be incremented by the
 * number of bytes truncated. The number of bytes actually written
 * into iob->dst is stored in iob->size. The buffer is not null terminated.
 * 
 * @param iob pointer to the iobuf structure
 * @param src the source to copy
 * @param n the size of src
 */
void	writer(t_iobuf *iob, const char *src, size_t n);
size_t	write_all(int fd, const void *buf, size_t s);

/**
 * @brief write output to stdout.
 * 
 * @param fmt The format string
 * @param ... arguments
 * @return The number of bytes written 
 */
size_t	stringf(const char *fmt, ...);

/**
 * @brief write output to file descriptor 'fd'.
 * 
 * @param fd - File descriptor to write to
 * @param fmt - The format string
 * @param ... - arguments
 * @return The number of bytes written
 */
size_t	fstringf(int fd, const char *fmt, ...);

/**
 * @brief write output to string 'str'.
 * 
 * @param str The string to write to
 * @param fmt The format string
 * @param ... Arguments
 * @return The number of bytes written 
 */
size_t	sstringf(char *str, const char *fmt, ...);

/**
 * @brief write at most 'n' bytes to str.
 * if the return value is greater than or equal to the size argument,
 * the string was too short and some of the printed characters
 * were discarded.  The output is always null-terminated,
 * unless size is 0.
 * 
 * @param str The string to write to
 * @param n The maximum number of characters to write (including null bytes)
 * @param fmt The format string
 * @param ... Arguments
 * @return The numbers of bytes written + the number of bytes truncated
 */
size_t	snstringf(char *str, size_t n, const char *fmt, ...);

/**
 * @brief Allocates 'n' bytes and formats the maximum
 * amount of characters. Always null terminated unless 'n' is 0.
 * The returned pointer must be freed.
 *	
 * @param n Maximum size of the allocation
 * @param fmt The format string
 * @param ... Arguments
 * @return The allocated string
 */
char	*cnstringf(size_t n, const char *fmt, ...);

#endif
