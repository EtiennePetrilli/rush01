/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:20:27 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/03 20:20:44 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		check_valid(char **str, int x, int y);
int		check_left_view(char *str);
int		check_right_view(char *str);
int		check_top_view(char **str, int col);
int		check_bot_view(char **str, int col);
int		resolve(char **puzzle, int row, int column);
void	get_next_position(int row, int col, int *new_row, int *new_col);
int		check_views_complete(char **puzzle, int row, int col);
void	ft_putchar(char c);
void	ft_print_tab(char **tab);

void	get_next_position(int row, int col, int *new_row, int *new_col)
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

int	check_views_complete(char **puzzle, int row, int col)
{
	int	row_view[2];
	int	col_view[2];

	row_view[0] = 1;
	row_view[1] = 1;
	col_view[0] = 1;
	col_view[1] = 1;
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
	return (row_view[0] && row_view[1] && col_view[0] && col_view[1]);
}

int	resolve(char **puzzle, int row, int col)
{
	int	new_row;
	int	new_col;
	int	i;

	if (row == 5)
		return (1);
	get_next_position(row, col, &new_row, &new_col);
	i = 0;
	while (++i <= 4)
	{
		puzzle[row][col] = i + 48;
		if (check_valid(puzzle, row, col))
		{
			if (check_views_complete(puzzle, row, col))
				if (resolve(puzzle, new_row, new_col))
					return (1);
		}
		puzzle[row][col] = '0';
	}
	return (0);
}
