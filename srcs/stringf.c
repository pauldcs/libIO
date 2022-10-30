/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:56 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 21:53:23 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libIO.h"
#include <stdarg.h>
#include <stddef.h>

size_t	stringf(const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	init_iob(&iob);
	va_start(ap, fmt);
	do_formatting(&iob, fmt, &ap);
	write_all(1, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}
