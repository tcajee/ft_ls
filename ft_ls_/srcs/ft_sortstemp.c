/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/09 18:14:58 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

typedef struct	s_sort
{
	t_info		*list;
	t_info		*next;
	t_info		*tail;
	t_info		*temp;

	int			i_size;
	int			l_size;
	int			n_size;
	int			m_count;

}				t_sort;

void	ft_sort3(int *flags, t_dirs *dirs, t_sort *s)
{
	while (s->l_size > 0 || (s->n_size > 0 && s->next))
	{
		if (s->l_size == 0 && s->n_size--)
		{
			s->temp = s->next;
			s->next = s->next->next;
		}
		else if ((s->n_size == 0 || !s->next) && s->l_size--)
		{
			s->temp = s->list;
			s->list = s->list->next;
		}
		else if (ft_sort_comp(flags, s->list, s->next) <= 0 && s->l_size--)
		{
			s->temp = s->list;
			s->list = s->list->next;
		}
		else if (s->n_size-- && !!(s->temp = s->next))
			s->next = s->next->next;
		(s->tail) ? (s->tail->next = s->temp) : (dirs->list = s->temp);
		s->temp->prev = s->tail;
		s->tail = s->temp;
	}
}

void	ft_sort2(int *flags, t_dirs *dirs, t_sort *sort)
{
	int		i;

	while (sort->list)
	{
		i = 0;
		++sort->m_count;
		sort->next = sort->list;
		sort->l_size = 0;
		while (i < sort->i_size)
		{
			sort->l_size++;
			sort->next = sort->next->next;
			if (!sort->next)
				break;
			i++;
		}
		sort->n_size = sort->i_size;
		ft_sort3(flags, dirs, sort);
		sort->list = sort->next;
	}
}

void	ft_sorts(int *flags, t_dirs *dirs)
{
	t_sort	*sort;

	if (!(sort = (t_sort *)malloc(sizeof(t_sort))))
		return ;
	sort->i_size = 1;
	while (sort->i_size)
	{
		sort->list = dirs->list;
		dirs->list = NULL;
		sort->tail = NULL;
		sort->m_count = 0;
		ft_sort2(flags, dirs, sort);
		if (sort->tail)
		{
			sort->tail->next = NULL;
			dirs->last = sort->tail;
		}
		if (sort->m_count <= 1)
			break;
		sort->i_size *= 2;
	}
}


