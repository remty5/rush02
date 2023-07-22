/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:24:44 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/22 13:38:02 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DICT_PATH "dicts/numbers.dict"
# define READ_SIZE 2048

// ft_read_utils
int					ft_read_file(char **str, int fd);

// ft_parse_utils
int					ft_is_valid_nbr(char *str);

// ft_utils
void				*ft_realloc(char *buf, int size);
char				*ft_strdup(char *src);
unsigned long long	ft_atoi(char *str);

#endif
