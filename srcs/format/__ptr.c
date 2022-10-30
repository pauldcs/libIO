/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:43 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 21:08:30 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libIO.h"
#include <stdint.h>
#include <stddef.h>

void	__ptr(t_iobuf *iob, const uint64_t *p)
{
	uint64_t		ptr;
	static char		hex[18];
	int				i;

	i = 18;
	if (p == 0)
		hex[--i] = '0';
	ptr = (uint64_t)p;
	while (ptr && i)
	{
		hex[--i] = "0123456789abcdef"[ptr & 0xf];
		ptr >>= 4;
	}
	hex[--i] = 'x';
	hex[--i] = '0';
	writer(
		iob,
		(uint8_t *)&hex[i],
		18 - i);
}
