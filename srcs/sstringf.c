/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:54 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 01:47:18 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

size_t	sstringf(char *str, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	iob.dst = str;
	iob.cap = BUFFER_SIZE - 1;
	iob.size = 0;
	va_start(ap, fmt);
	do_formatting(&iob, fmt, &ap);
	iob.dst[iob.size] = '\0';
	va_end(ap);
	return (iob.size);
}
