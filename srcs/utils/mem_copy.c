/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:25:29 by pducos            #+#    #+#             */
/*   Updated: 2022/11/02 19:25:31 by pducos           ###   ########.fr       */
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
