/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:33:44 by moel-hai          #+#    #+#             */
/*   Updated: 2024/12/16 03:34:33 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = malloc (sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*check_null(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (free((char *)s1), s1 = NULL, ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;
	int		len;

	if (!s1 || !s2)
		return (check_null(s1, s2));
	i = 0;
	j = 0;
	len = ft_strlen (s1) + ft_strlen (s2);
	tab = malloc (len + 1);
	if (!tab)
		return (free((char *)s1), s1 = NULL, NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';	
	return (free((char *)s1), s1 = NULL, tab);
}
