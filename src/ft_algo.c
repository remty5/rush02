/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:01:49 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/23 19:51:44 by aallou-v         ###   ########.fr       */
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

void	ft_putvalues(t_entry *dict, unsigned long long values, int x)
{
	int	i;

	i = 0;
	if (values == 0 && x == 0)
		return ;
	while (dict[i].n != values)
		i++;
	ft_putstr(dict[i].v);
	write(1, " ", 1);
}

void	ft_algo(t_entry *dict, char *values, unsigned int mod)
{
	if (ft_strlen(values) == 3)
	{
		ft_putvalues(dict, values[0] - 48, 0);
		if (values[0] != '0')
			ft_putvalues(dict, 100, 0);
		if (values[1] - 48 != 0 && values[1] - 48 != 1)
			ft_putvalues(dict, (values[1] - 48) * 10, 0);
		if (values[2] - 48 != 0 && values[1] - 48 != 1)
			ft_putvalues(dict, values[2] - 48, 0);
		if (values[1] - 48 == 1)
			ft_putvalues(dict, 10 + values[2] - 48, 0);
	}
	if (ft_strlen(values) == 2)
	{
		if (values[0] - 48 != 1)
			ft_putvalues(dict, (values[0] - 48) * 10, 0);
		if (values[1] - 48 != 0 && values[0] - 48 != 1)
			ft_putvalues(dict, values[1] - 48, 0);
		if (values[0] - 48 == 1)
			ft_putvalues(dict, 10 + values[1] - 48, 0);
	}
	if (ft_strlen(values) == 1)
		ft_putvalues(dict, values[0] - 48, 0);
	if (mod != 100)
		ft_putvalues(dict, mod, 0);
}

void	ft_show(t_entry *dict, char *values)
{
	int		len;
	int		i;
	char	vals[4][4];

	if (stris0(values))
		ft_putvalues(dict, 0, 1);
	if (stris0(values))
		return ;
	len = ft_strlen(values);
	i = -1;
	while (++i < 16)
		vals[i / 4][i % 4] = '\0';
	i = -1;
	while (++i < len)
		vals[(12 - len + i) / 3][(12 - len + i) % 3] = values[i];
	i = -1;
	if (len > 9 && !stris0(vals[0] + 12 - len))
		ft_algo(dict, vals[0] + 12 - len, 1000000000);
	if (len > 6 && !stris0(vals[1] + ((12 - len) % 3) * !(len > 9)))
		ft_algo(dict, vals[1] + ((12 - len) % 3) * !(len > 9), 1000000);
	if (len > 3 && !stris0(vals[2] + ((12 - len) % 3) * !(len > 6)))
		ft_algo(dict, vals[2] + ((12 - len) % 3) * !(len > 6), 1000);
	ft_algo(dict, vals[3] + ((12 - len) % 3) * !(len > 3), 100);
}
