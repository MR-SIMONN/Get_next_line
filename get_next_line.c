#include "get_next_line.h"

int no_newline(char *s)
{
    int i;

    i = 0;
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
    else
        return (NULL);
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
        return (free(src), NULL);
    while (src[i] && src[i] != '\n')
        i++;
    if (src[i] == '\n')
        i++;
    len = (ft_strlen(src) - i);
    str = malloc (len + 1);
    if (!str)
        return (NULL);
    while (len)
    {
        str[j++] = src[i++];
        len--;
    }
    str[j] = '\0';
    return (free(src), str);
}

char *get_next_line(int fd)
{
    char    *buffer;
    static char    *s;
    char *line;
    int readed;

    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);
    readed = 1;
    if (!s)
        s = "\0";
    buffer = malloc (BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (no_newline(s) && readed)
    {
        readed = read(fd, buffer, BUFFER_SIZE);
        if (readed < 0)
            return (free(buffer), NULL);
        buffer[readed] = '\0';
        s = ft_strjoin(s, buffer);
    }
    line = clean_my_line(s);
    s = update_it(s);
    return (free(buffer), line);
}

