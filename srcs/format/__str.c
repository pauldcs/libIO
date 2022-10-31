/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:45 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 21:27:26 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>
#include <string.h>

void	__str(t_iobuf *iob, char *s)
{
	if (s)
	{
		field_padder(iob, strlen(s));
		writer(iob, s, strlen(s));
	}
	else
		writer(iob, "(null)", 6);
}
