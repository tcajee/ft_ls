/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:36:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/30 17:36:34 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_dir(char *path)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}

int	ft_error_print(int *flags, char *path)
{
	if (*flags & F_R)
	{
		ft_putstr_fd(path, 2);
		ft_putendl_fd(":", 2);
	}
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(ft_strrchr(path, '/') + 1, 2);
	ft_putstr_fd(": ", 2);
	/* ft_putstr_fd(path, 2); */
	perror("");
	/* ft_putendl_fd(": permision denied", 2); */
	return (0);
}

int	ft_error_flag(char *flag)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(*flag, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage: ./ft_ls [-lRartGufgd1] [file ...]", 2);
	return (0);
}

int	ft_error_file(char *path)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}

int	ft_errors(int *flags, int code, char *error)
{
	if (code == E_FLAGS)
		return (ft_error_flag(error));
	else if (code == E_DIRS)
		return (ft_error_dir(error));
	else if (code == E_PRINTS)
		return (ft_error_print(flags, error));
	else if (code == E_FILES)
		return (ft_error_file(error));
	return (0);
}


