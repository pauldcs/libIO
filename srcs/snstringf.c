/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snstringf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:52 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 22:03:13 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

size_t	snstringf(char *str, size_t n, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	iob.dst = (uint8_t *)str;
	iob.cap = n - 1;
	iob.size = 0;
	va_start(ap, fmt);
	do_formatting(&iob, fmt, &ap);
	iob.dst[iob.size] = '\0';
	va_end(ap);
	return (iob.size + iob.trunc);
}
