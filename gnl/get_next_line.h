/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaer <mbaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:55:56 by mbaer             #+#    #+#             */
/*   Updated: 2020/12/11 11:55:56 by mbaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *buf);
char			*ft_strjoin(char const *s1, char const *s2);

#endif