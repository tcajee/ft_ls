/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 14:32:59 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls(int argc, char **argv)
{

	/* time_type = time_mtime; */
	/* sort_type = sort_name; */
	/* sort_reverse = false; */
	/* /1* numeric_ids = false; *1/ */
	/* print_block_size = false; */
	/* /1* indicator_style = none; *1/ */
	/* print_inode = false; */
	/* /1* dereference = DEREF_UNDEFINED; *1/ */
	/* recursive = false; */
	/* immediate_dirs = false; */
	/* ignore_mode = IGNORE_DEFAULT; */
	/* /1* ignore_patterns = NULL; *1/ */
	/* /1* hide_patterns = NULL; *1/ */
	/* /1* print_scontext = false; *1/ */
	/* format = long_format; */
	/* print_with_color = false; */
	/* print_hyperlink = false; */
/* case 'a': */
/* ignore_mode = IGNORE_MINIMAL; */
/* case 'd': */
/* immediate_dirs = true; */
/* case 'f': */
/* /1* Same as enabling -a -U and disabling -l -s.  *1/ */
/* ignore_mode = IGNORE_MINIMAL; */
/* sort_type = sort_none; */
/* sort_type_specified = true; */
/* /1* disable -l *1/ */
/* if (format == long_format) */
/* format = (isatty (STDOUT_FILENO) ? many_per_line : one_per_line); */
/* print_block_size = false;	/1* disable -s *1/ */
/* print_with_color = false;	/1* disable --color *1/ */
/* print_hyperlink = false;	/1* disable --hyperlink *1/ */
/* case 'g': */
/* format = long_format; */
/* print_owner = false; */
/* case 'l': */
/* format = long_format; */
/* case 'r': */
/* sort_reverse = true; */
/* case 't': */
/* sort_type = sort_time; */
/* sort_type_specified = true; */
/* case 'u': */
/* time_type = time_atime; */
/* case 'R': */
/* recursive = true; */




ft_parse_ls(argc, argv);
return (0);
}
