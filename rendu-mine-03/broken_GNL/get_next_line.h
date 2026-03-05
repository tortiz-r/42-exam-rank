#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


char    *get_next_line(int fd);

char    *read_until_newline(int fd, char *saved);
char    *join_and_free(char *saved, char *buffer);
char    *extract_line(char *buffer);
char    *save_remainder(char *buffer);

int     ft_strlen(char *s);
int     ft_strchr(const char *s, char c);
char    *ft_strjoin(char *s1, char *s2);

#endif