/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hai <moel-hai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:27:56 by moel-hai          #+#    #+#             */
/*   Updated: 2024/12/16 04:53:12 by moel-hai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int no_newline(char *s)
{
    int i;

    i = 0;
    if (s == NULL)
        return (1);
    while (s[i])
    {
        if (s[i] == '\n')
            return (0);
        i++;
    }
    return (1);
}

char*   clean_my_line(char *src)
{
    int i;
    int j;
    char *str;

    i = 0;
    j = 0;
    if (!src)
        return (NULL);
    while (src[i] && src[i] != '\n')
        i++;
    if (src[i] == '\n')
        i++;
    str = malloc (i + 1);
    if (!str)
        return (NULL);
    while (src[j] && src[j] != '\n')
    {
        str[j] = src[j];
        j++;
    }
    if (!no_newline(src))
        str[j++] = '\n';
    str[j] = '\0';
    return (str);
}

char*   update_it(char *src)
{
    int i;
    int j;
    char *str;
    int len;

    i = 0;
    j = 0;
    len = 0;
    if (!src)
        return (free(src), src = NULL, NULL);
    while (src[i] && src[i] != '\n')
        i++;
    if (src[i] == '\n')
        i++;
    len = (ft_strlen(src) - i);
    str = malloc (len + 1);
    if (!str)
        return (free(src), src = NULL, NULL);
    while (len)
    {
        str[j++] = src[i++];
        len--;
    }
    return (str[j] = '\0', free(src), src = NULL, str);
}

char *get_next_line(int fd)
{
    char        *buffer;
    char        *line;
    int         readed;
    static char *s[OPEN_MAX];

    if (fd < 0 || BUFFER_SIZE <= 0  || BUFFER_SIZE > INT_MAX)
        return (free (s[fd]),s[fd] = NULL, NULL);
    (1) && (readed = 1, buffer = malloc (sizeof(char) * BUFFER_SIZE + 1));
    if (!buffer)
        return (free (s[fd]), s[fd] = NULL, NULL);
    while (no_newline(s[fd]) && readed)
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        if (readed < 0)
            return (free(s[fd]),s[fd] = NULL ,free(buffer) ,NULL);  
        buffer[readed] = '\0';
        s[fd] = ft_strjoin(s[fd], buffer);
    }
    line = clean_my_line(s[fd]);
    if (!line)
        return (free(s[fd]), s[fd] = NULL, free(buffer), NULL);
    s[fd] = update_it(s[fd]);
    if (ft_strlen(line) == 0)
        return (free(s[fd]), s[fd] = NULL, free(buffer), free(line), NULL);
    return (free(buffer), line);
}

