/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:04:27 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 14:31:11 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		printf("NO ARGS\n");
	else if (argc > 1)
		return (ft_ls(argc, argv));
	return (0);
}
