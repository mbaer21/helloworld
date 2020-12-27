/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaer <mbaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:40:41 by mbaer             #+#    #+#             */
/*   Updated: 2020/12/11 12:40:41 by mbaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read
#include <stdlib.h> //malloc

int	read_from_fd(int fd)
{
	char 	*buf;
	int 	rs;
	size_t	BUFFER_SIZE = 1;

	rs = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rs = read(fd, buf, BUFFER_SIZE);
	buf[rs] = '\0';
	return(0);
}

