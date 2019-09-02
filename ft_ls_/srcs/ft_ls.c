/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/02 10:29:06 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_ls_clean(t_dirs *dirs)
{
	t_info *list;

	free(dirs->root);
	list = dirs->list;
	while (list)
	{
		if (list->root)
			free(list->root);
		if (list->name)
			free(list->name);
		if (list->path)
			free(list->path);
		if (list->next)
			free(list->next);
		list = list->prev;
	}
	free(dirs);

	
	/* if (dirs->root) */
	/* 	free(dirs->root); */
	/* if (dirs->path) */
	/* 	free(dirs->path); */
	/* if (dirs->name) */
	/* 	free(dirs->name); */

	/* t_dirs	*new; */
	/* new = NULL; */
	/* new->name = ft_strdup(path); */
	/* new->list = ft_list_new(); */
	/* new->last = NULL; */
	/* new->total = 0; */
	/* new->size = 0; */
	/* new->s_form.grp_len = 0; */
	/* new->s_form.usr_len = 0; */
	/* new->s_form.size_len = 0; */
	/* new->s_form.link_len = 0; */

	/* t_info	*new; */
	/* new->root = NULL; */
	/* new->name = NULL; */
	/* new->path = NULL; */
	/* new->next = NULL; */
	/* new->prev = NULL; */

}

int		ft_ls_check(char *path)
{
	t_stat	s_stat;
	if (lstat(path, &s_stat) < 0)
		return (0);
	if ((s_stat.st_mode & S_IFMT) == S_IFREG)
		return (1);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
		return (2);
	return (0);
}

char	*ft_ls_path(char *path, char *d_name)
{
	int		i;
	int		len;
	char	*temp;
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
	return (temp);
}

int		ft_ls_rec(int *flags, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	char		*fpath;

/* ft_putendl("begin ls rec"); */
	if (!(dir = opendir(path)))
		return (0);
	while ((s_dir = readdir(dir)) != NULL)
	{
		if ((s_dir->d_name[0] == '.' && s_dir->d_name[1] == '\0') ||
		   ((s_dir->d_name[0] == '.' && s_dir->d_name[2] == '\0') &&
			s_dir->d_name[1] == '.'))
			continue;
		if (ft_ls_check(fpath = ft_ls_path(path, s_dir->d_name)) == 2)
			ft_dirs(flags, fpath);
		free(fpath);
	}
	closedir(dir);
/* ft_putendl("end ls rec"); */
	return (1);
}

int		main(int argc, char **argv)
{
	int			flags;
	int			i;
	int			j;


/* ft_putendl("begin ls"); */
	i = 0;
	i = ft_flags(&flags, argv);
	
	/* ft_putnbr(i); */
	/* ft_putendl(""); */
	/* ft_putnbr(argc); */
	/* ft_putendl(""); */
	

	if ((argc - i) > 1)
		flags |= F_M;

	if (!argv[i])
		return (ft_dirs(&flags, "."));

	j = i - 1;
	while (argv[++j])
		if (ft_ls_check(argv[j]) == 0)
			ft_errors(&flags, E_DIRS, argv[j]);
	j = i - 1;
	while (argv[++j])
		if (ft_ls_check(argv[j]) == 1)
			ft_dirs(&flags, argv[j]);
	j = i - 1;
	while (argv[++j])
		if (ft_ls_check(argv[j]) == 2)
			ft_dirs(&flags, argv[j]);
/* ft_putendl("end ls"); */
	/* sleep(20); */
	return (1);
}
