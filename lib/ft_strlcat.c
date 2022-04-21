/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:09:44 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:28:33 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dsts;
	size_t	srcs;

	i = 0;
	dsts = ft_strlen(dst);
	srcs = ft_strlen(src);
	if (dstsize < dsts + 1)
		return (dstsize + srcs);
	if (dstsize > dsts)
	{
		while (src[i] != '\0' && dsts + 1 + i < dstsize)
		{
			dst[dsts + i] = src[i];
			i++;
		}
	}
	dst[dsts + i] = '\0';
	return (dsts + srcs);
}
