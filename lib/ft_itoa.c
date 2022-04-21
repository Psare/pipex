/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:05:40 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:28:17 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mincpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{	
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	ft_dop(char *res, int len, long min)
{
	while (min != 0 && len > 0)
	{
		len--;
		res[len] = min % 10 + '0';
		min = min / 10;
	}
	return ((char)res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	min;

	len = get_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	min = (long)n;
	if (n == -2147483648)
		return (ft_mincpy(res, "-2147483648"));
	res[len] = '\0';
	if (min < 0)
	{
		res[0] = '-';
		min = -min;
	}
	else if (min == 0)
		res[0] = '0';
	if (min != 0 && len > 0)
		ft_dop(res, len, min);
	return (res);
}
