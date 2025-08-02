/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etienne.petrilli <etienne.petrilli@learne  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:03:58 by etienne.petri     #+#    #+#             */
/*   Updated: 2025/08/02 20:49:31 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_rep_line(char *str)
{
	int i;
	int j;

	i = 1;
	j = 2;
	while (i <= 3)
	{
		j = i + 1;
		while (j <= 4)
		{
			//printf("%d == %d", str[i], str[j]);
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_left_line(char *str)
{
	int i;
	int count;
	char max;

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

int     check_right_line(char *str)
{
        int i;
        int count;
        char max;

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

int     check_top_column(char **str)
{
        int	i;
	int	j;
        int	count;
        char	max;

        max = '0';
        i = 1;
	j = 1;
        while (j <= 4)
        {
		i = 0;
		while (i <= 4)
		{
                	if (str[i][j] > max)
                	{
                       		max = str[i][j];
                       		count++;
               		}
                	i++;
		}
		if (count != str[0][j])
			return (0);
        	j++;
	}
	return (1);
}

int     check_bot_column(char **str)
{
        int     i;
        int     j;
        int     count;
        char    max;

        max = '0';
        i = 5;
        j = 1;
        while (j <= 4)
        {
                i = 0;
                while (i >= 1)
                {
                        if (str[i][j] > max)
                        {
                                max = str[i][j];
                                count++;
                        }
                        i--;
                }
                if (count != str[0][j])
                        return (0);
                j++;
        }
        return (1);
}


int	check_tab(char **str)
{
	int res;
	int i;

	i = 1;
	res = 1;
	while (i <= 4)
	{
		if (check_rep_line(str[i]) == '0')
			return (0);
		else if (check_right_line(str[i]) == '0')
			return (0);
		i++;
	}
	if (check_bot_column(str) == '0')
		return (0);
	if (check_top_column(str) == '1');
		return (0);
	return (1);
}
