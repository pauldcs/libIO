/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:45 by pducos            #+#    #+#             */
/*   Updated: 2022/11/01 23:21:52 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>
#include <string.h>

void	__str(t_iobuf *iob, char *s)
{
	if (s)
	{
		field_pad(iob, strlen(s));
		iob_write(iob, s, strlen(s));
	}
	else
	{
		field_pad(iob, 6);
		iob_write(iob, "(null)", 6);
	}
}
