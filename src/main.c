/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:15:23 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/23 01:17:37 by rvandepu         ###   ########.fr       */
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
	{
		free(dict_str);
		return (0);
	}
	free(dict_str);
	disp_dict(dict);
	ft_free_dict(dict, -1);
	return (1);
}

int	ft_main_error(char *str, int should_free)
{
	if (should_free && str)
		free(str);
	write(2, "Error\n", 6);
	return (1);
}

void	fr_test(char *i)
{
	t_entry	tab[32];
	tab[0].n = 0;
	tab[0].v = "zero";

	tab[1].n = 1;
	tab[1].v = "one";

	tab[2].n = 2;
	tab[2].v = "two";

	tab[3].n = 3;
	tab[3].v = "three";

	tab[4].n = 4;
	tab[4].v = "four";

	tab[5].n = 5;
	tab[5].v = "five";

	tab[6].n = 6;
	tab[6].v = "six";

	tab[7].n = 7;
	tab[7].v = "seven";

	tab[8].n = 8;
	tab[8].v = "eight";

	tab[9].n = 9;
	tab[9].v = "nine";

	tab[10].n = 10;
	tab[10].v = "ten";

	tab[11].n = 11;
	tab[11].v = "eleven";

	tab[12].n = 12;
	tab[12].v = "twelve";

	tab[13].n = 13;
	tab[13].v = "thirteen";

	tab[14].n = 14;
	tab[14].v = "fourteen";

	tab[15].n = 15;
	tab[15].v = "fifteen";

	tab[16].n = 16;
	tab[16].v = "sixteen";

	tab[17].n = 17;
	tab[17].v = "seventeen";

	tab[18].n = 19;
	tab[18].v = "nineteen";

	tab[19].n = 20;
	tab[19].v = "twenty";

	tab[20].n = 30;
	tab[20].v = "thirty";

	tab[21].n = 40;
	tab[21].v = "forty";

	tab[22].n = 50;
	tab[22].v = "fifty";

	tab[23].n = 60;
	tab[23].v = "sixty";

	tab[24].n = 70;
	tab[24].v = "seventy";

	tab[25].n = 80;
	tab[25].v = "eighty";

	tab[26].n = 90;
	tab[26].v = "ninety";

	tab[27].n = 100;
	tab[27].v = "hundred";

	tab[28].n = 1000;
	tab[28].v = "thousand";

	tab[29].n = 1000000;
	tab[29].v = "million";

	tab[30].n = 1000000000;
	tab[30].v = "billion";
	
	tab[31].n = 18;
	tab[31].v = "eighteen";

	ft_show(tab, i);
}

int	main(int argc, char *argv[])
{
	char	*path;
	char	*nbr_str;

	fr_test(argv[1]);
	return (0);
	if (argc <= 3)
	{
		path = DICT_PATH;
		if (argc == 3)
			path = argv[1];
		nbr_str = argv[argc - 1];
		if (argc == 1 && !ft_read_file(&nbr_str, 0))
			return (ft_main_error(nbr_str, argc == 1));
		if (!ft_is_valid_nbr(nbr_str))
			return (ft_main_error(nbr_str, argc == 1));
		if (!rush(path, nbr_str))
		{
			write(1, "Dict ", 5);
			return (ft_main_error(nbr_str, argc == 1));
		}
		if (argc == 1)
			free(nbr_str);
		return (0);
	}
	else
		return (ft_main_error(*argv, 0));
}
