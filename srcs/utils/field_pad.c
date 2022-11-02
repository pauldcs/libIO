/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_pad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:25:06 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 19:26:11 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>

void	field_pad(t_iobuf *iob, size_t size)
{
	while (iob->field.width > size++)
		iob_write(iob, " ", 1);
}
