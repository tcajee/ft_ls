
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 14:28:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_flags_ls(int i, char **argv)
{
	int j;
	int parse;
	char flags[11];

	parse = 0;
	j = 0;
	while (argv[i][parse])
	{
		if (argv[i][parse] < 65 || argv[i][parse] > 122)
			return (ft_error_ls(99));
		if (argv[i][parse] == 'l')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'R')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'a')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'r')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 't')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'u')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'f')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'g')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'd')
			flags[j++] = argv[i][parse++];
		else
			parse++;
	}
	flags[parse] = '\0';
	printf("ls %s\n", flags);
	return (0);
}
