/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:42 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 02:15:33 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>

void	__int(t_iobuf *iob, const int32_t c)
{
	char		nbr[20];
	uint32_t	n;
	size_t		i;

	if (c < 0)
		n = c * -1;
	else
		n = c;
	i = 20;
	if (n == 0)
		nbr[--i] = '0';
	while (n)
	{
		nbr[--i] = (n % 10) | 0x30;
		n /= 10;
	}
	if (c < 0)
		nbr[--i] = '-';
	field_pad(iob, 20 - i);
	iob_write(iob, &nbr[i], 20 - i);
}
