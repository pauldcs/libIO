/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnstringf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:47 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 00:20:42 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

size_t	cnstringf(char **ptr, const char *format, ...)
{
	static char	buf[IOBUF_SIZE];
	va_list	ap;
	t_iobuf	iob;

	memset(&iob, '\0', sizeof(t_iobuf));
	iob.data = buf;
	iob.cap = sizeof(buf) - 1;
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	*ptr = malloc(iob.len + 1);
	if (*ptr)
	{
		memcpy(*ptr, iob.data, iob.len);
		(*ptr)[iob.len] = '\0';
	}
	return (iob.len);
}
