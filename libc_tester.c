/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:27:54 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 20:28:06 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

void	test_isalpha(char c)
{
	printf("--isalpha--\n");
	printf("Real: %d\n", isalpha(c));
	printf("Yours: %d\n", ft_isalpha(c));
}

void	test_isdigit(char c)
{
	printf("--isdigit--\n");
	printf("Real: %d\n", isdigit(c));
	printf("Yours: %d\n", ft_isdigit(c));
}

void	test_isalnum(char c)
{
	printf("--isalnum--\n");
	printf("Real: %d\n", isalnum(c));
	printf("Yours: %d\n", ft_isalnum(c));
}

void	test_isascii(char c)
{
	printf("--isacii--\n");
	printf("Real: %d \n", isascii(c));
	printf("Yours: %d\n", ft_isascii(c));
}

void	test_isprint(char c)
{
	printf("--isprint--\n");
	printf("Real: %d\n", isprint(c));
	printf("Yours: %d\n", ft_isprint(c));
}

void	test_strlen(char *s)
{
	printf("--strlen--\n");
	printf("Real: %lu\n", strlen(s));
	printf("Yours: %lu\n", ft_strlen(s));
}

void	test_memset(void)
{
	int		value;
	size_t	size;
	void	*buffer;
	void	*buffer2;

	value = 'a';
	size = 10;
	buffer = (char *)malloc(sizeof(char) * size + 1);
	buffer2 = (char *)malloc(sizeof(char) * size + 1);
	printf("--memset--\n");
	printf("Real: %s\n", (char *)memset(buffer, value, size));
	printf("Yours: %s\n", (char *)ft_memset(buffer2, value, size));
	free(buffer);
	free(buffer2);
}

void	test_bzero(void)
{
	size_t	size;
	size_t	i;
	int		test;
	void	*buffer;
	void	*buffer2;
	char	b1;
	char	b2;

	size = 10;
	test = 1;
	buffer = (char *)malloc(sizeof(char) * size + 1);
	buffer2 = (char *)malloc(sizeof(char) * size + 1);
	printf("--bzero--\n");
	bzero(buffer, size);
	ft_bzero(buffer2, size);
	i = 0;
	while (i <= size)
	{
		b1 = ((char *)buffer)[i];
		b2 = ((char *)buffer2)[i];
		if (b1 != b2)
			test = 0;
		i++;
	}
	if (!test)
		printf("Not ");
	printf("Same results !\n");
	free(buffer);
	free(buffer2);
}

void	test_memcpy(void *src)
{
	size_t	size;
	void	*buffer;
	void	*buffer2;

	size = 10;
	buffer = (char *)malloc(sizeof(char) * size + 1);
	buffer2 = (char *)malloc(sizeof(char) * size + 1);
	printf("--memcpy--\n");
	printf("Real: %s\n", (char *)memcpy(buffer, src, size));
	printf("Yours: %s\n", (char *)ft_memcpy(buffer2, src, size));
	free(buffer);
	free(buffer2);
}

void	test_memmove(void *src)
{
	size_t	size;
	void	*buffer;
	void	*buffer2;

	size = 10;
	buffer = (char *)malloc(sizeof(char) * size + 1);
	buffer2 = (char *)malloc(sizeof(char) * size + 1);
	printf("--memmove--\n");
	printf("Real: %s\n", (char *)memmove(buffer, src, size));
	printf("Yours: %s\n", (char *)ft_memmove(buffer2, src, size));
	free(buffer);
	free(buffer2);
}

void	test_strlcpy(char *src)
{
	size_t	size;
	char	*buffer;
	char	*buffer2;

	size = 10;
	buffer = (char *)malloc(sizeof(char) * size + 1);
	buffer2 = (char *)malloc(sizeof(char) * size + 1);
	printf("--strlcpy--\n");
	printf("Real: %zu - %s\n", strlcpy(buffer, src, size), buffer);
	printf("Yours: %zu - %s\n", ft_strlcpy(buffer2, src, size), buffer2);
	free(buffer);
	free(buffer2);
}

void	test_strlcat(char *str, char *str2)
{
	size_t	size;
	char	*str_cpy;

	size = 10;
	str_cpy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	strlcpy(str_cpy, str, ft_strlen(str));
	printf("--strlcat--\n");
	printf("Real: %zu - %s\n", strlcat(str, str2, size), str);
	printf("Yours: %zu - %s\n", ft_strlcat(str_cpy, str2, size), str_cpy);
	free(str_cpy);
}

void	test_toupper(char c)
{
	printf("--toupper--\n");
	printf("Real: %c\n", (char)toupper(c));
	printf("Yours: %c\n", (char)ft_toupper(c));
}

void	test_tolower(char c)
{
	printf("--tolower--\n");
	printf("Real: %c\n", (char)tolower(c));
	printf("Yours: %c\n", (char)ft_tolower(c));
}

void	test_strchr(char *str, char c)
{
	printf("--strchr--\n");
	printf("Real: %s\n", strchr(str, c));
	printf("Yours: %s\n", ft_strchr(str, c));
}

void	test_strrchr(char *str, char c)
{
	printf("--strrchr--\n");
	printf("Real: %s\n", strrchr(str, c));
	printf("Yours: %s\n", ft_strrchr(str, c));
}

void	test_strncmp(char *str, char *str2)
{
	int	n;

	n = 5;
	printf("--strncmp--\n");
	printf("Real: %d\n", strncmp(str, str2, n));
	printf("Yours: %d\n", ft_strncmp(str, str2, n));
}

void	test_memchr(char *str, char c)
{
	int	n;

	n = 5;
	printf("--memchr--\n");
	printf("Real: %s\n", (char *)memchr(str, c, n));
	printf("Yours: %s\n", (char *)ft_memchr(str, c, n));
}

void	test_memcmp(char *str, char *str2)
{
	int	n;

	n = 5;
	printf("--memcmp--\n");
	printf("Real: %d\n", memcmp(str, str2, n));
	printf("Yours: %d\n", ft_memcmp(str, str2, n));
}

void	test_strnstr(char *str, char *str2)
{
	int	n;

	n = 4;
	printf("--strnstr--\n");
	printf("Real: %s\n", strnstr(str, str2, n));
	printf("Yours: %s\n", ft_strnstr(str, str2, n));
}

void	test_atoi(char *str)
{
	printf("--atoi--\n");
	printf("Real: %d\n", atoi(str));
	printf("Yours: %d\n", ft_atoi(str));
}

void	test_calloc(void)
{
	void	*test;

	printf("--calloc--\n");
	test = calloc(5, 5);
	if (!test)
		return ;
	printf("Real: %s\n", (char *)test);
	free(test);
	test = ft_calloc(5, 5);
	if (!test)
		return ;
	printf("Yours: %s\n", (char *)test);
	free(test);
}

void	test_strdup(char *str)
{
	char	*test;

	printf("--strdup--\n");
	test = strdup(str);
	if (!test)
		return ;
	printf("Real: %s\n", test);
	free(test);
	test = ft_strdup(str);
	if (!test)
		return ;
	printf("Yours: %s\n", test);
	free(test);
}

int	main(int argc, char **argv)
{
	(void)argc;
	//(void)argv;
	/* with a char */
	char	c;

	c = argv[1][0];
	test_isalpha(c);
	test_isdigit(c);
	test_isalnum(c);
	test_isascii(c);
	test_isprint(c);
	test_toupper(c);
	test_tolower(c);
	
	/*with a string

	char	*str;
	str = argv[1];
	test_strlen(str);
	test_memcpy(str);
	test_memmove(str);
	test_strlcpy(str);
	test_atoi(str);
	test_strdup(str);*/

	/* test with nothing
	test_memset();
	test_bzero();
	test_calloc();*/

	/*with a string and a char

	char	*str;
	char	n;
	str = argv[1];
	n = argv[2][0];
	test_strchr(str, n);
	test_strrchr(str, n);
	test_memchr(str, n);*/

	/*test with 2 strings
	char	*str;
	char	*str2;
	str = argv[1];
	str2 = argv[2];
	test_strlcat(str, str2);
	test_strncmp(str, str2);
	test_memcmp(str, str2); // complie with -lbsd
	test_strnstr(str, str2);*/
}
