/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/26 17:34:25 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void ft_files(int *flags, t_info dirs[], char *path)
{
	F_SET(*flags, F_0, F_REG);
	if (!(dirs[0].name = ft_strdup(path)))
		return ;
	lstat(dirs[0].name, &dirs[0].s_stat);
	dirs[0].dirc = 1;
	ft_prints(flags, dirs);
	F_SET(*flags, F_REG, F_0);
	free(dirs[0].name);
}

int	main(int argc, char **argv)
{
	int			flags;
	t_info		dirs[32768];
	int			i;
	int			j;

	i = 0;

	flags = 0;
	F_SET(flags, F_0, F_1);
	if ((i = ft_flags(&flags, argv)) < 0)
		return (-1);
	if ((argc - i) > 1)
		flags |= F_M;

	/* ft_flag_print(&flags); */
	/* ft_putendl(""); */
	/* ft_putendl(""); */

	/* printf("%s\n", argv[i]); */

	j = i - 1;
	if (!argv[i])
		return (ft_dirs(&flags, dirs, "."));
	while (argv[++j])
		if (ft_dir_check(argv[j]) == 0)
			ft_errors(E_DIRS, argv[j]);
	j = i - 1;
	while (argv[++j])
		if (ft_dir_check(argv[j]) == 1)
			ft_files(&flags, dirs, argv[j]);
	j = i - 1;
	while (argv[++j])
		if (ft_dir_check(argv[j]) == 2)
			ft_dirs(&flags, dirs, argv[j]);
	return (0);
}
