# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 40
# endif
#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);

# endif