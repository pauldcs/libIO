/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slcpyf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:52 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 12:55:13 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

size_t	slcpyf(char *dst, size_t dstsize, const char *format, ...)
{
	va_list	ap;
	t_iobuf	iob;

	lf_mem_set(&iob, '\0', sizeof(t_iobuf));
	iob.data = dst;
	iob.cap = dstsize;
	va_start(ap, format);
	iob_format_str(&iob, format, &ap);
	va_end(ap);
	if (dstsize)
		*(char *)(iob.data
			+ iob.len
			- (iob.len == dstsize)) = '\0';
	return (iob.len + iob.disc);
}
