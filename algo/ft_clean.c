/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:40:50 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/18 05:38:38 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clean(char **arr, int i)
{
	i--;
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

char	**ft_clean0(char **array, int i)
{
	ft_clean(array, i);
	return (NULL);
}

char	*ft_free(char *numb)
{
	if (numb)
		free(numb);
	return (NULL);
}
