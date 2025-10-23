/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:56:10 by eboulajd          #+#    #+#             */
/*   Updated: 2025/10/23 13:57:37 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
    t_list *next_node;

    if (!lst || !del)
        return;

    temp = *lst;
    while (temp)
    {
        next_node = temp->next;
        del(temp->content);
        free(temp);
        temp = next_node;
    }
    *lst = NULL;
}
