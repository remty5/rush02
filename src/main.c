/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:15:23 by aallou-v          #+#    #+#             */
/*   Updated: 2023/07/22 13:40:49 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "rush_02.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*nbr_str;
	char	*path;

	if (argc <= 3)
	{
		nbr_str = argv[argc - 1];
		if (argc == 1)
			ft_read_file(&nbr_str, 0);
		path = DICT_PATH;
		if (argc == 3)
			path = argv[1];
		printf("%s_%d_%s\n", nbr_str, ft_is_valid_nbr(nbr_str), path);
	}
	else
		return (ft_error());
	if (argc == 1)
		free(nbr_str);
	return (0);
}
