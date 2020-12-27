/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaer <mbaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:56:00 by mbaer             #+#    #+#             */
/*   Updated: 2020/12/11 11:56:00 by mbaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //open
#include <stdio.h> //printf
#include <unistd.h> //read
#include <stdlib.h> //malloc
#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		len;

	len = ft_strlen(s1);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (0);
	dup[len] = 0;
	while (len >= 0)
	{
		dup[len] = s1[len];
		len--;
	}
	return (dup);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return (s);
	return (NULL);
}

size_t	ft_strlen(const char *buf)
{
	int l;

	l = 0;
	while (buf[l] != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*sub;
	unsigned long	i;
	unsigned long	k;
	unsigned int	sumlen;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sumlen = ft_strlen(s2) + ft_strlen(s1);
	if (!(sub = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		sub[i] = s1[i];
		i++;
	}
	while (i < sumlen && k < ft_strlen(s2))
	{
		sub[i] = s2[k];
		i++;
		k++;
	}
	sub[i] = '\0';
	return (sub);
}

int get_next_line(int fd, char **line)
{
	//int		flag;
	int			readen_bytes;
	char 		*p_n;
	size_t		BUFFER_SIZE = 7;
	char 		buf[BUFFER_SIZE + 1];
	static char	*remain;

	//flag = 1;
	if (remain)
		*line = ft_strdup(remain);
	while ((readen_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[readen_bytes] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			remain = ft_strdup(p_n);
			//flag = 0;
		}
		*line = ft_strjoin(*line, buf); 
	}
	return(0);
}

int main(void)
{
	char	*line;
	int 	fd;

	//line = "hello";
	fd = open("txt.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

	/*get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line);
	printf("%s\n", line);*/
}