/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:04:06 by linux-babas       #+#    #+#             */
/*   Updated: 2024/11/15 02:00:17 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ft_strpbrk.c: Finds the first occurrence of any character from one string 
				in another */
/* ft_strspn.c: Calculates the length of the initial segment of a string 
				consisting only of characters found in another string */
/* ft_strtok.c: Splits a string into tokens based on 
				one or multiple delimiters */

static char	*ft_strpbrk(const char *s, const char *accept, bool skip_quote)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	quote = false;
	while (s[i])
	{
		j = 0;
		if (skip_quote && quote == 0 && (s[i] == '\'' || s[i] == '\"'))
			quote = s[i];
		else if (quote == s[i])
			quote = 0;
		if (quote == 0)
		{
			while (accept[j])
			{
				if (s[i] == accept[j])
					return ((char *)&s[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

static int	handle_quotes(const char *s, size_t *i, char *quote, bool skip)
{
	if (skip && !*quote && (s[*i] == '\'' || s[*i] == '\"'))
		*quote = s[*i];
	else if (*quote == s[*i])
		*quote = 0;
	return (*quote == 0);
}

static int	check_accepted_chars(const char *s, size_t *i, const char *accept)
{
	size_t	j;

	j = 0;
	while (accept[j])
	{
		if (s[*i] == accept[j])
			return (1);
		j++;
	}
	return (0);
}

static size_t	ft_strspn(const char *s, const char *accept, bool skip_quote)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = 0;
	while (s[i])
	{
		if (!handle_quotes(s, &i, &quote, skip_quote))
			break ;
		if (check_accepted_chars(s, &i, accept))
			i++;
		else
			break ;
	}
	return (i);
}

char	*ft_strtok(char *str, const char *delim, bool skip_quote)
{
	static char	*saved_str;
	char		*token;

	if (!str)
		str = saved_str;
	if (!str)
		return (NULL);
	str += ft_strspn(str, delim, skip_quote);
	if (!*str)
	{
		saved_str = NULL;
		return (NULL);
	}
	token = str;
	str = ft_strpbrk(token, delim, skip_quote);
	if (str)
	{
		*str = '\0';
		saved_str = str + 1;
	}
	else
		saved_str = NULL;
	return (token);
}
