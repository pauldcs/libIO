/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:54 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 21:26:37 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

size_t	sstringf(char *str, const char *format, ...)
{
	va_list	ap;
	t_iobuf	iob;

	memset(&iob, 0x00, sizeof(t_iobuf));
	iob.dst = str;
	iob.cap = IOBUF_SIZE - 1;
	va_start(ap, format);
	formatter(&iob, format, &ap);
	va_end(ap);
	*(iob.dst + iob.size) = 0x00;
	return (iob.size);
}
