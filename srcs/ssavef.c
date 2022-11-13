/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssavef.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:47 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 12:55:13 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

ssize_t	ssavef(char **dst, const char *format, ...)
{
	static char	buf[IOBUF_MAX];
	va_list		ap;
	t_iobuf		iob;

	lf_mem_set(&iob, '\0', sizeof(t_iobuf));
	iob.data = buf;
	iob.cap = sizeof(buf) - 1;
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	*dst = malloc(iob.len + 1);
	if (*dst)
	{
		lf_mem_copy(*dst, iob.data, iob.len);
		(*dst)[iob.len] = '\0';
		return (iob.len + iob.disc);
	}
	return (-1);
}
