/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:56 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 00:07:46 by pducos           ###   ########.fr       */
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

	memset(&iob, '\0', sizeof(t_iobuf));
	iob.data = buf;
	iob.cap = sizeof(buf);
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	return (write_all(
		STDOUT_FILENO,
		iob.data,
		iob.len));
}
