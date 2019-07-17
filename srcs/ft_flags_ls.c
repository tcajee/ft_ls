
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
	struct t_flags	flags;
	int parse;

	parse = 0;
	while (argv[i][parse])
	{
		if (argv[i][parse] < 65 || argv[i][parse] > 122)
			return (ft_error_ls(99));
		if (argv[i][parse] == 'l')
		{
			flags.format = 1;
		}
		else if (argv[i][parse] == 'R')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'a')
			ignore_mode = -1;
		else if (argv[i][parse] == 'r')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 't')
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'u')
			flags[j++] = argv[i][parse++];
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
			flags[j++] = argv[i][parse++];
		else if (argv[i][parse] == 'd')
			immediate_dirs = true;
		else
			parse++;
	}
	case 'l':
	case 'r':
	sort_reverse = true;
	case 't':
	sort_type = sort_time;
	sort_type_specified = true;
	case 'u':
	time_type = time_atime;
	case 'R':
	recursive = true;
	
	/* return (ft_strdup(flags)); */
	return (0);
}
