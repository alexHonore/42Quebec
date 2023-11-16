/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:14:01 by anshimiy          #+#    #+#             */
/*   Updated: 2023/11/14 10:11:12 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_tmp_head(t_node **list)
{
	*list = (t_node *)malloc(sizeof(t_node));
	(*list)->content = "delete";
	(*list)->type = -1;
	(*list)->prev = 0;
	(*list)->next = 0;
	(*list)->i = -1;
}

void	ft_delete_head(t_node **list)
{
	t_node	*tmp;

	if (!*list)
		return ;
	tmp = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = 0;
	free(tmp);
}

void	ft_lst_free(t_node *list)
{
	t_node	*tmp;

	if (list)
	{
		while (list)
		{
			tmp = list->next;
			free(list->content);
			free(list);
			list = tmp;
		}
	}
}

void	ft_lst_add_back(t_node **list, char *content)
{
	t_node	*new_node;
	t_node	*head;

	new_node = (t_node *)malloc(sizeof(t_node));
	head = *list;
	new_node->content = content;
	new_node->next = NULL;
	if (*list == NULL)
	{
		new_node->prev = NULL;
		*list = new_node;
		new_node->i = 0;
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = new_node;
	new_node->prev = head;
	new_node->i = new_node->prev->i + 1;
	new_node->type = -1;
}

t_node	*ft_get_first_node(t_node *list)
{
	while (list)
	{
		if (!list->prev)
			return (list);
		list = list->next;
	}
	return (0);
}
