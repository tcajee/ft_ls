/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/13 12:41:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls_print(char *ft, ...)
{
	va_list	v_list;
	int		i;

	i = -1;
	va_start (v_list, ft);
	while (ft[++i])
	{
		F_(ft[i] == '%', ft_putstr(va_arg(v_list, char *)));
		_F(ft[i] == 'n', ft_putendl(""));
		_F(ft[i] == 't', ft_putstr("	"));
		_F(ft[i] == '.', ft_putendl(""));
		_F(ft[i], ft_putchar(ft[i]));
	}
	va_end (v_list);
	return (1);
}

int	main(int argc, char **argv)
{
	t_flags		flags;
	int			i;

	i = 0;
	F_(!(flags = 0), B_1(flags, F_1));
	FT_((i = ft_flags(argv, &flags)) == E_FLAGS, errno);
	F_(argc - i > 1, flags |= F_M);

	ft_flag_print(&flags);
	ft_putchar('\n');

	return (ft_dirs(argv + i, &flags));

}
