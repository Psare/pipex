/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:26:54 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:28:30 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (len);
		}
		i++;
	}
	return (len);
}

static char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*in_str(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		strs_len;
	char	**str;

	strs_len = ft_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (strs_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < strs_len)
	{
		while (s[0] == c)
			s++;
		str[i] = in_str(s, c);
		if (!str[i])
		{
			ft_free(str);
			return (NULL);
		}
		s = s + ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
