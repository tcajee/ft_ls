/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:28:16 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:28:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_open_dirs(char *path)
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
