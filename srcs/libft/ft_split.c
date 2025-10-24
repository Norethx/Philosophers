/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:33:15 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/24 16:55:28 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	quantity_words;
	int	i;

	quantity_words = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (((s[i] != 0 && s[i] != c)) && (s[i + 1] == c || s[i + 1] == 0))
			quantity_words++;
		i++;
	}
	return (quantity_words);
}

static void	*ft_free_array(void **s)
{
	int	i;

	i = 0;
	while (s[i] != ((void *)0))
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (((void *)0));
}

char	**ft_split(char const *s, char c)
{
	int		begin;
	int		end;
	char	**set_words;
	int		i_arr;

	begin = 0;
	i_arr = 0;
	set_words = (char **)ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!set_words)
		return ((void *)0);
	while (s[begin] != 0)
	{
		end = 0;
		while (s[begin + end] != c && s[begin + end] != 0)
			end++;
		if (end > 0)
		{
			set_words[i_arr] = ft_substr(s, begin, end);
			if (!set_words[i_arr++])
				return (ft_free_array((void **)set_words));
			begin += end - 1;
		}
		begin++;
	}
	return (set_words);
}
