/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:49 by pducos            #+#    #+#             */
/*   Updated: 2022/11/01 18:12:14 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

size_t	fstringf(int fd, const char *format, ...)
{
	static char	buf[IOBUF_SIZE];
	va_list		ap;
	t_iobuf		iob;

	memset(&iob, 0x00, sizeof(t_iobuf));
	iob.data = buf;
	iob.cap = IOBUF_SIZE;
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	write_all(fd, iob.data, iob.len);
	va_end(ap);
	return (iob.len);
}
