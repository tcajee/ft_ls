/* ************************************************************************** */
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

#include "libft.h"


//---<PRINTF_EN.PDF>--------------------------------------------------{{{

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


