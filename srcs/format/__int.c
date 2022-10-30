/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:42 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 23:51:15 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>

void	__int(t_iobuf *iob, const int64_t c)
{
	static int8_t	nbr[20];
	uint64_t		n;
	int				i;

	n = c;
	i = 20;
	if (n == 0)
		nbr[--i] = '0';
	if (c < 0)
		n = c * -1;
	while (n)
	{
		nbr[--i] = (n % 10) | 0x30;
		n /= 10;
	}
	if (c < 0)
		nbr[--i] = '-';
	writer(iob, (uint8_t *)&nbr[i], 20 - i);
}
