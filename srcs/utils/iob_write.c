/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iob_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:08:07 by pducos            #+#    #+#             */
/*   Updated: 2022/11/01 18:13:06 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>
#include <stdint.h>

void	iob_write(t_iobuf *iob, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n && iob->len + i < iob->cap)
	{
		*(unsigned char *)(iob->data + iob->len + i) = src[i];
		i++;
		n--;
	}
	iob->len += i;
	iob->disc += n;
}
