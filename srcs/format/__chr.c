/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __chr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:14:14 by pducos            #+#    #+#             */
/*   Updated: 2022/11/27 23:23:45 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stdint.h>
#include <stddef.h>

void	__chr(t_iobuf *iob, const int c)
{
	char	buf[3];

	if (c >= 32 && c <= 126)
		iob_write(iob, (char *)&c, 1);
	else
	{
		buf[2] = "0123456789abcdef"[c & 0xf];
		buf[1] = "0123456789abcdef"[(c >> 4) & 0xf];
		buf[0] = '\\';
		iob_write(iob, buf, 3);
	}
}
