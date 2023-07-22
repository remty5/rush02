/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:54:17 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/22 23:37:24 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_parse_line(struct s_entry *entry, char *line)
{
	int	i;
	int	s;

	i = 0;
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	while (i > 0 && line[i] == ' ')
		i++;
	if (i == 0 || line[i++] != ':')
		return (0);
	while (i > 0 && line[i] == ' ')
		i++;
	s = i;
	while (i > 0 && ' ' <= line[i] && line[i] <= '~')
		i++;
	if (i == 0 || line[i] != '\n')
		return (0);
	while (line[--i] == ' ')
		;
	entry->n = ft_atoi(line);
	entry->v = malloc(i - s + 2);
	if (entry->v == NULL)
		return (0);
	ft_cpy_line_val(entry->v, line, s, i + 1);
	return (1);
}

int	ft_parse_dict(struct s_entry **dict, char *dict_str)
{
	int	i;
	int	n;
	int	c;

	*dict = malloc(sizeof(struct s_entry) * (ft_count_lines(dict_str) + 1));
	if (*dict == NULL)
		return (0);
	i = -1;
	n = 0;
	c = 1;
	while (dict_str[++i])
	{
		if (c && ' ' <= dict_str[i] && dict_str[i] <= '~')
		{
			if (ft_parse_line(*dict + n, dict_str + i))
				n++;
			c = 0;
		}
		else if (dict_str[i] == '\n')
			c = 1;
	}
	(*dict)[n].v = NULL;
	if (n != ft_count_lines(dict_str))
		return (!ft_free_dict(*dict, n));
	return (1);
}
