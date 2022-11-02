/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fputstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:49 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 19:28:21 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>

size_t	fputstr(int fd, const char *format, ...)
{
	static char	buf[IOBUF_MAX];
	va_list		ap;
	t_iobuf		iob;

	mem_set(&iob, '\0', sizeof(t_iobuf));
	iob.data = buf;
	iob.cap = sizeof(buf);
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	return (write_all(
			fd,
			iob.data,
			iob.len));
}
