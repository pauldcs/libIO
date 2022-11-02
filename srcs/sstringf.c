/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:54 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 02:14:03 by pducos           ###   ########.fr       */
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

	memset(&iob, '\0', sizeof(t_iobuf));
	iob.data = str;
	iob.cap = IOBUF_MAX - 1;
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	*(char *)(iob.data + iob.len) = '\0';
	return (iob.len);
}
