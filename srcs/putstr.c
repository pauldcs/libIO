/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:56 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 12:55:25 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

size_t	putstr(const char *format, ...)
{
	static char	buf[IOBUF_MAX];
	va_list		ap;
	t_iobuf		iob;

	lf_mem_set(&iob, '\0', sizeof(t_iobuf));
	iob.data = buf;
	iob.cap = sizeof(buf);
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	return (lf_write_all(
			STDOUT_FILENO,
			iob.data,
			iob.len));
}
