/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_iob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:08:02 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 21:09:11 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libIO.h"

void	init_iob(t_iobuf *iob)
{
	static char	buf[BUFFER_SIZE];

	iob->dst = (uint8_t *)buf;
	iob->cap = BUFFER_SIZE;
	iob->size = 0;
	iob->trunc = 0;
}
