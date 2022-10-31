/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:56 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 21:24:05 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

size_t	stringf(const char *format, ...)
{
	static char	buf[IOBUF_SIZE];
	va_list		ap;
	t_iobuf		iob;

	memset(&iob, 0x00, sizeof(t_iobuf));
	iob.dst = buf;
	iob.cap = IOBUF_SIZE;
	va_start(ap, format);
	formatter(&iob, format, &ap);
	va_end(ap);
	return (write_all(
		STDOUT_FILENO,
		iob.dst,
		iob.size));
}
