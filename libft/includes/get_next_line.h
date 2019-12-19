/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 23:01:50 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/10/15 22:55:31 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

typedef struct		s_slist
{
	char			*content;
	int				fd;
	struct s_slist	*next;
}					t_tlist;
int					get_next_line(const int fd, char **line);

#endif
