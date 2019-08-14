/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/14 11:38:56 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_dir_check(char *path)
{
	t_stat	s_stat;

	FT_(lstat(path, &s_stat) < 0, 0);
	FT_((s_stat.st_mode & S_IFMT) == S_IFDIR, 1);
	return (0);
}

int	ft_dir_info(char *path, t_dirs *dirs)
{
	DIR			*dir;
	/* t_dirs		*dirt; */
	t_dirent	*s_dir;
	int i;

	i = 0;
	FT_(!(dirs = (t_dirs *)malloc(sizeof(t_dirs))), 0);
	FT_(!(dir = opendir(path)), 0);
	while ((s_dir = readdir(dir)) != NULL)
	{
		F_(!dirs->info[i], dirs->info[i] = (t_info *)malloc(sizeof(t_info)));
		FT_(!dirs->info[i], 0);

printf("s_dir->d_name:			%s\n", s_dir->d_name);
		FT_(!(dirs->info[i]->name = ft_strdup(s_dir->d_name)), 0);
printf("dirs->info[i]->name:		%s\n", dirs->info[i]->name);
printf("dir_path:			%s , %s\n", path, s_dir->d_name);
	/* F_(!IS_DOT(dirs->info[i]->name) && !IS_DDOT(dirs->info[i]->name), */
		FT_(!(dirs->info[i]->path = ft_dir_path(path, s_dir->d_name)), 0); //);
	/* F_(IS_DOT(dirs->info[i]->name) && IS_DDOT(dirs->info[i]->name), */
		FT_(!(dirs->info[i]->path = ft_dir_path(path, s_dir->d_name)), 0); //);
printf("dirs->info[i]->path:		%s\n", dirs->info[i]->path);


		if ((lstat(dirs->info[i]->path, &dirs->info[i]->s_stat)) < 0)
		{
			perror("LSTAT ");
			return (0);
		}

printf("%d\n", dirs->info[i]->s_stat.st_dev);
printf("%d\n", dirs->info[i]->s_stat.st_mode);
printf("%d\n", dirs->info[i]->s_stat.st_nlink);
/* printf("%d\n", dirs->info[i]->s_stat.st_ino); */
printf("%d\n", dirs->info[i]->s_stat.st_uid);
printf("%d\n", dirs->info[i]->s_stat.st_gid);
printf("%d\n", dirs->info[i]->s_stat.st_rdev);
/* printf("%d\n", dirs->info[i]->s_stat.st_size); */
/* printf("%\n", dirs->info[i]->s_stat.st_blocks); */
printf("%d\n", dirs->info[i]->s_stat.st_blksize);
printf("%d\n", dirs->info[i]->s_stat.st_gen);
		i++;
	}
	closedir(dir);
	return (1);
}

char	*ft_dir_path(char *path, char *d_name)
{
	int		i;
	int		len;
	char	*temp;
	/* char	*out; */

	/* out = NULL; */
	temp = NULL;
	i = -1;
	len = ft_strlen(path) + ft_strlen(d_name) + 1;
	FT_(!(temp = (char *)malloc(sizeof(char) * (len + 2))), NULL);
	while (*path)
		temp[++i] = *path++;
	temp[++i] = '/';
	while (*d_name)
		temp[++i] = *d_name++;
	temp[++i] = '\0';
	/* F_(ft_dir_check(temp), out = ft_strjoin(temp, "/..")); */
	/* _F(!ft_dir_check(temp), out = temp); */
	/* F_(temp, free(temp)); */
	return (temp);
}

int ft_dirs(char **argv, t_flags *flags)
{
	t_dirs	dirs;
	F_(ft_dir_check("drafts"), ft_dir_info("drafts", &dirs));
	F_(&dirs == NULL, printf("dir info failed\n"));

	(void)flags;
	(void)argv;
	/* int			i; */
	/* i = -1; */
	/* while (argv[++i]) */
	/* 		F_(!(ft_dir_check(argv[i])), ft_errors(E_PRINTS, argv[i])); */
	/* i = -1; */
	/* while (argv[++i]) */
	/* 	F_(ft_dir_check(argv[i]), ft_prints(flags, ft_dir_info(argv[i]))); */

	/* ft_print_lst(flags, tmp); */
	/* i = -1; */
	/* FT_(!argv[0], ft_prints(flags, ft_dir_info("."))); */
	/* while (argv[++i] && flags) */
	/* 		F_(!(ft_dir_check(argv[i])), ft_errors(E_PRINTS, argv[i])); */
	/* i = -1; */
	/* while (argv[++i]) */
	/* 	F_(ft_dir_check(argv[i]), ft_prints(flags, ft_sorts(flags, ft_dir_info(argv[i])))); */
	/* return (i); */

	return (0);
}

/* {{{TITLE


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
	 printf("s_stat: %s\n", s_stat);
	 return s_stat;
 }
char *get_path(char *path, char *name)
{
	char	*ret;
	const size_t	size = ft_strlen(path) + ft_strlen(name) + 2;
	ret = ft_strnew(size);
	ret = ft_strcpy(ret, name);
	ft_strlcat(ret, "/", size);
	ft_strlcat(ret, name, size);
	return (ret);
 }
int ft_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX])
{
	int i;
	i = -1;
	while (path[++i])
		full_path[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			full_path[i++] = '/';
	while (*name && i < PATH_MAX)
		full_path[i++] = *name++;
	if (i < PATH_MAX)
		full_path[i] = '\0';
	else
		errno = ENAMETOOLONG;
	return ((i < PATH_MAX) ? 1 : 0);
}


}}} */

/* {{{TITLE



int	ft_rec_prints(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;
	char			*fpath[1024];
	int 			i;
	int 			j;
	i = 0;
	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	while ((s_dirent = readdir(dir)))
	{

		printf("path: %s\n", path);
		printf("s_dir: %s\n", s_dirent->d_name);
		printf("fpath: %s\n", fpath[i] =get_path(path, s_dirent->d_name));

		if (ft_ls_isdir(fpath[i] = get_path(path, s_dirent->d_name)))
		{
			if (path[ft_strlen(path) - 1] == '/')
				fpath[i] = ft_strjoin(path, s_dirent->d_name);
			else
				fpath[i] = ft_strjoin(ft_strjoin(path, "/"), s_dirent->d_name);
			printf("fpath: %s\n", fpath[i]);
			++i;
			closedir(dir);
			j = -1;
			while (++j < i)
				ft_rec_prints(fpath[j], flags);
		}
	}
	return (1);
}

}}} */

 /* {{{TITLE */
/* nt ft_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX]) */
 /* { g */
 /* 	int	i; g */
 /*   i = -1; g */
 /*   while (path[++i]) g */
 /*   	full_path[i] = path[i]; g */
 /*   if (i && i < PATH_MAX) g */
 /*   	if (!(path[0] == '/' && path[1] == '\0')) g */
 /*   		full_path[i++] = '/'; g */
 /*   while (*name && i < PATH_MAX) g */
 /*   	full_path[i++] = *name++; g */
 /*   if (i < PATH_MAX) g */
 /*   	full_path[i] = '\0'; g */
 /*   else g */
 /*   	errno = ENAMETOOLONG; g */
 /*   return ((i < PATH_MAX) ? 1 : 0); g */
 /* } g */
 /* static t_file	*ft_new_dir(char path[PATH_MAX], char *name, t_stat *stat) g */
 /* { g */
 /* 	if (!(new = (t_file*)ft_memalloc(sizeof(t_file))) g */
 /* 	|| (!(new->name = ft_strdup(name)))) g */
 /* 		ls_error(NULL, 2); g */
 /* 	new->mode = stat->st_mode; g */
 /* 	new->st_nlink = stat->st_nlink; g */
 /* 	new->st_uid = stat->st_uid; g */
 /* 	new->st_gid = stat->st_gid; g */
 /* 	new->size = stat->st_size; g */
 /* 	new->st_rdev = stat->st_rdev; g */
 /* 	new->time = stat->st_mtimespec.tv_sec; g */
 /* 	new->ntime = stat->st_mtimespec.tv_nsec; g */
 /* 	new->st_blocks = stat->st_blocks; g */
 /* 	get_full_path(path, name, new->full_path); g */
 /* 	return (new); g */
 /* } g */
 /* int				ft_add_dir(char path[PATH_MAX], char *name, t_file **lst) g */
 /* { g */
 /* 	char		fpath[PATH_MAX]; g */
 /* 	t_stat		stat; g */
 /* 	if (!(ft_path(path, name, fpath))) g */
 /* 	{ g */
 /* 		ft_error_dirs(*name, 1); g */
 /* 		return (-1); g */
 /* 	} g */
 /* 	if (lstat(fpath, &stat) == -1) g */
 /* 		return (-1); g */
 /* 	if (!*lst) g */
 /* 		*lst = ft_new_dir(path, name, &stat); g */
 /* 	else g */
 /* 	{ g */
 /* 		while ((*lst)) g */
 /* 			lst = &((*lst)); g */
 /* 		(*lst) = ft_new_dir(path, name, &stat); g */
 /* 	} g */
 /* 	return (1); g */
 /* } g */
/* g */
/* }}} */

/* {{{TITLE

 	
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
	printf("struct dirent  // when _DARWIN_FEATURE_64_BIT_INODE is defined\n");
	printf("{\n");
	printf("	ino_t		d_fileno;		file number of entry\n");
	printf("	__uint64_t	d_seekoff;		seek offset (optional, used by servers)\n");
	printf("	__uint16_t	d_reclen;		length of this record\n");
	printf("	__uint16_t	d_namlen;		length of string in d_name\n");
	printf("	__uint8_t	d_type;			file type, see below\n");
	printf("	char		d_name[1024];		name must be no longer than this\n");
	printf("}\n");
	printf("struct group \n");
	printf("{\n");
	printf("	char		*gr_name;		group name\n");
	printf("	char		*gr_passwd;		group password\n");
	printf("	gid_t		gr_gid;			group id\n");
	printf("	char		**gr_mem;		group members\n");
	printf("}\n");
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






 * }}} */

/* {{{TITLE
 
  	
		printf("%s\n", dirs->darr[i]->s_pwd);
		printf("%s\n", dirs->darr[i]->s_grp);


		F_(!dirs->darr[i], dirs->darr[i] = (t_dirs *)malloc(sizeof(t_dirs)));
		FT_(!dirs->darr[i], NULL);
	printf("dirs->s_dir->d_name:		%s\n", dirs->s_dir->d_name);
		FT_(!(dirs->darr[i]->name = ft_strdup(dirs->s_dir->d_name)), NULL);
	printf("dirs->darr[i]->name:		%s\n", dirs->darr[i]->name);
	printf("path:	%s		%s\n", path, dirs->s_dir->d_name);
	F_(!IS_DOT(dirs->darr[i]->name) && !IS_DDOT(dirs->darr[i]->name),
		FT_(!(dirs->darr[i]->path = ft_dir_path(path, dirs->s_dir->d_name)), NULL));
	F_(IS_DOT(dirs->darr[i]->name) && IS_DDOT(dirs->darr[i]->name),
		FT_(!(dirs->darr[i]->path = ft_dir_path(path, dirs->s_dir->d_name)), NULL));
	printf("dirs->darr[i]->path:		%s\n", dirs->darr[i]->path);
		FT_((stat(dirs->darr[i]->path, dirs->darr[i]->s_stat)) < 0, NULL);
	
		
	printf("%d\n", dirs->darr[i]->s_stat->st_dev);
	printf("%d\n", dirs->darr[i]->s_stat->st_mode);
	printf("%d\n", dirs->darr[i]->s_stat->st_nlink);
	printf("%d\n", dirs->darr[i]->s_stat->st_ino);
	printf("%d\n", dirs->darr[i]->s_stat->st_uid);
	printf("%d\n", dirs->darr[i]->s_stat->st_gid);
	printf("%d\n", dirs->darr[i]->s_stat->st_rdev);
	printf("%d\n", dirs->darr[i]->s_stat->st_size);
	printf("%\n", dirs->darr[i]->s_stat->st_blocks);
	printf("%d\n", dirs->darr[i]->s_stat->st_blksize);
	printf("%d\n", dirs->darr[i]->s_stat->st_gen);
	
	
	
	FT_(!(dirs->darr[i]->s_pwd = getpwuid(dirs->darr[i]->s_stat->st_uid)), NULL);
		FT_(!(dirs->darr[i]->s_grp = getgrgid(dirs->darr[i]->s_stat->st_gid)), NULL);
		i++;
	}
	dirs->path = ft_strdup(path);
	dirs->dirc = i;
		printf("%s\n", dirs->path);
		printf("%d\n", dirs->dirc);
	closedir(dir);
	return (dirs);
 
 
 * }}} */




