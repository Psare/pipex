/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:11:50 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:28:37 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	i = ft_strlen(s);
	ch = c;
	if (ch == '\0')
		return ((char *)s + i);
	while (i--)
	{
		if (s[i] == ch)
			return ((char *)s + i);
	}
	return (NULL);
}
