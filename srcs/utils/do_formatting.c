/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_formatting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:08:10 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 09:55:59 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

static char	*absorbe_fwidth(t_iobuf *iob, char *str)
{
	char	*ret;
	int		fwidth;

	ret = str_to_uint(str, &fwidth);
	if (ret && *ret)
	{
		iob->fwidth = fwidth;
		return (ret);
	}
	return (str);
}

void	do_formatting(t_iobuf *iob, const char *fmt, va_list *ap)
{
	char	*ptr;

	ptr = (char *)fmt;
	while (*ptr)
	{
		while (*ptr && *ptr != '%')
			writer(iob, ptr++, 1);
		if (*ptr++)
		{
			iob->fwidth = 0;
			ptr = absorbe_fwidth(iob, ptr);
			if (*ptr == 'd' && ptr++)
				__int(iob, va_arg(*ap, int32_t));
			else if (*ptr == 's' && ptr++)
				__str(iob, va_arg(*ap, char *));
			else if (*ptr == 'x' && ptr++)
				__hex(iob, va_arg(*ap, uint32_t), "0123456789abcdef");
			/*else if (*ptr == 'X' && ptr++)
				__hex(iob, va_arg(*ap, uint64_t), "0123456789ABCDEF");*/
			else if (*ptr == 'p' && ptr++)
				__ptr(iob, va_arg(*ap, uint64_t *));
			else if (*ptr == '%')
				writer(iob, ptr++, 1);
		}
		else
			break ;
	}
}
