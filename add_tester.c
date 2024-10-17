/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:54:54 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 13:19:51 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	test_substr(char *str)
{
	char	*result;

	printf("--substr--\n");
	result = ft_substr(str, 0, 500);
	printf("%s\n", result);
	free(result);
}

void	test_strjoin(char *str, char *str2)
{
	char	*result;

	printf("--strjoin--\n");
	result = ft_strjoin(str, str2);
	printf("%s\n", result);
	free(result);
}

void	test_strtrim(char *str, char *str2)
{
	char	*result;

	printf("--strtrim--\n");
	result = ft_strtrim(str, str2);
	printf("%s\n", result);
	free(result);
}

void	test_split(char *str, char c)
{
	char	**result;
	int		i;

	printf("--split--\n");
	result = ft_split(str, c);
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i++]);
	}
	free(result);
}

void	test_itoa(int n)
{
	printf("--itoa--\n");
	printf("%s\n", ft_itoa(n));
}

char	test_mapi(unsigned int index, char c)
{
	return (c + index);
}

void	test_strmapi(char *str)
{
	char	*res;

	printf("--strmapi--\n");
	res = ft_strmapi(str, *test_mapi);
	printf("%s\n", res);
	free(res);
}

void	test_iteri(unsigned int index, char *s)
{
	*s = *s + index;
}

void	test_striteri(char *str)
{
	printf("--striteri--\n");
	ft_striteri(str, *test_iteri);
	printf("%s\n", str);
}

void	test_putstr_fd(char *str)
{
	write(1, "--putstr_fd--\n", 14);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
}

void	test_putendl_fd(char *str)
{
	write(1, "--putendl_fd--\n", 15);
	ft_putendl_fd(str, 1);
}

void	test_putnbr_fd(int n)
{
	write(1, "--putnbr_fd--\n", 14);
	ft_putnbr_fd(n, 1);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*str2;

	(void)argc;
	/* test with 1 string 
	str = argv[1];
	test_substr(str);
	test_strmapi(str);
	test_striteri(str);*/

	/*test with 2 strings*/
	str = argv[1];
	str2 = argv[2];
	test_strjoin(str, str2);
	test_strtrim(str, str2);
	test_split(str, str2[0]);

	/*test with 1 int
	test_itoa(ft_atoi(argv[1]));*/

	/*test whith write
	test_putstr_fd(argv[1]);
	test_putendl_fd(argv[1]);
	test_putnbr_fd(atoi(argv[1]));*/
}
