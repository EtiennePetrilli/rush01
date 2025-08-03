/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:20:27 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/03 19:18:05 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		check_valid(char **str, int x, int y);
int		check_left_view(char *str);
int		check_right_view(char *str);
int		check_top_view(char **str, int col);
int		check_bot_view(char **str, int col);
int		resolve(char **puzzle, int row, int column);
char	**fill_param_2(char *str, char **tab, int k);
void	ft_putchar(char c);
void	ft_print_tab(char **tab);

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
			if ((i == 0 && j == 0) || (i == 0 && j == 5)
				|| (j == 0 && i == 5) || (j == 5 && i == 5))
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

int	resolve(char **puzzle, int row, int col)
{
	int	row_view[2];
	int	col_view[2];
	int	new_row;
	int	new_col;
	int	i;

	if (row == 5)
		return (1);
	ft_init(&row_view[0], &row_view[1], &col_view[0], &col_view[1]);
	get_next_cell(row, col, &new_row, &new_col);
	printf("new_row = %d, new_col = %d\n", new_row, new_col);
	i = 1;
	while (i <= 4)
	{
		puzzle[row][col] = i + '0';
		if (check_valid(puzzle, row, col))
		{
			if (col == 4)
			{
				row_view[0] = check_left_view(puzzle[row]);
				row_view[1] = check_right_view(puzzle[row]);
			}
			if (row == 4)
			{
				col_view[0] = check_top_view(puzzle, col);
				col_view[1] = check_bot_view(puzzle, col);
			}
			if (row_view[0] && row_view[1] && col_view[0] && col_view[1])
				if (resolve(puzzle, new_row, new_col))
					return (1);
		}
		puzzle[row][col] = '0';
		i++;
	}
	return (0);
}
/*
int	resolve(char **puzzle, int row, int col)
{
	int	new_row;
	int	new_col;
	int	i;
	int	row_view[2];
	int	col_view[2];

	i = 0;
	row_view[0] = 1;
	row_view[1] = 1;
	col_view[0] = 1;
	col_view[1] = 1;
	if (row == 5)
		return (1);
	if (col == 4)
		new_row = row + 1;
	else
		new_row = row;
	new_col = (col == 3) ? 4 : (col + 1) % 4;
	while (++i <= 4)
	{
		puzzle[row][col] = i + 48;
		if (check_valid(puzzle, row, col))
		{
			if (col == 4)
			{
				row_view[0] = check_left_view(puzzle[row]);
				row_view[1] = check_right_view(puzzle[row]);
			}
			if (row == 4)
			{
				col_view[0] = check_top_view(puzzle, col);
				col_view[1] = check_bot_view(puzzle, col);
			}
			if (row_view[0] && row_view[1] && col_view[0] && col_view[1])
				if (resolve(puzzle, new_row, new_col))
					return (1);
		}
		puzzle[row][col] = '0';
	}
	return (0);
}*/
