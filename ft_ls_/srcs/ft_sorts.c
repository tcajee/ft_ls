/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/02 13:42:44 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void sortedInsert(t_info **head_ref, t_info *newNode) 
{ 
    t_info *current; 
  
    // if list is empty 
    if (*head_ref == NULL) 
        *head_ref = newNode; 
  
    // if the node is to be inserted at the beginning 
    // of the doubly linked list 
    else if (ft_strcmp((*head_ref)->name ,newNode->name) >= 0) { 
        newNode->next = *head_ref; 
        newNode->next->prev = newNode; 
        *head_ref = newNode; 
    } 
  
    else { 
        current = *head_ref; 
  
        // locate the node after which the new node 
        // is to be inserted 
        while (current->next != NULL &&  
               ft_strcmp(current->next->name ,newNode->name) < 0)
            current = current->next; 
  
        /*Make the appropriate links */
  
        newNode->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            newNode->next->prev = newNode; 
  
        current->next = newNode; 
        newNode->prev = current;
    } 
} 
  
// function to sort a doubly linked list using insertion sort 
void insertionSort(t_dirs **head_ref) 
{ 
    // Initialize 'sorted' - a sorted doubly linked list 
    t_info *sorted = NULL; 
  
    // Traverse the given doubly linked list and 
    // insert every node to 'sorted' 
    t_info *current = (*head_ref)->list; 
    while (current != NULL) { 
  
        // Store next for next iteration 
        t_info *next = current->next; 
  
        // removing all the links so as to create 'current' 
        // as a new node for insertion 
        current->prev = current->next = NULL; 
  
        // insert current in 'sorted' doubly linked list 
        sortedInsert(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted doubly linked list 
    (*head_ref)->list = sorted;
    while (sorted != NULL)
	{
		if (sorted->next == NULL)
			(*head_ref)->last = sorted;
		sorted = sorted->next;
	}
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
	t_info *current;

	if (*head == NULL)
		*head = newnode;
	else if (ft_strcmp((*head)->name, newnode->name) > 0)
	{
		newnode->next = *head;
		newnode->next->prev = newnode;
		*head = newnode;
	}
	else
	{
		current = *head;
		while (current->next != NULL && ft_strcmp(current->next->name, newnode->name) < 0)
			current = current->next;
		newnode->next = current->next;
		if (current->next != NULL)
			newnode->next->prev = newnode;
		current->next = newnode;
		newnode->prev = current;
	}
/*	t_info dummy;
	t_info *current;

	current = &dummy;
	dummy.next = *head;
	while (current->next != NULL && (ft_strcmp(current->next->name, newnode->name) < 0))
		current = current->next;
	newnode->next = current->next;
	if (current->next != NULL)
		newnode->next->prev = newnode;
	current->next = newnode;
	newnode->prev = current;
	*head = dummy.next; */
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
		 else
		 	ft_lex_sort(&result, current);
	 	 current = next;
	 }
	 *head = result;
 }
