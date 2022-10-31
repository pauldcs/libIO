/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:56 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 01:01:35 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

size_t	stringf(const char *fmt, ...)
{
	static char	buf[BUFFER_SIZE];
	va_list	ap;
	t_iobuf	iob;

	va_start(ap, fmt);
	memset(&buf, 0x00, BUFFER_SIZE);
	iob.dst = (uint8_t *)buf;
	iob.cap = BUFFER_SIZE;
	iob.size = 0;
	iob.trunc = 0;
	do_formatting(&iob, fmt, &ap);
	write_all(1, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}
