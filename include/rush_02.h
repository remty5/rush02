/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:24:44 by rvandepu          #+#    #+#             */
/*   Updated: 2023/07/22 19:07:37 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DICT_PATH "dicts/numbers.dict"
# define READ_SIZE 1024

typedef struct s_entry {
	unsigned long long	n;
	char				*v;
}	t_entry;

// ft_parser
int					ft_parse_dict(struct s_entry **dict, char *dict_str);

// ft_read_utils
int					ft_read_file(char **str, int fd);

// ft_parse_utils
int					ft_is_valid_nbr(char *str);
int					ft_count_lines(char *str);
void				ft_cpy_line_val(char *dest, char *src, int start, int end);
int					ft_free_dict(struct s_entry *dict, int n);

// ft_utils
void				*ft_realloc(char *buf, int size);
char				*ft_strdup(char *src);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
unsigned long long	ft_atoi(char *str);

// ft_algo
void				ft_show(t_entry *dict, char *values);

#endif
