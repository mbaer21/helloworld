/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaer <mbaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:56:03 by mbaer             #+#    #+#             */
/*   Updated: 2020/12/11 11:56:03 by mbaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
	int 	rb;
	size_t	BUFFER_SIZE = 10;
	char 	buf[BUFFER_SIZE + 1];

	//int 	fd = open("text.txt", O_RDONLY);
	while ((rb = read(fd, buf, BUFFER_SIZE)) > 0) 
	{
		buf[rb] = '\0';
		*line = ft_strjoin(*line, buf);
	}
}

int main(void)
{
	char	*line;
	int 	fd;

	fd = open("txt.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}