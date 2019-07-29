/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/29 16:07:52 by tcajee           ###   ########.fr       */
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
			(ft_error_flags(argv[i][2])));
		FT(argv[i][0] == '-' && argv[i][1], ft_set_flags(argv[i], flags));
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	int i;

	i = 0;
	flags = 0;
	FT(!flags, ft_init_flags(&flags));
	FT_(argc == 1, ft_ls(".", flags));
	i = ft_flags(argv, &flags);
	while (argv[i] && ft_check_dirs(argv[i]))
	{
		printf("argv[%d]: %s\n", i ,argv[i]);
		ft_ls(argv[i], flags);
		i++;
	}
	return (0);
}
