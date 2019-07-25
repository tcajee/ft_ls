/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/24 16:22:11 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int ft_ls(int argc, char **argv)
{
	t_flags flags;
	int		i;

	flags = 0;
	// handle flags
	i = ft_flags(argv, &flags);
	// handle dirs
	if (i < argc)
		i = ft_dirs(argc, argv + i);
	// handle memory
	// handle printing
	// handle errors
	return (i);
}

/* {{{temp
 *
 */

/* numeric_ids = false; */
/* indicator_style = none; */
/* dereference = DEREF_UNDEFINED; */
/* ignore_patterns = NULL; */
/* hide_patterns = NULL; */
/* print_scontext = false; */



	/* time_type = time_mtime; */
	/* sort_type = sort_name; */
	/* sort_reverse = false; */
	/* print_block_size = false; */
	/* print_inode = false; */
	/* recursive = false; */
	/* immediate_dirs = false; */
	/* format = long_format; */
	/* ignore_mode = IGNORE_DEFAULT; */
	/* print_with_color = false; */
	/* print_hyperlink = false; */


/* case 'a': */
/* ignore_mode = IGNORE_MINIMAL; */
/* case 'd': */
/* immediate_dirs = true; */
/* case 'f': */
/* Same as enabling -a -U and disabling -l -s. */ 
/* ignore_mode = IGNORE_MINIMAL; */
/* sort_type = sort_none; */
/* sort_type_specified = true; */
/* disable -l */
/* if (format == long_format) */
/* format = (isatty (STDOUT_FILENO) ? many_per_line : one_per_line); */
/* print_block_size = false;	 disable -s */ 
/* print_with_color = false;	 disable --color */ 
/* print_hyperlink = false;	 disable --hyperlink */ 
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
/*  recursive = true; */

 /* }}} */
