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

#include <stdbool.h>

typedef struct	s_flags
{
	bool		flags;
	bool 		recursive;
	bool		immediate_dirs;
	bool		sort_type_specified;
	bool 		sort_reverse;
	bool		print_block_size;
	bool		print_inode;
	bool		print_with_color;
	bool		print_hyperlink;
	int			sort_type;
	int			format;
	int			time_type;
	int			ignore_mode;
}				t_flags;


#include "../libft/incs/libft.h"

int	ft_ls(int argc, char **argv)
{
	ft_parse_ls(argc, argv);
	return (0);
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


case 'a':
ignore_mode = IGNORE_MINIMAL;
case 'd':
immediate_dirs = true;
case 'f':
/* Same as enabling -a -U and disabling -l -s.  */
ignore_mode = IGNORE_MINIMAL;
sort_type = sort_none;
sort_type_specified = true;
/* disable -l */
if (format == long_format)
format = (isatty (STDOUT_FILENO) ? many_per_line : one_per_line);
print_block_size = false;	/* disable -s */
print_with_color = false;	/* disable --color */
print_hyperlink = false;	/* disable --hyperlink */
case 'g':
format = long_format;
print_owner = false;
case 'l':
format = long_format;
case 'r':
sort_reverse = true;
case 't':
sort_type = sort_time;
sort_type_specified = true;
case 'u':
time_type = time_atime;
case 'R':
 recursive = true;

 /* }}} */
