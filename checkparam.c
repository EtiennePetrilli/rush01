/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:53:04 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2025/08/03 17:55:42 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_digit(char *str, char digit)
{
	int	positions[16];
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < 32)
	{
		positions[i / 2] = i;
		i += 2;
	}
	i = 0;
	while (i < 16)
	{
		count = 0;
		j = -1;
		while (j++ < 3)
			if (str[positions[i + j]] == digit)
				count++;
		if (count > 1)
			return (0);
		i += 4;
	}
	return (1);
}

int	check_valid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '4') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_possible(char *str)
{
	int	i;
	int	sum1;
	int	sum2;

	i = 0;
	while (i <= 6)
	{
		sum1 = (str[i] - '0') + (str[i + 8] - '0');
		if (sum1 < 3 || sum1 > 5)
			return (0);
		if (str[i] == '4' && str[i + 8] != '1')
			return (0);
		i += 2;
	}
	i = 16;
	while (i <= 22)
	{
		sum2 = (str[i] - '0') + (str[i + 8] - '0');
		if (sum2 < 3 || sum2 > 5)
			return (0);
		if (str[i] == '4' && str[i + 8] != '1')
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_check_param(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) != 31)
		return (0);
	if (check_possible(str) == 0)
		return (0);
	if (check_valid_char(str) == 0)
		return (0);
	if (check_digit(str, '4') == 0)
		return (0);
	if (check_digit(str, '1') == 0)
		return (0);
	return (1);
}
