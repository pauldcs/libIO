/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnstringf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:47 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 21:26:44 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char	*cnstringf(size_t n, const char *format, ...)
{
	va_list	ap;
	t_iobuf	iob;

	memset(&iob, 0x00, sizeof(t_iobuf));
	iob.cap = n;
	iob.dst = malloc(n + 1);
	if (!iob.dst)
		return (NULL);
	va_start(ap, format);
	formatter(&iob, format, &ap);
	va_end(ap);
	*(iob.dst + iob.size) = 0x00;
	return (iob.dst);
}
