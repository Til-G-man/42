#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
int ft_isalpha(int c);
int ft_isdigit(int c);
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
int	ft_isalnum(char c);
int	ft_isascii(char c);
int	ft_isprint(char c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
