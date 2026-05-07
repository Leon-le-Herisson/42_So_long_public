/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:21:07 by bamagere          #+#    #+#             */
/*   Updated: 2025/11/12 02:44:46 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab, unsigned int j_index)
{
	unsigned int	i;

	i = 0;
	while (i < j_index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	counter;
	unsigned int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static char	**fill_tab(char **tab, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	i = 0;
	j = 0;
	while (s[i] && j < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_substr(s, start, (i - start));
		if (!tab[j])
		{
			free_tab(tab, j);
			return (NULL);
		}
		start = i;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

/**
 * @brief Splits a string into substrings separated by character c.
 * @return char** NULL-terminated array of newly allocated substrings.
 */
char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	fill_tab(tab, s, c);
	return (tab);
}
