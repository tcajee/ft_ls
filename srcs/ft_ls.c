/* *************************************************** *********************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/29 13:18:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

enum	acl_type
{
	ACL_T_NONE,
	ACL_T_LSM_CONTEXT_ONLY, 
	ACL_T_YES
};

enum	ftype
{
	unknown,
	fifo,
	chardev,
	directory,
	blockdev,
	normal,
	symbolic_link,
	sock,
	whiteout,
	arg_directory
};

struct	finfo
{
	/* The file name.  */
	char *name;
	/* For symbolic link, name of the file linked to, otherwise zero.  */
	char *linkname; /* For terminal hyperlinks. */
	char *absolute_name;
	struct stat fstat;
	enum ftype ftype;
	/* For symbolic link and long listing, st_mode of file linked to, otherwise zero.  */
	mode_t linkmode;
	/* security context.  */
	char *scontext;
	bool stat_ok;
	/* For symbolic link and color printing, true if linked-to file exists, otherwise false.  */
	bool linkok;
	/* For long listings, true if the file has an access control list, or a security context.  */
	enum acl_type acl_type;
	/* For color listings, true if a regular file has capability info.  */
	bool has_capability; /* Whether file name needs quoting. tri-state with -1 == unknown.  */
	int quoted;
};

struct fstat
{
	st_mode	The current permissions on the file.
	st_ino	The inode for the file (note that this number is unique to all files and directories on a Linux System.
	st_dev	The device that the file currently resides on.
	st_uid	The User ID for the file.
	st_gid	The Group ID for the file.
	st_atime	The most recent time that the file was accessed.
	st_ctime	The most recent time that the file's permissions were changed.
	st_mtime	The most recent time that the file's contents were modified.
	st_nlink	The number of links that there are to this file.
	st_size
};

/* The table of files in the current directory:
   'cwd_file' points to a vector of 'struct fileinfo', one per file.
   'cwd_n_alloc' is the number of elements space has been allocated for.
   'cwd_n_used' is the number actually in use.  */

/* Address of block containing the files that are described.  */
static struct finfo *cwd_file;

/* Length of block that 'cwd_file' points to, measured in files.  */
static size_t cwd_n_alloc;

/* Index of first unused slot in 'cwd_file'.  */
static size_t cwd_n_used;

/* Whether files needs may need padding due to quoting.  */
static bool cwd_some_quoted;

/* Record of one pending directory waiting to be listed.  */

struct pending
  {
    char *name;
    /* If the directory is actually the file pointed to by a symbolic link we
       were told to list, 'realname' will contain the name of the symbolic
       link, otherwise zero.  */
    char *realname;
    bool command_line_arg;
    struct pending *next;
  };

static struct pending *pending_dirs;

/* Current time in seconds and nanoseconds since 1970, updated as
   needed when deciding whether a file is recent.  */

static struct timespec current_time;


/* The number of columns to use for columns containing inode numbers,
   block sizes, link counts, owners, groups, authors, major device
   numbers, minor device numbers, and file sizes, respectively.  */

static int inode_number_width;
static int block_size_width;
static int nlink_width;
static int scontext_width;
static int owner_width;
static int group_width;
static int author_width;
static int major_device_number_width;
static int minor_device_number_width;
static int file_size_width;

/* Option flags */

/* long_format for lots of info, one per line.
   one_per_line for just names, one per line.
   many_per_line for just names, many per line, sorted vertically.
   horizontal for just names, many per line, sorted horizontally.
   with_commas for just names, many per line, separated by commas.
   -l (and other options that imply -l), -1, -C, -x and -m control
   this parameter.  */

enum format
  {
    long_format,		/* -l and other options that imply -l */
    one_per_line,		/* -1 */
    many_per_line,		/* -C */
    horizontal,			/* -x */
    with_commas			/* -m */
  };

enum time_type
  {
    time_mtime,			/* default */
    time_ctime,			/* -c */
    time_atime,			/* -u */
    time_numtypes		/* the number of elements of this enum */
  };
static enum time_type time_type;

/* The file characteristic to sort by.  Controlled by -t, -S, -U, -X, -v.
   The values of each item of this enum are important since they are
   used as indices in the sort functions array (see sort_files()).  */

enum sort_type
  {
    sort_none = -1,		/* -U */
    sort_name,			/* default */
    sort_extension,		/* -X */
    sort_size,			/* -S */
    sort_version,		/* -v */
    sort_time,			/* -t */
    sort_numtypes		/* the number of elements of this enum */
  };


static enum sort_type sort_type;

/* Direction of sort.
   false means highest first if numeric,
   lowest first if alphabetic;
   these are the defaults.
   true means the opposite order in each case.  -r  */
//---<FT_LS_EN.PDF>--------------------------------------------------{{{

/* Within your mandatory part you are allowed to use the following functions: */
/* ◦ write */
/* ◦ opendir */
/* ◦ readdir */
/* ◦ closedir */
/* ◦ stat */
/* ◦ lstat */
/* ◦ getpwuid */
/* ◦ getgrgid */
/* ◦ listxattr */
/* ◦ getxattr */
/* ◦ time */
/* ◦ ctime */
/* ◦ readlink */
/* ◦ malloc */
/* ◦ free */
/* ◦ perror */
/* ◦ strerror */
/* ◦ exit */
/* You are allowed to use other functions to carry out the bonus part as long as their */
/* use is justified during your defence. For example, to use tcgetattr is justified in */
/* certain case, to use printf because you are lazy isn’t. Be smart! */
/* You must recode the system’s command ls. */
/* Its behavior must be identical to the original ls command with the following variations: */
/* ◦ Amongst the numerous options available, we are asking you to create the following: -l, -R, -a, -r and -t. */
/* ◦ We strongly recommend that you account for the implications of the option -R from the very beginning of your code... */
/* ◦ You do not have to deal with the multiple column format for the exit when the option -l isn’t in the arguments. */
/* ◦ You are not required to deal with ACL and extended attributes. */
/* ◦ The overall display, depending on each option, must stay as identical as possible to the system command. We will be cordial when grading either the padding or the pagination, but no information can be missing. */
/* man ls */


//}}}


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


