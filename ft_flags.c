/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/28 16:17:35 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_flags(char **argv, t_flags *flags)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		FT_((argv[i][0] != '-'), i);
		FT_(!ft_strcmp(argv[i], "--"), i);
		FT_((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2],
			(*flags = ft_error_flags(argv[i][2])));
		FT(argv[i][0] == '-' && argv[i][1], ft_set_flags(argv[i], flags));
	}
	return (i);
}
