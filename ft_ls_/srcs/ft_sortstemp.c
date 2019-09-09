/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/09 17:24:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_sorts3(int *flags, t_dirs *dirs)
{
			dirs;
			list;
			listsize;
			next;
			nextsize;
			temp;
			tail;
			while (listsize > 0 || (nextsize > 0 && next))
			{
				if (listsize == 0)
				{
					temp = next;
					next = next->next;
					nextsize--;
				}
				else if (nextsize == 0 || !next)
				{
					temp = list;
					list = list->next;
					listsize--;
				}
				else if (ft_sort_comp(flags, list, next) <= 0)
				{
					temp = list;
					list = list->next;
					listsize--;
				}
				else
				{
					temp = next;
					next = next->next;
					nextsize--;
				}
				if (tail)
					tail->next = temp;
				else
					dirs->list = temp;
				temp->prev = tail;
				tail = temp;
			}
			





}
void	ft_sorts2(int *flags, t_dirs *dirs)
{
	int i;

		nmerges;
		list;
		listsize;
		next;
		nextsize;
		insize;
		while (list)
		{
			++nmerges;
			next = list;
			listsize = 0;
			i = 0;
			while (i < insize)
			{
				listsize++;
				next = next->next;
				if (!next)
					break;
				i++;
			}
			nextsize = insize;
			//--------------------------
			list = next;
		}


}


void	ft_sorts1(int *flags, t_dirs *dirs)
{

	t_info *list;
	t_info *temp;
	t_info *next;
	t_info *tail;
	int insize;
	int nmerges;
	int listsize;
	int nextsize;
	int i;
	insize = 1;
	list;
	dirs;
	tail;
	nmerges;

	while (insize)
	{
		list = dirs->list;
		dirs->list = NULL;
		tail = NULL;
		nmerges = 0;
		
		//--------------------------2
		
		if (tail)
		{
			tail->next = NULL;
			dirs->last = tail;
		}
		if (nmerges <= 1)
			break;
		insize *= 2;
	}
}


