/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:33:24 by pducos            #+#    #+#             */
/*   Updated: 2022/10/31 09:34:10 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

char	*str_to_uint(char *str, int *result)
{
	long	i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += *(str++) & 0xCF;
		if (i > INT_MAX)
			return (0);
	}
	*result = i;
	return (str);
}