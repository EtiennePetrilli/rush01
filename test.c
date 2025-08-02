/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:20:27 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/02 20:51:38 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_check_param(char *str);

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
		if (tab[i][j] == '4')
		{
			tab[i + 1][j] = '1';
			tab[i + 2][j] = '2';
			tab[i + 3][j] = '3';
			tab[i + 4][j] = '4';
		}
		else if (tab[i][j] == '1')
			tab[i + 1][j] = '4';
		k = k + 2;
		j++;
	}
	j = 1;
	i = 5;
	while(j <= 4)
	{
		tab[i][j] = str[k];
                if (tab[i][j] == '4')
                {
                        tab[i - 1][j] = '1';
                        tab[i - 2][j] = '2';
                        tab[i - 3][j] = '3';
                        tab[i - 4][j] = '4';
                }
                else if (tab[i][j] == '1')
                        tab[i - 1][j] = '4';

		k = k + 2;
		j++;
	}
	j = 0;
	i = 1;
	while (i <= 4)
	{
		tab[i][j] = str[k];
                if (tab[i][j] == '4')
                {
                        tab[i][j + 1] = '1';
                        tab[i][j + 2] = '2';
                        tab[i][j + 3] = '3';
                        tab[i][j + 4] = '4';
                }
                else if (tab[i][j] == '1')
                        tab[i][j + 1] = '4';

		k = k + 2;
		i++;
	}
	j = 5;
	i = 1;
	while (i <= 4)
	{
		tab[i][j] = str[k];
		if (tab[i][j] == '4')
                {
                        tab[i][j - 1] = '1';
                        tab[i][j - 2] = '2';
                        tab[i][j - 3] = '3';
                        tab[i][j - 4] = '4';
                }
                else if (tab[i][j] == '1')
                        tab[i + 1][j] = '4';
		if (k < 30)
			k += 2;
		i++;
	}
	return (tab);
}

char	**resolve1(char **puzzle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (puzzle[i][j])
	{
		if (puzzle[i][j] == '4' && i == 0)
		{
			puzzle[i + 1][j] = '1';
			puzzle[i + 2][j] = '2';
			puzzle[i + 3][j] = '3';
			puzzle[i + 4][j] = '4';
		}
		j++;
	}
	return (puzzle);
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
		ft_print_tab(puzzle);
		puzzle = fill_param(argv[1], puzzle);
		puzzle = resolve1(puzzle);
		ft_print_tab(puzzle);
		free(puzzle);	

		return (0);
}
