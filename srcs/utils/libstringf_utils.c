/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstringf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:52:32 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 12:56:48 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <limits.h>

size_t	lf_write_all(int fd, const void *buf, size_t s)
{
	ssize_t	c;
	size_t	ret;

	ret = 0;
	while (s)
	{
		c = write(fd, buf + ret, s);
		if (c == -1)
			break ;
		ret += c;
		s -= c;
	}
	return (ret);
}

void	lf_mem_copy(void *dst, const void *src, size_t len)
{
	while (len)
	{
		*(char *)dst = *(const char *)src;
		dst++;
		src++;
		len--;
	}
}

void	lf_mem_set(void *p, char byte, size_t n)
{
	while (n)
	{
		*(char *)p = byte;
		n--;
		p++;
	}
}

char	*lf_str_to_uint(char *str, int *result)
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
