/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_null_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:05:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/13 10:15:54 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_null_info(t_info *t_info)
{
	t_info->name = NULL;
	t_info->hlinks = 0;
	t_info->owner = NULL;
	t_info->group = NULL;
	t_info->bytes = 0;
	t_info->mod_time = NULL;
	t_info->final = NULL;
}
