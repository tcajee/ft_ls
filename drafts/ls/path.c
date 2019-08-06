
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/05 16:54:06 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_dirs
{
	char	*path;
	char	*name;
	char	*fpath[1024];
	struct stat	s_stat;

}				t_dirs;

int		ft_prints(char *path, int flags);
int		ft_rec_prints(char *path, int flags, t_dirs *dirs);
char	*ft_path_ls(char *path, char *d_name, char *fpath);
int		ft_def_prints(char *path);
void	ft_name_prints(char *path);
int		ft_ls_isdir(char *path);

int	ft_ls_isdir(char *path)
{
	struct stat	s_stat;

	if (stat(path, &s_stat) < 0)
		return (0);
if ((s_stat.st_mode & __S_IFMT) == __S_IFDIR)
		return (1);
	return (0);
}

void	ft_name_prints(char *path)
{
	puts(path);
	puts(":\n");
}

int	ft_def_prints(char *path)
{
	DIR				*dir;
	struct dirent	*s_dirent;


	dir = opendir(path);
	if (!dir)
		return (-1);
	while ((s_dirent = readdir(dir)))
	{
		if (s_dirent->d_name[0] != '.')
			printf("%s\n", s_dirent->d_name);
		else
			printf("%s\n", s_dirent->d_name);
	}
	closedir(dir);
	return (1);
}


char *		ft_path_ls(char *path, char *d_name, char *fpath)
{
	int i = -1;
	int j = -1;

	printf("%s/%s:%s\n", path, d_name, fpath);
	if (!fpath)
		fpath = (char *)malloc(sizeof(char) * (strlen(path) + strlen(d_name) + 2));
	if (fpath)
	{
		while (path[++i] != '\0')
			fpath[i] = path[i];
		fpath[i] = '/';
		while (d_name[++j] != '\0')
			fpath[++i] = d_name[j];
		fpath[++i] = '\0';
		printf("%s/%s:%s\n", path, d_name, fpath);
		if (ft_ls_isdir(fpath))
			return (fpath);
	}
	free(fpath);
	return (NULL);
}
	/* int		j; */
	/* char	*temp; */
	/* int	len; */

	/* printf("PATH: %s\n",path ); */
	/* printf("D_NAME: %s\n", d_name); */
	/* i = -1; */
	/* j = 0; */


	/* len = strlen(path) + strlen(d_name) + 1; */
	/* 	return (0); */
	/* temp[len] = '\0'; */
	/* while (temp[len]) */
	/* { */
	/* 	while (path[++i]) */
	/* 		temp[i] = path[i]; */
	/* 	temp[i] = '/'; */
	/* 	j += i; */
	/* 	i = -1; */
	/* 	while (d_name[++i]) */
	/* 		temp[++j] = d_name[i]; */
	/* } */
	/* *fpath = temp; */
	/* printf("TEMP: %s\n",temp); */



int	ft_rec_prints(char *path, int flags, t_dirs *dirs)
{
	printf("REC\n");
	DIR				*dir;
	struct dirent	*s_dirent;
	int 			i;
	int 			j;

	i = 0;
	dir = opendir(path);
	if (!dir)
		return (-1);

	ft_def_prints(path);
	while ((s_dirent = readdir(dir)) != NULL)
	{
		if (s_dirent->d_name[0] == '.' && s_dirent->d_name[1] == '\0')
			continue ;
		if (s_dirent->d_name[0] == '.' && s_dirent->d_name[1] == '.' && s_dirent->d_name[2] == '\0')
			continue ;
		if ((dirs->fpath[i] = ft_path_ls(path, s_dirent->d_name, dirs->fpath[i])) != NULL)
			i++;
		else
			continue ;
	}
	closedir(dir);

	j = 0;
	printf("[i = %d]	[j = %d]", i, j);
	while (j < i)
	{
		puts("\n");
		ft_name_prints(dirs->fpath[j]);
		printf("[i = %d]	[j = %d]", i, j);
		ft_rec_prints(dirs->fpath[j], flags, dirs);
		++j;
	}
	free(dirs);
	return (1);
}

int	main(int argc, char **argv)
{
	t_dirs	*dirs;
	int	F_1 = 1;
	
	dirs = NULL;
	if (!dirs)
		dirs = malloc(sizeof(t_dirs));
	if (!dirs->fpath)
		dirs->fpath = NULL;
	dirs->path = argv [1];
	if(argc == 1)
		ft_rec_prints(".", F_1, dirs);
	else if (argc > 1)
		ft_rec_prints(argv[1], F_1, dirs);
	printf("\n");
	return (1);
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
