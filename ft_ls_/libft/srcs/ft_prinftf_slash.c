/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:07:24 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/29 14:24:40 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"

void	ft_slash(char id)
{
	if (id == 'n')
		ft_putchar('\n');
	else if (id == 't')
		ft_putchar('\t');
	else if (id == 'b')
		ft_putchar('\b');
	else if (id == 'a')
		ft_putchar('\a');
	else if (id == 'v')
		ft_putchar('\v');
	else if (id == 'f')
		ft_putchar('\f');
	else if (id == 'r')
		ft_putchar('\r');
}
