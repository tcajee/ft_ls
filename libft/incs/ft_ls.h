/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/22 16:18:28 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include <time.h>
# include <limits.h>

/* flags */
/* files */
/* dirs */
/* date */
/* format */

typedef enum	e_flags
{
	F_L = 1, // -l
	F_R = 2, // -R
	F_A = 4, // -a
	F_U = 8, // -u
	F_r = 16, // -r
	F_T = 32, // -t
	F_G = 64, // -g
	F_D = 128, // d
	F_F = 256, // f
} 				t_flags;


typedef struct	s_flags
{
	int		flags;
	int		recursive;
	int		immediate_dirs; 
	int		sort_type_specified;
	int		sort_reverse;
	int		print_block_size;
	int		print_inode;
	int		print_with_color;
	int		print_hyperlink;
	int		sort_type;
	int		format;
	int		time_type;
	int		ignore_mode;
}				t_flags;

int				ft_flags(int argc, char **argv);
int				ft_dirs(int argc, char **argv);
int				ft_prints(int i, char **argv);
int				ft_errors(int ERROR);

#endif
//---<DECODE>---------------------------------------------------------{{{


/* In all cases, ls: */
/* Assumes we always print the directory name */
/* Clears all pending directories */
/* Gets the current time for upcoming consistency checks */
/* Initializes flags to a default value */
/* Sets a default quoting style */
/* Pulls column and tab size from the environment */


/* Parsing */
/* The largest helper function is decode_switches() at 579 lines. The function goes through each of the command line arguments to set flags used later during execution. Parsing switches answers these general questions: */
/* What is the overall output format? */
/* What are the specific formats? (time, inode, blocks, etc) */
/* Are colors used? */
/* How is the output sorted and ordered? */
/* Is the search recursive? */
/* Does the search follow links? */
/* Switch decoding finishes by checking for consistency among options. Note that many options simply override others rather than failing (i.e. -l overrides -1). */

/* Parsing failures */
/* These failure cases are explicitly checked: */
/* An invalid line or tab size */
/* Invalid time style format */

/* Execution */
/* After parsing, the next step sets up the colors via the environment variables LS_COLORS or COLORTERM in that order. */

/* We then set search behaviors. This means finalizing symlink handling and preparing for a recusrive search (if used). Some smaller details include current time zone, sort format, dired mode stacks, and hyperlinks. */

/* The final step before processing is to set up the table data structure that we populate during file system traversal. The involves allocating the table and ensuring the sort order vector is clear. The initial directory (either user specified or cwd) is added to the processing queue and we're ready to go. */

/* Processing directories */
/* If only a single file is specified, that file is added to the file table and printed with print_current_files(). However, the typical case is that an entire directory is queued. This target directory (and eventually children) live in the pending_dirs list. These list members are checked for loops and then processed one at a time via print_dir(). Preparing directory output looks like this: */

/* Attempt to open directory with the opendir() syscall */
/* Check if the directory has been visited to avoid cycles */
/* Clear the file table to prep for the new directory */
/* Print the directory name, if appropriate */
/* Repeatedly make readdir() syscall until all files processed */
/* Check that file type isn't ignored */
/* Add the file to the table (more below) */
/* Handle any signals that may have arrived */
/* Close the current directory with closedir() syscall */
/* Sort the file table */
/* Revisit the table entries and add directories to the pending list */
/* Print the output of the file table (the cwd) */
/* Printing output */
/* Getting the files listed on the screen is the final step. This is more complicated than a call to printf() due to the variety possible output formats including a list of columns, a single list, many wrapped horizonal entries, and more. The most significant printing function is print_long_format(). In general, we walk file table and print the entries, which are already processed during add (gobble_file() - See below for details). The most in-depth printing call sequence worth exploring is: */

/* print_current_files() */
/* print_long_format() */
/* print_name_with_quoting() */
/* quote_name() - ends with fwrite() to STDOUT */
/* print_color_indicator() */
/* put_indicator() - The fwrite() here comes first */
/* There are several ways that file processing could fail: */

/* Failure cases: */

/* Unable to open directory (doesn't exist, no permissions, etc) */
/* Unable to stat file (doesn't exist, no permissions, bad path, etc) */
/* Improper hyperlink formatting */
/* Error reading directory */
/* Unable to close directory */
/* Unable to read a followed symlink */
/* Extra comments */
/* Adding a file to the file table */
/* A file is added with a call to gobble_file(), the 2nd largest helper function in this utility at 332 lines. While printing all the files simply walks the table, outputting all of the lines, most of the work in ls happens as each file is collected and stored. To add a file we perform a subset of the following operations, depending on format required: */

/* Ensure that the file table is large enough */
/* Set the file reference in the file table */
/* Verify quoting requirements */
/* Construct the full name of the file */
/* stat or lstat (if symlink) the file */
/* Check capabilities */
/* Check security context and access list */
/* Construct the link name (if link) */
/* Get widths: owner, group, author, security context, major/minor device, size, and inode */
/* Return the total size in blocks */



//}}}

/* typedef struct stat		t_stat; */
/* typedef struct dirent	t_dirent; */
/* typedef struct passwd	t_passwd; */
/* typedef struct group	t_group; */

/* -l, -r, -t, -u,
 * -R,
 * -a,
 * -f, 
 * -g, -d, ACL COLOURS COLUMNS */

/* Option flags */

/* long_format for lots of info, one per line.
-l (and other options that imply -l), -1, -C, -x and -m control this parameter*/

/* enum format */
/*   { */
/*     format_long,		/1* -l and other options that imply -l *1/ */
/*     format_numtypes		/1* the number of elements of this enum *1/ */
/*   }; */

/* enum time_type */
/* { */
/* 	time_mtime,			/1* default *1/ */
/* 	time_atime,			/1* -u *1/ */
/* 	time_numtypes		/1* the number of elements of this enum *1/ */
/* }; */

/* The file characteristic to sort by.  Controlled by -t, -S, -U, -X, -v.
   The values of each item of this enum are important since they are
   used as indices in the sort functions array (see sort_files()).  */

/* Direction of sort.
   false means highest first if numeric,
   lowest first if alphabetic;
   these are the defaults.
   true means the opposite order in each case.  -r  */

/* enum sort_type */
/*   { */
/*     sort_name,			/1* default *1/ */
/*     sort_time, */
/* 	psort_reverse,		/1* -t *1/ */
/*     sort_direction,			/1* -r *1/ */
/*     sort_numtypes		/1* the number of elements of this enum *1/ */
/*   }; */




