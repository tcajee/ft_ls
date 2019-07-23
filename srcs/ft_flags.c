/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/22 16:27:48 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_parse(int argc, char **argv)
{
	int i;
	int j;
	int len;
	int parse;

	i = 1;
	while (i < argc)
	{
		parse = 0;
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
		}
		/* flags[parse] = '\0'; */
		/* printf("ls %s\n", flags); */
		i++;
	}
	return (0);
}

int	ft_set(char *arg, t_flags *flags)
{
	return (0);
}

int	ft_flags(char **argv, t_flags *flags)
{
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
