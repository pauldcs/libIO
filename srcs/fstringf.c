/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:49 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 22:05:28 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <stddef.h>

static void	init_iob(t_iobuf *iob)
{
	static char	buf[BUFFER_SIZE];

	iob->dst = (uint8_t *)buf;
	iob->cap = BUFFER_SIZE;
	iob->size = 0;
	iob->trunc = 0;
}

size_t	fstringf(int fd, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	init_iob(&iob);
	va_start(ap, fmt);
	do_formatting(&iob, fmt, &ap);
	write_all(fd, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}
