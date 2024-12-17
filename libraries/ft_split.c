/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:20:31 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:20:31 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	count_words(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
			count++;
		while (*str && !ft_isspace(*str))
			str++;
	}
	return (count);
}

char	*malloc_number(const char *str)
{
	int		i;
	int		j;
	char	*numb;

	i = 0;
	j = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	numb = (char *)malloc(sizeof(char) * (i + 1));
	if (!numb)
		return (NULL);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		numb[j++] = str[i++];
	while (str[i] && !ft_isspace(str[i]))
	{
		if (str[i] >= '0' && str[i] <= '9')
			numb[j++] = str[i++];
		else
			return (ft_free(numb));
	}
	numb[j] = '\0';
	return (numb);
}

char	**ft_split(const char *str)
{
	int		i;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!arr || !str)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			arr[i] = malloc_number(str);
			if (arr[i] == NULL)
				return (ft_clean0(arr, i));
			i++;
		}
		while (*str && !ft_isspace(*str))
			str++;
	}
	arr[i] = NULL;
	return (arr);
}
