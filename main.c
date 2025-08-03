/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:20:27 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/03 18:11:16 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_check_param(char *str);
int		resolve(char **puzzle, int row, int column);
char	**tab_init(char **tab);
char	**fill_param(char *str, char **tab);

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
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			ft_putchar(tab[i][j]);
			if (j != 4)
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	char	**puzzle;

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
	puzzle = fill_param(argv[1], puzzle);
	if (resolve(puzzle, 1, 1))
		ft_print_tab(puzzle);
	else
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	free_tab(puzzle);
	return (0);
}
