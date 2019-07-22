
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/22 13:36:41 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_flags_ls(int i, char **argv)
{
	struct t_flags	flags;
	int parse;

	parse = 0;
	while (argv[i][parse])
	{
		if (argv[i][parse] < 65 || argv[i][parse] > 122)
			return (ft_error_ls(99));
		if (argv[i][parse] == 'l')
			flags.format = 1;
		else if (argv[i][parse] == 'R')
			recursive = true;
		else if (argv[i][parse] == 'a')
			ignore_mode = -1;
		else if (argv[i][parse] == 'r')
			sort_reverse = true;
		else if (argv[i][parse] == 't')
		{
			sort_type = sort_time;
			sort_type_specified = true;
		}
		else if (argv[i][parse] == 'u')
			time_type = time_atime;
		else if (argv[i][parse] == 'f')
		{
			ignore_mode = IGNORE_MINIMAL;
			sort_type = 0;
			sort_type_specified = true;
			if (format)
			{ 
				format = (isatty (STDOUT_FILENO) ? many_per_line : one_per_line);
				print_block_size = false;	/* disable -s */
				print_with_color = false;	/* disable --color */
				print_hyperlink = false;	/* disable --hyperlink */
			}
		}
		else if (argv[i][parse] == 'g')
		{
			format = 1;
			print_owner = false;
		}
		else if (argv[i][parse] == 'd')
			immediate_dirs = true;
		else
			parse++;
	}
	/* return (ft_strdup(flags)); */
	return (0);
}
