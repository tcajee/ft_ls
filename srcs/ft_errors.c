/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:36:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/06 12:14:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_dirs(char *path)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}

int	ft_error_prints(char *path)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}

int	ft_error_flags(char *flag)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(*flag, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage: ./ft_ls [-lRartGufgd1] [file ...]", 2);
	return (0);
}

int	ft_errors(int code, char *error)
{
	FT_(code == E_FLAGS, ft_error_flag(error));
	_FT(code == E_DIRS, ft_error_dir(error));
	_FT(code == E_PRINTS, ft_error_print(error));
	_FT(code == E_FILES, ft_error_file(error));
	return (code);
}


