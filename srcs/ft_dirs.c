/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:12:37 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_dirs(char *argv)
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
