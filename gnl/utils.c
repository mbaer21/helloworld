/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaer <mbaer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:24:31 by mbaer             #+#    #+#             */
/*   Updated: 2020/12/12 18:24:31 by mbaer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc
#include "get_next_line.h"

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
