/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstringf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:49 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 21:09:02 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libIO.h"
#include <stdarg.h>
#include <stddef.h>

size_t	fstringf(int fd, const char *fmt, ...)
{
	va_list	ap;
	t_iobuf	iob;

	init_iob(&iob);
	va_start(ap, fmt);
	vsnstringf(&iob, fmt, &ap);
	write_all(fd, iob.dst, iob.size);
	va_end(ap);
	return (iob.size);
}
