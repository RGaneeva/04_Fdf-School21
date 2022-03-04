/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:03:49 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:38:50 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_in_str(char const *string, char c)
{
	int	i;
	int	wordscounter;

	i = 0;
	wordscounter = 0;
	while (string[i] != '\0')
	{
		if (string[i] != c && (string[i + 1] == c || string[i + 1] == '\0'))
			wordscounter++;
		i++;
	}
	return (wordscounter);
}

static int	ft_symbs_in_word(char const *word, char c)
{
	int	i;

	i = 0;
	while (word[i] != '\0' && word[i] != c)
		i++;
	return (i);
}

static void	*ft_free_mem(char **result, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		free(result[k]);
		k++;
	}
	free(result);
	return (0);
}

static char	**ft_arrayfill(const char *str, int i, char sym, char **result)
{
	int	j;
	int	k;
	int	lenght;

	j = 0;
	while (j < i)
	{
		while (*str == sym)
			str++;
		lenght = ft_symbs_in_word(str, sym);
		result[j] = malloc(sizeof(char) * (lenght + 1));
		if (!result)
			return (ft_free_mem(result, j));
		k = 0;
		while (k < lenght)
			result[j][k++] = *str++;
		result[j++][k] = '\0';
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(char const *str, char c)
{
	int		wordcount;
	char	**result;

	if (!str)
		return (0);
	wordcount = ft_words_in_str(str, c);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (0);
	result = ft_arrayfill(str, wordcount, c, result);
	return (result);
}
