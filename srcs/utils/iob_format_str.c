/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iob_format_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:08:10 by pducos            #+#    #+#             */
/*   Updated: 2022/11/01 23:55:34 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

inline static char *format_field(t_iobuf *iob, char *ptr, va_list *ap)
{
	char	*tmp;
	int		valid;

	valid = 0;
	iob->width = 0;
	tmp = str_to_uint(
		ptr, (int *)&iob->width);
	if (!tmp)
		return (ptr);
	if (*tmp == 'd' && ++tmp && ++valid)
		__int(iob, va_arg(* ap, int32_t));
	else if (*tmp == 's' && ++tmp && ++valid)
		__str(iob, va_arg(*ap, char *));
	else if (*tmp == 'x' && ++tmp && ++valid)
		__hex(iob, va_arg(*ap, uint32_t));
	else if (*tmp == 'p' && ++tmp && ++valid)
		__ptr(iob, va_arg(*ap, uint64_t *));
	if (valid)
		return (tmp);
	return (iob_write(iob, "%", 1), ptr);
}

void	iob_format_str(t_iobuf *iob, const char *format, va_list *ap)
{
	char	*ptr;

	ptr = (char *)format;
	while (*ptr)
	{
		while (*ptr && *ptr != '%')
			iob_write(iob, ptr++, 1);
		if (!*ptr++)
			break ;
		ptr = format_field(iob, ptr, ap);
	}
}
