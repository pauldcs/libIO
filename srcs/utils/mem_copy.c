/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:11:01 by nmathieu          #+#    #+#             */
/*   Updated: 2022/11/02 10:48:32 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	mem_copy(void *dst, const void *src, size_t len)
{
	while (len)
	{
		*(char *)dst = *(const char *)src;
		dst++;
		src++;
		len--;
	}
}
