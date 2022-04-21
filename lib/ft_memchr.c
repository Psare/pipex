/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:06:51 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:28:24 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char ) c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
