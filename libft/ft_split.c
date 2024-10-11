/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:03:40 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/07 23:16:56 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **dest, int i)
{
	while (i > 0)
	{
		i--;
		free(dest[i]);
	}
	free(dest);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **dest, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		dest[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!dest[word])
			return (free_array(dest, word));
		ft_putword(dest[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	dest[word] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char			**dest;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!dest)
		return (0);
	dest = ft_split_words(s, c, dest, num_words);
	return (dest);
}

/*#include <stdio.h>

void print_split_result(char **split)
{
	for (int i = 0; split[i] != NULL; i++)
	{
		printf("Word %d: '%s'\n", i, split[i]);
	}
}

int main(void)
{
	char *test1 = "lorem ipsum dolor sit amet, consectetur adipiscing elit.
	Sed non risus.
	 Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,
	 ultricies
	 sed,
	  dolor. Cras elementum ultricies diam.
	  Maecenas ligula massa, varius a, semper congue, euismod non, mi.";


	char **result;

	printf("Test 1:\n");
	result = ft_split(test1, 'i');
	print_split_result(result);

	return 0;
}*/
