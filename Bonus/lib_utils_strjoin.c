/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:31:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/21 18:51:44 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static int	ft_count_size(int size, char **strs, char *sep)
{
	int	dest_size;
	int	i;

	i = 0;
	dest_size = 1;
	while (i < size)
	{
		dest_size += ft_strlen(strs[i]);
		i++;
	}
	dest_size += ft_strlen(sep) * (size - 1);
	return (dest_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;

	if (size == 0)
	{
		s = malloc(sizeof(char) * 1);
		if (s == NULL)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (ft_count_size(size, strs, sep)));
	if (s == NULL)
		return (NULL);
	i = 0;
	s[i] = '\0';
	while (i < size)
	{
		s = ft_strcat(s, strs[i]);
		if (i < (size - 1))
			s = ft_strcat(s, sep);
		i++;
	}
	return (s);
}
