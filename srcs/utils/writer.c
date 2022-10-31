/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:08:07 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 09:48:04 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include <stddef.h>
#include <stdint.h>

void	write_field(t_iobuf *iob, size_t n)
{
	size_t	ct;

	ct = 0;
	if (n < (size_t)iob->fwidth)
		n = iob->fwidth - n;
	else
		return ;
	while (ct + iob->size < iob->cap && ct < n)
	{
		iob->dst[iob->size + ct] = ' ';
		ct++;
	}
	iob->size += ct;
	iob->trunc += n - ct;
}

void	writer(t_iobuf *iob, const char *src, size_t n)
{
	size_t	ct;

	ct = 0;
	while (ct + iob->size < iob->cap && ct < n)
	{
		iob->dst[iob->size + ct] = src[ct];
		ct++;
	}
	iob->size += ct;
	iob->trunc += n - ct;
}
