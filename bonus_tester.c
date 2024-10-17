/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguerbig <lguerbig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:31:16 by lguerbig          #+#    #+#             */
/*   Updated: 2024/10/10 20:08:49 by lguerbig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	test_lstnew(char *str)
{
	t_list	*list;

	list = ft_lstnew((void *)str);
	printf("--lstnew--\n");
	printf("%s\n", (char *)list->content);
	free(list);
}

void	free_list(t_list	*lst)
{
	t_list	*tmp;
	t_list	*tmpnext;

	tmp = lst;
	while (tmp)
	{
		tmpnext = tmp->next;
		free(tmp);
		tmp = tmpnext;
	}
}

void	test_lstadd_front(char *str)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew((void *)"Bonjour");
	new = ft_lstnew((void *)str);
	printf("--lstadd_front--\n");
	ft_lstadd_front(&list, new);
	printf("New start: %s\n", (char *)list->content);
	printf("Next node: %s\n", (char *)list->next->content);
	free_list(list);
}

void	test_lstsize(char *str)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew((void *)"Bonjour");
	new = ft_lstnew((void *)str);
	printf("--lstsize--\n");
	printf("With 1 node: %d\n", ft_lstsize(list));
	ft_lstadd_front(&list, new);
	printf("With 2 nodes: %d\n", ft_lstsize(list));
	free_list(list);
}

void	test_lstlast(char *str)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew((void *)"Bonjour");
	new = ft_lstnew((void *)str);
	printf("--lstlast--\n");
	ft_lstadd_front(&list, new);
	printf("%s\n", (char *)(ft_lstlast(list))->content);
	free_list(list);
}

void	test_lstadd_back(char *str)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew((void *)"Bonjour");
	new = ft_lstnew((void *)str);
	printf("--lstadd_back--\n");
	ft_lstadd_back(&list, new);
	printf("New start: %s\n", (char *)list->content);
	printf("Next node: %s\n", (char *)list->next->content);
	free_list(list);
}

void	ntd(void *content)
{
	(void)content;
}

void	test_lstclear()
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew((void *)"Bonjour");
	new = ft_lstnew((void *)"blablou");
	printf("--lstclear--\n");
	ft_lstadd_back(&list, new);
	ft_lstclear(&list, ntd);
	printf("%d\n", list == 0);
}

void	*addl(void *content)
{
	printf("act ");
	return (content);
}

void	test_lstmap()
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	t_list	*res;

	l1 = ft_lstnew((void *)"Bonjour");
	l2 = ft_lstnew((void *)"blablou");
	l3 = ft_lstnew((void *)"la famille");
	ft_lstadd_back(&l1, l2);
	ft_lstadd_back(&l1, l3);
	printf("--lstmap--\n");
	res = ft_lstmap(l1, addl, ntd);
	printf("\n");
	ft_lstclear(&l1, ntd);
	printf("Node 1: %s\n", (char *)res->content);
	printf("Node 2: %s\n", (char *)res->next->content);
	printf("Node 3: %s\n", (char *)res->next->next->content);
	ft_lstclear(&res, ntd);
}



int	main(int argc, char **argv)
{
	(void)argc;
	test_lstnew(argv[1]);
	test_lstadd_front(argv[1]);
	test_lstsize(argv[1]);
	test_lstlast(argv[1]);
	test_lstadd_back(argv[1]);
	test_lstclear();
	test_lstmap();
}
