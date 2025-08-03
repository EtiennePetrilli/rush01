/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:20:27 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/03 14:45:39 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_check_param(char *str);
int	check_valid(char **str, int x, int y);
int	check_left_view(char *str);
int	check_right_view(char *str);
int	check_top_view(char *str);
int	check_bot_view(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_print_tab(char **tab)
{
	int i;
	
	i = 0;

	while(i < 6)
	{
		ft_putstr(tab[i]);
		i++;
		ft_putchar('\n');
	}
}

char	**tab_init(char **tab)
{
	int i;
	int j;
	
	i = 0;
	while(i < 6)
	{
		j = 0;
		tab[i] = malloc(7 * sizeof(char));
		while(j < 6)
		{
			if ((i == 0 && j == 0 )|| (i == 0 && j == 5) 
					|| (j == 0 && i == 5) || (j == 5 && i ==5))
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
	while(j <= 4)
	{
		tab[i][j] = str[k];
		k = k + 2;
		j++;
	}
	j = 1;
	i = 5;
	while(j <= 4)
	{
		tab[i][j] = str[k];
		k = k + 2;
		j++;
	}
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

int	resolve(char **puzzle, int row, int col)
{
	int new_row;
	int new_col;
	int i;
	int row_view;
	int col_view;

	i = 1;
	row_view = 1;
	col_view = 1;
	if (row == 5)
		return (1);
	if (col == 4)
	{
		new_row = row + 1;
	}
	else
	{
		new_row = row;
	}
	new_col = (col == 3) ? 1 : (col + 1) % 4;
	//ft_putchar(row + 48);
	//ft_putchar(' ');
	//ft_putchar(col + 48);
	//ft_putchar('\n');
	while (i <= 4)
	{	
		
		puzzle[row][col] = i + 48;
		//ft_print_tab(puzzle);
		if (check_valid(puzzle, row, col))
		{
			//ft_print_tab(puzzle);
			if (col == 4)
			{
				row_view = check_left_view(puzzle[row]);
				if (row_view == 1)
					row_view = check_right_view(puzzle[row]);
			}
			if (row == 4)
			{
				col_view = check_top_view(puzzle[col]);
				if (col_view == 1)
					col_view = check_bot_view(puzzle[col]);
			}
			if (row_view && col_view)
				if (resolve(puzzle, new_row, new_col))
					return (1);
		}
		puzzle[row][col] = '0';
		i++;
	}	
	return (0);
}

int	main(int argc, char **argv)
{
		char **puzzle;

		puzzle = malloc(6 * sizeof(char *));
		puzzle = tab_init(puzzle);
		if (argc != 2)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		if (ft_check_param(argv[1]) == 0)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		//ft_print_tab(puzzle);
		puzzle = fill_param(argv[1], puzzle);
		//puzzle[1][1] = '1';
		//puzzle[1][2] = '2';
		//puzzle[1][3] = '3';
		//puzzle[1][4] = '4';
		//ft_putchar(check_valid(puzzle, 1, 4) + 48);
		if (resolve(puzzle, 1, 1))
			ft_print_tab(puzzle);
		//else
		//{
		//	write(1, "Error\n", 6);
		//	return (-1);
		//}
		free(puzzle);	
		return (0);
}
