/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:56 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 09:58:37 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>

size_t	stringf(const char *fmt, ...)
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
	do_formatting(&iob, fmt, &ap);
	va_end(ap);
	write_all(1, iob.dst, iob.size);
	return (iob.size);
}
