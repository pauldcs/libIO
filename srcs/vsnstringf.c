/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsnstringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:08:10 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 21:08:52 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libIO.h"
#include <stdarg.h>
#include <string.h>

void	vsnstringf(t_iobuf *iob, const char *fmt, va_list *ap)
{
	char	*ptr;

	ptr = (char *)fmt;
	while (*ptr)
	{
		while (*ptr && *ptr != '%')
			writer(iob, (uint8_t *)ptr++, 1);
		if (*ptr && ptr++)
		{
			if (*ptr == 'd' && ptr++)
				__int(iob, va_arg(*ap, int64_t));
			else if (*ptr == 's' && ptr++)
				__str(iob, va_arg(*ap, char *));
			else if (*ptr == 'x' && ptr++)
				__hex(iob, va_arg(*ap, uint64_t));
			else if (*ptr == 'p' && ptr++)
				__ptr(iob, va_arg(*ap, uint64_t *));
			else if (*ptr == '%')
				writer(iob, (uint8_t *)ptr++, 1);
		}
	}
}
