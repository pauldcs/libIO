/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:42 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 08:59:21 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>

void	__int(t_iobuf *iob, int32_t c)
{
	char		nbr[20];
	uint32_t	n;
	int			i;

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
	writer(iob, &nbr[i], 20 - i);
}
