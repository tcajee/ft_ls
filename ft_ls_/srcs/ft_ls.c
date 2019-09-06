/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/06 18:50:54 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_ls_file(int *flags, char **argv)
{
	t_dirs	*dirs;
	t_info	*list;

ft_putendl("			LS_FILE");
ft_putendl("-----------------------------------");
	F_SET(*flags, F_0, F_REG);
	dirs = ft_dir_new(*(argv + 1));
	list = dirs->list;
	while (*++argv)
	{
		if (ft_ls_check(*argv) == 1 && ++dirs->size)
		{
			if (!list)
				list = ft_dir_add(dirs->last);
			dirs->last = list;
			list->name = ft_strdup(*argv);
			lstat(list->name, &list->s_stat);
			ft_dir_form(flags, dirs);
			if (!(*flags & F_F))
				ft_sorts(flags, dirs);
			list = !(*flags & F_F) ? dirs->last->next : list->next;
		}
	}
	ft_prints(flags, dirs);
	ft_sort_clean(dirs);
	F_SET(*flags, F_REG, F_0);
ft_putendl("			LS_FILE END");
ft_putendl("-----------------------------------");
}

int		ft_ls_check(char *path)
{
	t_stat	s_stat;

ft_putendl("			LS_CHECK");
ft_putendl("-----------------------------------");
	if (lstat(path, &s_stat) < 0)
		return (0);
	if ((s_stat.st_mode & S_IFMT) == S_IFREG)
		return (1);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
		return (2);
ft_putendl("			LS_CHECK");
ft_putendl("-----------------------------------");
	return (0);
}

char	*ft_ls_path(char *path, char *d_name)
{
	int		i;
	int		len;
	char	*temp;

ft_putendl("			LS_PATH");
ft_putendl("-----------------------------------");
	i = 0;
	len = ft_strlen(path) + ft_strlen(d_name);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (*path)
		temp[i++] = *path++;
	if (temp[i - 1] == '/')
		temp[i] = '/';
	else
		temp[i++] = '/';
	while (*d_name)
		temp[i++] = *d_name++;
	temp[i] = '\0';
ft_putendl("			LS_PATH END");
ft_putendl("-----------------------------------");
	return (temp);
}

int		main(int argc, char **argv)
{
	int		flags;
	int		i;
	int		j;

ft_putendl("-----------------------------------");
ft_putendl("			INIT");
	i = -1;
ft_putendl("PARAMS");
while (argv[++i])
{
ft_putstr("[");
ft_putnbr(i);
ft_putstr("]");
ft_putstr("	");
ft_putendl(argv[i]);
}
ft_putendl("-----------------------------------");

	i = 0;
	i = ft_flags(&flags, argv);
	if ((argc - i) > 1)
		flags |= F_M;
	if (!argv[i])
	{
		ft_dirs(&flags, ".");
ft_putendl("-----------------------------------");
ft_putendl("			END");
ft_putendl("-----------------------------------");
		return (1);
	}
	j = i - 1;
	ft_errors(&flags, argv + j);
	ft_ls_file(&flags, argv + j);
	while (argv[++j])
	{
		if (ft_ls_check(argv[j]) == 2)
			ft_dirs(&flags, argv[j]);
	}
ft_putendl("-----------------------------------");
ft_putendl("			END");
ft_putendl("-----------------------------------");
	return (1);
}
