/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:58:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/24 16:11:40 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"


void	ft_ls_open(char *path)
{
	DIR				*dir;
	struct dirent	*d;

	dir = opendir(path);
	while ((d = readdir(dir)) != NULL)
	{
		/*if (ft_ls_isdir(d->d_name))
		{
			if (!(file = malloc(sizeof(t_files))))
				perror("Malloc error: ");
			file->dir = d->d_name;
			ft_putendl(file->dir);
		}*/
		if ((d->d_name) != NULL && d->d_name[0] != '.')
		{
			ft_putendl(d->d_name);
		}
	}
	closedir(dir);
}

int	ft_dirs(int argc, char **argv)
{
	int i;

	i = -1;
	while (argv[++i] && i < argc)
	{
		if (ft_isdir(argv[i]))
			ft_ls_open(argv[i]);
		else
		{
			ft_errors(99);
			perror("DIR ERROR");
			break ;
		}
	}
	return (i);
}
