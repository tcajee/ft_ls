/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/02 14:22:37 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	i = 0;
	flags = 0;
	FT(!flags, flags |= F_1);
	FT_(argc == 1, ft_ls(".", &flags));
	_FT((i = ft_flags(argv, &flags)) == E_FLAGS, errno);
	_FT((i = ft_dirs(argv + i, &flags)) == E_DIRS, errno);
	return (errno);
}
