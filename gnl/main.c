/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaer <mbaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:38:10 by mbaer             #+#    #+#             */
/*   Updated: 2020/12/11 12:38:10 by mbaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //open
#include <stdio.h> //printf
#include "get_next_line.h"

int main(void)
{
	int 	fd = open("text.txt", O_RDONLY);
	char 	*line;
	int 	i;

	while (i = get_next_line(fd, &line))
	{
		printf("i = %d %s\n", i, line);
		free (line);
	}
	printf("i = %d %s\n", i, line);
		free(line);
	return(0);
}