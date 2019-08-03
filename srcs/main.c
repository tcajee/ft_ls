/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/03 04:10:29 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	i = 1;
	FT(!(flags = 0), flags |= F_1);
	if (argc == 1)
		FT_(i , ft_ls(NULL, &flags));
	if (argc > 1)
		FT_((i = ft_flags(argv, &flags)) == E_FLAGS, errno);
	printf("i: %d\n", i);
	FT_(i , ft_ls(argv + i, &flags));
	return (errno);
}
