/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:20:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 14:32:39 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_parse_ls(int argc, char **argv)
{
	int i;
	int j;
	int len;
	int parse;
	char flags[2];

	i = 1;
	parse = 0;
	while (i < argc)
	{
		while (argv[i][parse] == '-' && (len = ft_strlen(argv[i])) > 1)
		{
			j = 0;
			flags[j++] = argv[i][parse++];
			if (argv[i][parse] == '-')
				flags[j++] = argv[i][parse++];
			if (len >= 2 && parse == 2)
				return (ft_error_ls(99));
			else if (len > 2 && parse < 2)
				ft_flags_ls(i, argv);
			parse = 0;
		}
		i++;
	}
	return (0);
}
