/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sysinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:55:00 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/29 12:50:44 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void		ft_print_stat(void)
{
	printf("struct stat // when _DARWIN_FEATURE_64_BIT_INODE is defined\n");
	printf("{\n");
	printf("	dev_t		st_dev			ID of device containing file\n");
	printf("	mode_t		st_mode			Mode of file (see below)\n");
	printf("	nlink_t		st_nlink		Number of hard links\n");
	printf("	ino_t		st_ino			File serial number\n");
	printf("	uid_t		st_uid			User ID of the file\n");
	printf("	gid_t		st_gid			Group ID of the file\n");
	printf("	dev_t		st_rdev			Device ID\n");
	printf("	struct timespec st_atimespec		time of last access\n");
	printf("	struct timespec st_mtimespec		time of last data modification\n");
	printf("	struct timespec st_ctimespec		time of last status change\n");
	printf("	struct timespec st_birthtimespec	time of file creation(birth)\n");
	printf("	off_t		st_size			file size, in bytes\n");
	printf("	blkcnt_t	st_blocks		blocks allocated for file\n");
	printf("	blksize_t	st_blksize		optimal blocksize for I/O\n");
	printf("	uint32_t	st_flags		user defined flags for file\n");
	printf("	uint32_t	st_gen			file generation number\n");
	printf("	int32_t		st_lspare		RESERVED: DO NOT USE!\n");
	printf("	int64_t		st_qspare[2]		RESERVED: DO NOT USE!\n");
	printf("}\n");
}

void		ft_print_dirent(void)
{
	printf("struct dirent  // when _DARWIN_FEATURE_64_BIT_INODE is defined\n");
	printf("{\n");
	printf("	ino_t		d_fileno;		file number of entry\n");
	printf("	__uint64_t	d_seekoff;		seek offset (optional, used by servers)\n");
	printf("	__uint16_t	d_reclen;		length of this record\n");
	printf("	__uint16_t	d_namlen;		length of string in d_name\n");
	printf("	__uint8_t	d_type;				file type, see below\n");
	printf("	char		d_name[1024];		name must be no longer than this\n");
	printf("}\n");
}

void		ft_print_group(void)
{
	printf("struct group \n");
	printf("{\n");
	printf("	char		*gr_name;		group name\n");
	printf("	char		*gr_passwd;		group password\n");
	printf("	gid_t		gr_gid;			group id\n");
	printf("	char		**gr_mem;		group members\n");
	printf("}\n");
}

void		ft_print_passwd(void)
{
	printf("struct passwd\n");
	printf("{\n");
	printf("	char		*pw_name;		user name\n");
	printf("	char		*pw_passwd;		encrypted password\n");
	printf("	uid_t		pw_uid;			user uid\n");
	printf("	gid_t		pw_gid;			user gid\n");
	printf("	time_t		pw_change;		password change time\n");
	printf("	char		*pw_class;		user access class\n");
	printf("	char		*pw_gecos;		Honeywell login info\n");
	printf("	char		*pw_dir;		home directory\n");
	printf("	char		*pw_shell;		default shell\n");
	printf("	time_t		pw_expire;		account expiration\n");
	printf("	int		pw_fields;		internal: fields filled in\n");
	printf("}\n");
}

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

char	*dirname(char *fname, char *s_stat)
{
	char *ptr;

	strcpy (s_stat, fname);
	if ((ptr = strrchr (s_stat, '/')) == NULL)
	{
		s_stat[0] = '.';
		s_stat[1] = '\0';
	}
	else if (s_stat != ptr)
	{
		*ptr++ = '\0';
		if(*ptr == '\0')
		{
			ptr = strrchr (s_stat, '/');
			if (ptr != NULL && s_stat != ptr)
				*ptr = '\0';
		}
	}
	return s_stat;
}

void	ft_prints(char *fname, struct stat *s_stat)
{
	static char path[PATH_MAX];
	static struct stat dir;
	int flag;

	flag = 0;
	
	ft_print_stat();
	ft_print_dirent();
	ft_print_group();
	ft_print_passwd();
	printf ("\nFile information for %s\n", fname);
	printf ("\tFilesystem ID : Major %02x Minor %02x\n",
			(((int) s_stat->st_dev) >> 8) & 0xff, ((int) s_stat->st_dev) & 0xff);
	printf ("\tFile inode : %d\n",    (int) s_stat->st_ino);
	printf ("\tFile mode : ");

	FT(S_ISBLK(s_stat->st_mode),  printf("BLOCK "));
	FT(S_ISCHR(s_stat->st_mode),  printf("CHAR "));
	FT(S_ISDIR(s_stat->st_mode),  printf("DIRECTORY "));
	FT(S_ISFIFO(s_stat->st_mode), printf("FIFO "));
	FT(S_ISREG(s_stat->st_mode),  printf("FILE "));
	FT(S_ISSUID(s_stat->st_mode), printf("SETUID "));
	FT(S_ISSGID(s_stat->st_mode), printf("SETGID "));

	/*FT(S_ISNAM(s_stat->st_mode), printf ("PIPE ")); */

	printf("%s\n", filemode((int)s_stat->st_mode));
	printf("\tYour rights : ");

	FT((( getuid() == s_stat->st_uid) && ( s_stat->st_mode & S_IRUSR) ) ||
	   (( getgid() == s_stat->st_gid) && ( s_stat->st_mode & S_IRGRP) ) ||
		( s_stat->st_mode & S_IROTH)                                    ||
		( getuid() == 0)                                                 ,
	  FT( S_ISDIR(s_stat->st_mode)                                       ,
		  printf("LIST %c ", flag++))                                    )
	else  printf("READ %c", flag++)                                      ;

	FT((( getuid() == s_stat->st_uid) && ( s_stat->st_mode & S_IWUSR) ) ||
	   (( getgid() == s_stat->st_gid) && ( s_stat->st_mode & S_IWGRP) ) ||
		( s_stat->st_mode & S_IWOTH)                                    ||
		( getuid() == 0)                                                 ,
	  FT( S_ISDIR(s_stat->st_mode)                                       ,
		  printf("CREATE FILES  DELETE FILES %c", flag++))               )
	else  printf("WRITE %c", flag++)                                     ;

	FT((( getuid() == s_stat->st_uid) && ( s_stat->st_mode & S_IXUSR))  ||
	   (( getgid() == s_stat->st_gid) && ( s_stat->st_mode & S_IXGRP))  ||
		( s_stat->st_mode & S_IXOTH)                                    ||
		( getuid() == 0 && (s_stat->st_mode & (S_IXUSR|S_IXGRP|S_IXOTH))),
	  FT( S_ISDIR(s_stat->st_mode)                                       ,
		  printf("CHANGE TO  %c", flag++))                               )
	else  printf("EXECUTE %c", flag++)                                   ;

	FT(  S_ISDIR(s_stat->st_mode)                                        ,
		 strcat(strcpy (path, fname), "/..")                             )
	else dirname (fname, path)                                           ;

	FT(     stat (path, &dir) != -1                                      ,
	 FT(((( getuid() == dir.st_uid) && (dir.st_mode & S_IWUSR) )        ||
		 (( getgid() == dir.st_gid) && (dir.st_mode & S_IWGRP) )        ||
		  ( dir.st_mode & S_IWOTH)                                      ||
		  ( getuid() == 0))                                              ,
		FT( S_ISDIR(s_stat->st_mode)                                     ,
			printf("REMOVE %c", flag++)))                                )
	else    printf ("DELETE %c", flag++)                                 ;

	printf("%s\n", (flag)?"":"(NONE)")                                   ;

	FT(S_ISREG( s_stat->st_mode)                                         ,
		printf( "\tNumber of Links : %d\n", (int) s_stat->st_nlink)     ;
		printf( "\tUser ID : %d (%s)\n"                                 ,
			  ( int)s_stat->st_uid                                       ,
			  ( getuname((int)s_stat->st_uid)))                          ;
		printf( "\tGroup ID : %d (%s)\n"                                ,
			  ( int)s_stat->st_gid                                       ,
			  ( getgname ((int)s_stat->st_gid))))                        ;

	FT(S_ISBLK( s_stat->st_mode) || S_ISCHR(s_stat->st_mode)             ,
		printf( "\tSpecial Device : Major %02x Minor %02x\n"            ,
		      ( ((int) s_stat->st_rdev) >> 8) & 0xff                     ,
		      ( (int) s_stat->st_rdev) & 0xff)                           )


	FT(S_ISFIFO( s_stat->st_mode)                                        ,
		 printf( "\tData in Fifo : %d\n", (int) s_stat->st_size)        )

	FT(S_ISREG( s_stat->st_mode)                                         ,
		printf( "\tFile Size : %d\n", (int) s_stat->st_size)            )

	printf( "\tLast File access : %s", ctime (&s_stat->st_atime))        ;
	printf( "\t... modification : %s", ctime (&s_stat->st_mtime))        ;
	printf( "\tFile creation : %s", ctime (&s_stat->st_ctime))        ;
	printf( "\n");

	printf("File Size: \t\t%lld bytes\n", s_stat->st_size);
	printf("Number of Links: \t%hu\n", s_stat->st_nlink);
	printf("File inode: \t\t%lld\n", s_stat->st_ino);
	printf("File Permissions: \t");
	printf( (S_ISDIR(s_stat->st_mode)) ? "d" : "-");
	printf( (s_stat->st_mode & S_IRUSR) ? "r" : "-");
	printf( (s_stat->st_mode & S_IWUSR) ? "w" : "-");
	printf( (s_stat->st_mode & S_IXUSR) ? "x" : "-");
	printf( (s_stat->st_mode & S_IRGRP) ? "r" : "-");
	printf( (s_stat->st_mode & S_IWGRP) ? "w" : "-");
	printf( (s_stat->st_mode & S_IXGRP) ? "x" : "-");
	printf( (s_stat->st_mode & S_IROTH) ? "r" : "-");
	printf( (s_stat->st_mode & S_IWOTH) ? "w" : "-");
	printf( (s_stat->st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
	printf("The file %s a symbolic link\n", (S_ISLNK(s_stat->st_mode)) ? "is" : "is not");


	/* if (S_ISNAM(s_stat->st_mode)) */
	/* printf ("\t    Data in Pipe : %d\n", (int) s_stat->st_size); */
}

int main (int argc, char *argv[])
{
	struct stat s_stat;
	int index;

	index = 1;
	while (index < argc)
	{
		if (stat (argv[index], &s_stat) == -1)
			printf("\nStat failed for file %s. errno=%d\n\n", argv[index], errno);
		else
			ft_prints(argv[index], &s_stat);
		index++;
	}
	return 0;
}


