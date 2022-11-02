/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:39 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 02:15:30 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdint.h>
#include <stddef.h>

void	__hex(t_iobuf *iob, const uint32_t n)
{
	uint64_t	tmp;
	char		bytes[16];
	size_t		i;

	i = 16;
	if (n == 0)
		bytes[--i] = '0';
	else
	{
		tmp = n;
		while (i && tmp)
		{
			bytes[--i] = "0123456789abcdef"[tmp & 0xf];
			tmp >>= 4;
		}
	}
	field_pad(iob, 16 - i);
	iob_write(iob, &bytes[i], 16 - i);
}
