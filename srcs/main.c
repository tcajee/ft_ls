/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/30 16:13:32 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	i = 0;
	flags = 0;
	FT_(argc == 1, ft_ls(".", flags));
	_FT((i = ft_flags(argv, &flags)) == E_FLAGS, errno);
	while (argv[i] && ft_check_dirs(argv[i]))
		ft_ls(argv[i++], flags);
	return (0);
}
