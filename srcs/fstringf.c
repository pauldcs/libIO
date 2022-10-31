/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:49 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 17:41:32 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>

size_t	fstringf(int fd, const char *fmt, ...)
{
	char	buf[BUFFER_SIZE];
	va_list	ap;
	t_iobuf	iob;

	va_start(ap, fmt);
	iob.dst = buf;
	iob.cap = BUFFER_SIZE;
	iob.size = 0;
	iob.trunc = 0;
	iob.fwidth = 0;
	formatter(&iob, fmt, &ap);
	write_all(fd, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}
