/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:03:40 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/11 13:51:37 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_countw(char const *s, char c)
{
	size_t	count;
	int		inword;

	count = 0;
	inword = 0;
	while (*s)
	{
		if (*s == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	*ft_malloc(char **res, int i, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		while (i > 0)
			free(res[--i]);
		free(res);
		return (NULL);
	}
	return (str);
}

void	fill(char **res, char const *s, char c, size_t *i)
{
	size_t	len;

	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			res[*i] = ft_malloc(res, *i, len);
			if (!res[*i])
				return ;
			ft_strlcpy(res[*i], s, len + 1);
			(*i)++;
		}
		s += len;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	numword;
	char	**res;
	size_t	i;

	if (!s)
		return (NULL);
	numword = ft_countw(s, c);
	res = (char **)malloc(sizeof(char *) * (numword + 1));
	if (!res)
		return (NULL);
	i = 0;
	fill(res, s, c, &i);
	res[i] = NULL;
	return (res);
}

/*
int	main(void)
{
	char	str[] = "salut comment vas tu ?";
	char	c = ' ';

	ft_split(str, c);
}*/
