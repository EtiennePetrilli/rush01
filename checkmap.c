/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:03:58 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/03 17:07:35 by jihane.arfaou    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c);

int	check_left_view(char *str)
{
	int		i;
	int		count;
	char	max;

	max = '0';
	i = 1;
	count = 0;
	while (i <= 4)
	{
		if (str[i] > max)
		{
			max = str[i];
			count ++;
		}
		i++;
	}
	if (count == str[0] - 48)
		return (1);
	else
		return (0);
}

int	check_right_view(char *str)
{
	int		i;
	int		count;
	char	max;

	max = '0';
	i = 4;
	count = 0;
	while (i >= 1)
	{
		if (str[i] > max)
		{
			max = str[i];
			count ++;
		}
		i--;
	}
	if (count == str[5] - 48)
		return (1);
	else
		return (0);
}

int	check_top_view(char **str, int col)
{
	int		i;
	int		count;
	char	max;

	max = '0';
	i = 1;
	count = 0;
	while (i <= 4)
	{
		if (str[i][col] > max)
		{
			max = str[i][col];
			count++;
		}
		i++;
	}
	if (count != str[0][col] - 48)
		return (0);
	return (1);
}

int	check_bot_view(char **str, int col)
{
	int		i;
	int		count;
	char	max;

	max = '0';
	i = 4;
	count = 0;
	while (i >= 1)
	{
		if (str[i][col] > max)
		{
			max = str[i][col];
			count++;
		}
		i--;
	}
	if (count != str[5][col] - 48)
		return (0);
	return (1);
}

int	check_valid(char **str, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = y;
	while (i <= 4)
	{
		if (str[x][y] == str[i][j] && i != x)
			return (0);
		i++;
	}
	i = x;
	j = 1;
	while (j <= 4)
	{
		if (str[x][y] == str[i][j] && j != y)
			return (0);
		j++;
	}
	return (1);
}
