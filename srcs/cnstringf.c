/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnstringf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:47 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 17:41:34 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

char	*cnstringf(size_t n, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	iob.dst = malloc(n);
	if (!iob.dst)
		return (NULL);
	iob.cap = n - 1;
	iob.size = 0;
	iob.fwidth = 0;
	va_start(ap, fmt);
	formatter(&iob, fmt, &ap);
	iob.dst[iob.size] = '\0';
	va_end(ap);
	return ((char *)iob.dst);
}
