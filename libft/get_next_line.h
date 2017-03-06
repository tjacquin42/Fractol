/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:24:29 by ghubert           #+#    #+#             */
/*   Updated: 2017/01/23 13:54:51 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define ERROR			-1
# define END_OF_LINE	1
# define END_OF_FILE	0

# define BUFF_SIZE		5

typedef struct		s_file
{
	int				fd;
	int				eof;
	char			*data;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
