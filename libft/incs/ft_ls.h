/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/30 17:00:03 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <sys/types.h>

# include <sys/stat.h>

# include <sys/time.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <limits.h>

# define E_FLAGS -1 // BAD FLAG
# define E_DIRS -2 // BAD DIR
# define E_USAGE -4 // BAD USAGE

# define B_IS(x , y) (x & y) ? 1 : 0
# define B_0(x , y) (x = x & ~y)
# define B_1(x , z) (x = x | z)
# define B_10(x , y , z) B_IS(x, y) ? B_0(y) : B_1(x , z)
/* B_0(x, y) */ 
/* B_IS(x , y) B_1(x , z) B_0(x, y) */


typedef enum	e_flags
{
	F_0 = 0,	// 0
	F_l = 1,	// -l
	F_R = 2,	// -R
	F_a = 4,	// -a
	F_r = 8,	// -r
	F_t = 16,	// -t
	F_1 = 32,	// -1
	F_u = 64,	// -u
	F_f = 128,	// -f
	F_d = 256,	// -d
	F_G = 512,	// -G
	F_g = 1024,	// -g
} 				t_flags;

typedef struct		s_file
{
	char			*name;
	char			path[PATH_MAX];
	mode_t			mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	dev_t			st_rdev;
	off_t			size;
	blkcnt_t		st_blocks;
	time_t			time;
	long			ntime;
}					t_file;

typedef struct		s_dirs
{
	char			*name;
	t_file			*file;
	t_file			*self;
	int				dirno;
	int				is_sub;
	struct s_dirs	*sub_dirs;
	struct s_dirs	*next;
	int				stat;
	int				total_blocks;
	int				max_file_len;
}					t_dirs;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;


int 			ft_flags(char **argv, t_flags *flags);
int				ft_check_flags(char flag, t_flags *flags);
int				ft_set_flags(int mode, int on, int off, t_flags *flags);
int				ft_error_flags(char flag);
void			ft_print_flags(t_flags *flags);

int				ft_dirs(char **argv, t_file **dirs);
int				ft_count_dirs(char **argv);
int				ft_check_dirs(char *path);

int				ft_ls(char *path, t_flags flags);

int				ft_add_dirs(char path[PATH_MAX], char *name, t_file **lst);
t_file			*ft_new_dir(char path[PATH_MAX], char *name, t_stat *stat);
int				ft_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX]);

void			ft_open_dirs(char *path);
int				ft_error_dirs(char *arg);

int				ft_sorts(int argc, char **argv);

/* int				ft_prints(int i, char **argv); */
void			ft_def_prints(char *path);
int				ft_list_prints(int i, char **argv);
int				ft_error_prints(char flag, int error);

int				ft_errors(int error);

int				ft_cleans(int argc, char **argv);

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

/* {{{TITLE

 -l, -r, -t, -u,
 * -R,
 * -a,
* -f, 
* -g, -d, ACL COLOURS COLUMNS 

Option flags

* long_format for lots of info, one per line.
-l (and other options that imply -l), -1, -C, -x and -m control this parameter*


* The file characteristic to sort by.  Controlled by -t, -S, -U, -X, -v.
   The values of each item of this enum are important since they are
   used as indices in the sort functions array (see sort_files()).  *

* Direction of sort.
   false means highest first if numeric,
   lowest first if alphabetic;
   these are the defaults.
   true means the opposite order in each case.  -r  *



 * }}} */
