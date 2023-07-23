/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:01:49 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/22 15:08:01 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	stris0(char *values)
{
	int	i;

	i = -1;
	while (values[++i])
		if (values[i] != '0')
			return (0);
	return (1);
}

void	ft_putvalues(t_entry *dict, unsigned long long values)
{
	int	i;

	i = 0;
	while (dict[i].n != values)
		i++;
	ft_putstr(dict[i].v);
	write(1, " ", 1);
}

int	ft_checkalgo(char *values)
{
	if (ft_strlen(values) == 3)
		if (values[0] == '0' && values[1] == '0' && values[2] == '0')
			return (0);
	if (ft_strlen(values) == 2)
		if (values[0] == '0' && values[1] == '0')
			return (0);
	if (ft_strlen(values) == 1)
		if (values[0] == '0')
			return (0);
	return (1);
}

void	ft_algo(t_entry *dict, char *values, unsigned int mod)
{
	if (ft_checkalgo(values) == 0)
		return ;
	if (ft_strlen(values) == 3)
	{
		ft_putvalues(dict, values[0] - 48);
		ft_putvalues(dict, 100);
		if (values[1] - 48 != 0 && values[1] - 48 != 1)
			ft_putvalues(dict, (values[1] - 48) * 10);
		if (values[2] - 48 != 0 && values[1] - 48 != 1)
			ft_putvalues(dict, values[2] - 48);
		if (values[1] - 48 == 1)
			ft_putvalues(dict, 10 + values[2] - 48);
	}
	if (ft_strlen(values) == 2)
	{
		if (values[1] - 48 != 1)
		ft_putvalues(dict, (values[0] - 48) * 10);
		if (values[1] - 48 != 0 && values[0] - 48 != 1)
			ft_putvalues(dict, values[1] - 48);
		if (values[1] - 48 == 1)
			ft_putvalues(dict, 10 + values[4] - 48);
	}
	if (ft_strlen(values) == 1)
		ft_putvalues(dict, values[0] - 48);
	ft_putvalues(dict, mod);
}

void	ft_show(t_entry *dict, char *values)
{
	int	i;

	if (stris0(values))
	{
		write(1, "2", 1);
		ft_putvalues(dict, 0);
		return ;
	}
	i = -1;
	//040040040100
	ft_algo(dict, "040", 1000000000);
	ft_algo(dict, "04", 1000000);
	ft_algo(dict, "400", 1000);
	ft_algo(dict, "100", 100);
}

/*
void	ft_show_dix(t_entry *dict, char *values, int calcul, int i)
{
	if (ft_strlen(values) - i == 2 && calcul != 1)
	{
		ft_putvalues(dict, 10 * calcul);
		if (values[i + 1] - 48 != 0)
			ft_putvalues(dict, values[i + 1] - 48);
	}
	if (ft_strlen(values) - i == 2 && calcul == 1)
	{
		ft_putvalues(dict, 10 + values[i + 1] - 48);
		return ;
	}
	if (ft_strlen(values) - i == 1)
		if (ft_strlen(values) - i )
			if(values[i])
		else
			ft_putvalues(dict, values[i] - 48);
}

void	ft_show(t_entry *dict, char *values)
{
	int	i;
	int	calcul;
	int len;

	i = -1;
	while (values[++i])
	{
		len = ft_strlen(values) - i;
		calcul = values[i] - 48;
		if ((len == 10 || len == 7 || len == 4 || len == 3) && calcul != 0)
		{
			ft_putvalues(dict, calcul);
			continue ;
		}
		if (len == 10)
			ft_putvalues(dict, 1000000000);
		if (len == 7)
			ft_putvalues(dict, 1000000);
		if (len == 4)
			ft_putvalues(dict, 1000);
		if (len == 3)
			ft_putvalues(dict, 100);
		ft_show_dix(dict, values, calcul, i);
	}
}*/
