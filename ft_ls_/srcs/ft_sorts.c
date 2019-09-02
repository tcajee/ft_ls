/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/02 12:43:16 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_last_access_sort(t_info **head, t_info *newnode)
{	
	t_info	dummy;
	t_info	*current;
	
	current = &dummy;
	dummy.next = *head;
	while (current->next != NULL && (ft_strcmp(current->next->name, newnode->name) < 0))
	{
		current = current->next;
	}
	newnode->next = current->next;
	current->next = newnode;
	*head = dummy.next;
	//while (current->next != NULL &&
	//		current->next->s_stat.st_atimespec.tv_nsec < newnode->s_stat.st_atimespec.tv_nsec)
}

void	ft_mod_time_sort(t_info **head, t_info *newnode)
{
	t_info dummy;
	t_info *current;

	current = &dummy;
	dummy.next = *head;
//	while (current->next != NULL &&
//			&current->next->s_stat.st_mtimespec > &newnode->s_stat.st_mtimespec)
	while (current->next != NULL && (ft_strcmp(current->next->name, newnode->name) < 0))
		current = current->next;
	newnode->next = current->next;
	current->next = newnode;
	*head = dummy.next;
}

void	ft_lex_sort(t_info **head, t_info *newnode)
{
	t_info dummy;
	t_info *current;

	current = &dummy;
	dummy.next = *head;
	while (current->next != NULL && (ft_strcmp(current->next->name, newnode->name) < 0))
		current = current->next;
	newnode->next = current->next;
	current->next = newnode;
	*head = dummy.next;
}

void	ft_sort(int *flags, t_info **head)
 {
 	 t_info *result;
 	 t_info *current;
 	 t_info *next;

 	 result = NULL;
 	 current = *head;
 	 (void)flags;
 	 while (current != NULL)
	 {
	 	 next = current->next;
	 	 if (*flags & F_t)
	 	 	 ft_mod_time_sort(&result, current);
	 	 if (*flags & F_u)
		 	 ft_last_access_sort(&result, current);
		 else
		 	ft_lex_sort(&result, current);
	 	 current = next;
	 }
	 *head = result;
 }
