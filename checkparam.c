/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:53:04 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2025/08/02 20:36:18 by etienne.petri    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_possible(char *str)
{
	int	i;
	int	sum1;
	int	sum2;

	i = 0;
	// colonnes
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
	// Lignes
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
	if (ft_strlen(str) != 31)
		return (0);
	if (check_possible(str) == 0)
		return (0);
	/*

	* Proprietes de la grille :

	*	*

		-On ne peut pas avoir plus de une fois le chiffre 4 ou 1 sur les parametres

	*  Si column1up vaut 4 les autres columnUp ne peuvent pas valoir 4 aussi idem

	*  pour 1;

	*- Un 4 doit etre face a un 1 et vice versa;

	- La string doit faire 31 char en comptant les espace et ne peut comprendre

	que des chiffres entre 1 et 4 inclus

	- Si un 4 est place il doit etre en miroir avec la colones ou la ligne

	* */
	return (1);
}
