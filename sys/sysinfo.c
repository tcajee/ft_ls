/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sysinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:55:00 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/29 10:37:28 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

// {{{	DEFINITIONS

#ifndef S_ISREG
#ifndef S_IFREG
#ifndef _S_IFREG
#define S_IFREG		(-1)
#else
#define S_IFREG		_S_IFREG
#endif
#endif
#define S_ISREG(m)	(((m)&S_IFREG)==S_IFREG)
#endif

#ifndef S_ISBLK
#ifndef S_IFBLK
#ifndef _S_IFBLK
#define S_IFBLK		(-1)
#else
#define S_IFBLK		_S_IFBLK
#endif
#endif
#define S_ISBLK(m)	(((m)&S_IFBLK)==S_IFBLK)
#endif

#ifndef S_ISCHR
#ifndef S_IFCHR
#ifndef _S_IFCHR
#define S_IFCHR		(-1)
#else
#define S_IFCHR		_S_IFCHR
#endif
#endif
#define S_ISCHR(m)	(((m)&S_IFCHR)==S_IFCHR)
#endif

#ifndef S_ISDIR
#ifndef S_IFDIR
#ifndef _S_IFDIR
#define S_IFDIR		(-1)
#else
#define S_IFDIR		_S_IFDIR
#endif
#endif
#define S_ISDIR(m)	(((m)&S_IFDIR)==S_IFDIR)
#endif

#ifndef S_ISFIFO
#ifndef S_IFIFO
#ifndef _S_IFIFO
#define S_IFIFO		(-1)
#else
#define S_IFIFO		_S_IFIFO
#endif
#endif
#define S_ISFIFO(m)	(((m)&S_IFIFO)==S_IFIFO)
#endif

#ifndef S_ISSUID
#ifndef S_ISUID
#ifndef _S_ISUID
#define S_ISUID		(-1)
#else
#define S_ISUID		_S_ISUID
#endif
#endif
#define S_ISSUID(m)	(((m)&S_ISUID)==S_ISUID)
#endif

#ifndef S_ISSGID
#ifndef S_ISGID
#ifndef _S_ISGID
#define S_ISGID		(-1)
#else
#define S_ISGID		_S_ISGID
#endif
#endif
#define S_ISSGID(m)	(((m)&S_ISGID)==S_ISGID)
#endif

#ifndef S_IRUSR
#define S_IRUSR		0x0100
#endif
#ifndef S_IWUSR
#define S_IWUSR		0x0080
#endif
#ifndef S_IXUSR
#define S_IXUSR		0x0040
#endif
#ifndef S_IRGRP
#define S_IRGRP		0x0020
#endif
#ifndef S_IWGRP
#define S_IWGRP		0x0010
#endif
#ifndef S_IXGRP
#define S_IXGRP		0x0008
#endif
#ifndef S_IROTH
#define S_IROTH		0x0004
#endif
#ifndef S_IWOTH
#define S_IWOTH		0x0002
#endif
#ifndef S_IXOTH
#define S_IXOTH		0x0001
#endif
//}}}

// {{{	FUNCTIONS

int		ft_print_stat(char *arg, struct stat *buf)
{

	printf("Information for %s\n", arg);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n", buf->st_size);
	printf("Number of Links: \t%hu\n", buf->st_nlink);
	printf("File inode: \t\t%lld\n", buf->st_ino);
	printf("File Permissions: \t");
	printf( (S_ISDIR(buf->st_mode)) ? "d" : "-");
	printf( (buf->st_mode & S_IRUSR) ? "r" : "-");
	printf( (buf->st_mode & S_IWUSR) ? "w" : "-");
	printf( (buf->st_mode & S_IXUSR) ? "x" : "-");
	printf( (buf->st_mode & S_IRGRP) ? "r" : "-");
	printf( (buf->st_mode & S_IWGRP) ? "w" : "-");
	printf( (buf->st_mode & S_IXGRP) ? "x" : "-");
	printf( (buf->st_mode & S_IROTH) ? "r" : "-");
	printf( (buf->st_mode & S_IWOTH) ? "w" : "-");
	printf( (buf->st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
	printf("The file %s a symbolic link\n", (S_ISLNK(buf->st_mode)) ? "is" : "is not");
	return (0);
}

 // }}} 


// {{{TITLE



 // }}} 
// {{{TITLE



 // }}} 
// {{{TITLE



 // }}} 

char	*filemode(int mode)
{
	static char result[11];
	static char rwxkey[8][4] =
	{ "---", "--x", "-w-", "-wx",	"r--", "r-x", "rw-", "rwx" };

	result[0] = '-';
	result[1] = rwxkey[((mode >> 6) & 0x07)][0];
	result[2] = rwxkey[((mode >> 6) & 0x07)][1];
	result[3] = rwxkey[((mode >> 6) & 0x07)][2];
	result[4] = rwxkey[((mode >> 3) & 0x07)][0];
	result[5] = rwxkey[((mode >> 3) & 0x07)][1];
	result[6] = rwxkey[((mode >> 3) & 0x07)][2];
	result[7] = rwxkey[  mode       & 0x07 ][0];
	result[8] = rwxkey[  mode       & 0x07 ][1];
	result[9] = rwxkey[  mode       & 0x07 ][2];
	result[10]= '\0';
	return result;
}

char	*getuname(int uid)
{
	static char res[20];
	struct passwd *pwent;

	if ((pwent = getpwuid (uid)) == NULL)
		sprintf (res, "%d", uid);
	else
		strcpy (res, pwent->pw_name);
	return res;
}

char	*getgname(int gid)
{
	static char res[20];
	struct group *grent;

	if ((grent = getgrgid (gid)) == NULL)
		sprintf (res, "%d", gid);
	else
		strcpy (res, grent->gr_name);
	return res;
}

char	*dirname(char *fname, char *buf)
{
	char *ptr;

	strcpy (buf, fname);
	if ((ptr = strrchr (buf, '/')) == NULL)
	{
		buf[0] = '.';
		buf[1] = '\0';
	}
	else if (buf != ptr)
	{
		*ptr++ = '\0';
		if(*ptr == '\0')
		{
			ptr = strrchr (buf, '/');
			if (ptr != NULL && buf != ptr)
				*ptr = '\0';
		}
	}
	return buf;
}

void	printinfo(char *fname, struct stat *buf)
{
  static char tbuf[PATH_MAX];
  static struct stat dir;
  int flag;

  flag = 0;

  printf ("\nFile information for %s\n", fname);
  printf ("\t   Filesystem ID : Major %02x Minor %02x\n",
	  (((int) buf->st_dev) >> 8) & 0xff, ((int) buf->st_dev) & 0xff);
  printf ("\t      File inode : %d\n",    (int) buf->st_ino);
  printf ("\t       File mode : ");

#ifdef S_ISBLK
  if (S_ISBLK(buf->st_mode))  printf ("BLOCK ");
#endif
#ifdef S_ISCHR
  if (S_ISCHR(buf->st_mode))  printf ("CHAR ");
#endif
#ifdef S_ISDIR
  if (S_ISDIR(buf->st_mode))  printf ("DIRECTORY ");
#endif
#ifdef S_ISFIFO
  if (S_ISFIFO(buf->st_mode)) printf ("FIFO ");
#endif
#ifdef S_ISNAM
  if (S_ISNAM(buf->st_mode))  printf ("PIPE ");
#endif
#ifdef S_ISREG
  if (S_ISREG(buf->st_mode))  printf ("FILE ");
#endif
#ifdef S_ISSUID
  if (S_ISSUID(buf->st_mode)) printf ("SETUID ");
#endif
#ifdef S_ISSGID
  if (S_ISSGID(buf->st_mode)) printf ("SETGID ");
#endif

  printf ("%s\n", filemode ((int)buf->st_mode));
  printf ("\t     Your rights : ");

  if (((getuid()==buf->st_uid) && (buf->st_mode&S_IRUSR)) ||
      ((getgid()==buf->st_gid) && (buf->st_mode&S_IRGRP)) ||
      (                            buf->st_mode&S_IROTH)  ||
      ( getuid()==0                                    )) {
#ifdef S_ISDIR
    if (S_ISDIR(buf->st_mode))
      printf ("LIST %c ", flag++);
    else
#endif
      printf ("READ %c", flag++);
  }
  if (((getuid()==buf->st_uid) && (buf->st_mode&S_IWUSR)) ||
      ((getgid()==buf->st_gid) && (buf->st_mode&S_IWGRP)) ||
      (                            buf->st_mode&S_IWOTH)  ||
      ( getuid()==0                                    )) {
#ifdef S_ISDIR
    if (S_ISDIR(buf->st_mode))
      printf ("CREATE FILES  DELETE FILES  %c", flag++);
    else
#endif
      printf ("WRITE %c", flag++);
  }
  if (((getuid()==buf->st_uid) && (buf->st_mode&S_IXUSR)) ||
      ((getgid()==buf->st_gid) && (buf->st_mode&S_IXGRP)) ||
      (                            buf->st_mode&S_IXOTH)  ||
      ( getuid()==0 && (buf->st_mode&(S_IXUSR|S_IXGRP|S_IXOTH)))) {
#ifdef S_ISDIR
    if (S_ISDIR(buf->st_mode))
      printf ("CHANGE TO  %c", flag++);
    else
#endif
      printf ("EXECUTE %c", flag++);
  }
#ifdef S_ISDIR
  if (S_ISDIR(buf->st_mode))
    strcat (strcpy (tbuf, fname), "/..");
  else
    dirname (fname, tbuf);
#endif
  if (stat (tbuf, &dir) != -1) {
    if (((getuid()==dir.st_uid) && (dir.st_mode&S_IWUSR)) ||
	((getgid()==dir.st_gid) && (dir.st_mode&S_IWGRP)) ||
	(                           dir.st_mode&S_IWOTH)  ||
	( getuid()==0                                  )) {
#ifdef S_ISDIR
      if (S_ISDIR(buf->st_mode))
	printf ("REMOVE %c", flag++);
      else
#endif
	printf ("DELETE %c", flag++);
    }
  }
  printf ("%s\n", (flag)?"":"(NONE)");

#ifdef S_ISREG
  if (S_ISREG(buf->st_mode))
#endif
    printf ("\t Number of Links : %d\n", (int) buf->st_nlink);

  printf ("\t         User ID : %d (%s)\n", (int)buf->st_uid, getuname ((int)buf->st_uid));
  printf ("\t        Group ID : %d (%s)\n", (int)buf->st_gid, getgname ((int)buf->st_gid));

#if defined(S_ISBLK) || defined(S_ISCHR)
  if (S_ISBLK(buf->st_mode) || S_ISCHR(buf->st_mode))
    printf ("\t      Special Device : Major %02x Minor %02x\n",
	    (((int) buf->st_rdev) >> 8) & 0xff, ((int) buf->st_rdev) & 0xff);
#endif

#ifdef S_ISNAM
  if (S_ISNAM(buf->st_mode))
    printf ("\t    Data in Pipe : %d\n", (int) buf->st_size);
#endif

#ifdef S_ISFIFO
  if (S_ISFIFO(buf->st_mode))
    printf ("\t    Data in Fifo : %d\n", (int) buf->st_size);
#endif

#ifdef S_ISREG
  if (S_ISREG(buf->st_mode))
#endif
    printf ("\t       File Size : %d\n", (int) buf->st_size);

	printf ("\tLast File access : %s", ctime (&buf->st_atime));
	printf ("\t... modification : %s", ctime (&buf->st_mtime));
	printf ("\t   File creation : %s", ctime (&buf->st_ctime));
	printf ("\n");
	ft_print_stat(fname, buf);
}

int main (int argc, char *argv[])
{
	struct stat buf;
	int index;

	index = 1;
	while (index < argc)
	{
		if (stat (argv[index], &buf) == -1)
			printf ("\nStat failed for file %s. Errno=%d\n\n", argv[index], errno);
		else
			printinfo (argv[index], &buf);
		index++;
	}
	return 0;
}


