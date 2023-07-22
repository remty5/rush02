/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:58:05 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/22 19:07:21 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_is_valid_nbr(char *str)
{
	int	i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	else
		return (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'));
}

int	ft_count_lines(char *str)
{
	int	i;
	int	n;
	int	c;

	i = -1;
	n = 0;
	c = 1;
	while (str[++i] != '\0')
	{
		if (c && ' ' <= str[i] && str[i] <= '~')
		{
			n++;
			c = 0;
		}
		else if (str[i] == '\n')
			c = 1;
	}
	return (n);
}

void	ft_cpy_line_val(char *dest, char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start + i < end)
	{
		while (src[start + i - 1] == ' ' && src[start + i] == ' ')
			start++;
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_free_dict(struct s_entry *dict, int n)
{
	int	i;

	i = 0;
	while (i < n || (n == -1 && dict[i].v))
		free(dict[i++].v);
	free(dict);
	return (1);
}
