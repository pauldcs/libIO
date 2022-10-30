/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:07:45 by pducos            #+#    #+#             */
/*   Updated: 2022/10/30 22:06:19 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>
#include <string.h>

void	__str(t_iobuf *iob, const char *s)
{
	if (s)
		writer(iob, (uint8_t *)s, strlen(s));
}
