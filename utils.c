/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:30:00 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2025/08/03 19:30:00 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**tab_init(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		tab[i] = malloc(7 * sizeof(char));
		while (j < 6)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == 5) || (j == 0 && i == 5)
				|| (j == 5 && i == 5))
				tab[i][j] = 'x';
			else
				tab[i][j] = '0';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

char	**fill_param_2(char *str, char **tab, int k)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i <= 4)
	{
		tab[i][j] = str[k];
		k = k + 2;
		i++;
	}
	j = 5;
	i = 1;
	while (i <= 4)
	{
		tab[i][j] = str[k];
		if (k < 30)
			k += 2;
		i++;
	}
	return (tab);
}

char	**fill_param(char *str, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (j <= 4)
	{
		tab[i][j] = str[k];
		k = k + 2;
		j++;
	}
	j = 1;
	i = 5;
	while (j <= 4)
	{
		tab[i][j] = str[k];
		k = k + 2;
		j++;
	}
	tab = fill_param_2(str, tab, k);
	return (tab);
}

void	get_next_cell(int row, int col, int *new_row, int *new_col)
{
	if (col == 4)
		*new_row = row + 1;
	else
		*new_row = row;
	if (col == 3)
		*new_col = 4;
	else
		*new_col = (col + 1) % 4;
}

void	ft_init(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}
