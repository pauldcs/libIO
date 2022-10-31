/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:39 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 08:49:03 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdint.h>
#include <stddef.h>

void	__hex(t_iobuf *iob, uint64_t n, char *base)
{
	uint64_t	tmp;
	char		bytes[16];
	int			i;

	i = 16;
	if (n == 0)
		bytes[--i] = '0';
	else
	{
		tmp = n;
		while (i && tmp)
		{
			bytes[--i] = base[tmp & 0xf];
			tmp >>= 4;
		}
	}
	writer(iob, &bytes[i], 16 - i);
}
