/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:15:23 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/22 23:25:46 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "rush_02.h"

void	disp_dict(struct s_entry *dict)
{
	int	i;

	i = -1;
	while (dict[++i].v)
		printf("i: %d\n\tn: %llu\n\tv: '%s'\n", i, dict[i].n, dict[i].v);
}

int	rush(char *dict_path, char *nbr_str)
{
	struct s_entry	*dict;
	int				fd;
	char			*dict_str;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!ft_read_file(&dict_str, fd))
		return (0);
	close(fd);
	printf("%s contents:\n%s\n", dict_path, dict_str);
	printf("========\nnbr: %s\n", nbr_str);
	if (!ft_parse_dict(&dict, dict_str))
		return (0);
	disp_dict(dict);
	ft_free_dict(dict, -1);
	free(dict_str);
	return (1);
}

int	ft_main_error(char *nbr_str, int argc)
{
	if (argc == 1 && nbr_str)
		free(nbr_str);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*path;
	char	*nbr_str;

	if (argc <= 3)
	{
		path = DICT_PATH;
		if (argc == 3)
			path = argv[1];
		nbr_str = argv[argc - 1];
		if (argc == 1 && !ft_read_file(&nbr_str, 0))
			return (ft_main_error(nbr_str, argc));
		if (!ft_is_valid_nbr(nbr_str))
			return (ft_main_error(nbr_str, argc));
		if (!rush(path, nbr_str))
		{
			write(1, "Dict ", 5);
			return (ft_main_error(nbr_str, argc));
		}
		if (argc == 1)
			free(nbr_str);
		return (0);
	}
	else
		return (ft_main_error(*argv, -1));
}
