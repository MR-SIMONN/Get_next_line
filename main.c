#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("a", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *s;

    s = get_next_line(fd);
    printf("%s",s);
    free(s);


    s = get_next_line(fd);
    printf("%s",s);
    free(s);


    s = get_next_line(fd);
    printf("%s",s);
    free(s);

    s = get_next_line(fd);
    printf("%s",s);
    free(s);

    s = get_next_line(fd);
    printf("%s",s);
    free(s);

    close(fd);
    return (0);
}