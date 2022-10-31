/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:49 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 21:26:42 by pducos           ###   ########.fr       */
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
	iob.dst = buf;
	iob.cap = IOBUF_SIZE;
	va_start(ap, format);
	formatter(&iob, format, &ap);
	write_all(fd, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}
