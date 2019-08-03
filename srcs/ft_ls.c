/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/03 06:13:34 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"


char*dirname(char *fname, char *s_stat)
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


int	ft_ls(char **argv, t_flags *flags)
{
	t_stat s_stat;
	int i;
	int k;

	i = -1;
	k = -1;
	
	ft_print_flags(flags);
	ft_putchar('\n');
	
	
	
	FT_(!argv[0], ft_prints(".", flags));
	while (argv[++i])
		FT(lstat(argv[i], &s_stat) < 0, ft_errors(E_PRINTS, argv[i]));
	while (argv[++k])
		FT((s_stat.st_mode & S_IFMT) == S_IFDIR, ft_prints(argv[k], flags));
	
	/* printf("argv[%d]: %s	", i, argv[i]); */
	return (i);
}


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

// {{{TITLE
 
 /* void	ft_recur_prints(char *path, t_flags* flags) */
/* { */
	/* DIR				*dp; */
	/* struct dirent	*dir; */
	/* t_files			*files; // Put in struct */
	/* int 			i; */
	/* int 			j; */
	/* i = 0; */
	/* while ((dir = readdir(dp)) != NULL) */
	/* { */
		/* FT_(lstat(path, &stat) < 0, ft_error_dirs(argv[i])); */
		/* if (dir->d_name[0] != '.' && *flags == F_1); */ 
		/* ft_def_print(name, dir->d_name); // call print function. What do we feed it? */
		/* if ((-R)) */
		/* { */
			/* if (ft_ls_isdir(ft_strjoin(ft_strjoin(name, "/"), dir->d_name)) && dir->d_name[0] != '.') */
			/* { */
				/* if (name[ft_strlen(name) -1] == '/') */
					/* files->rec[i] = ft_strjoin(name, dir->d_name); // newname struct */
				/* else */
					/* files->rec[i] = ft_strjoin(ft_strjoin(name, "/"), dir->d_name); // struct */
				/* ++i; */
	/* { 		} */
			/* closedir(dp); */
			/* j = 0; */
			/* while (j < i) */
			/* { */
				/* printf("\n%s:\n", files->rec[j]); // struct */
				/* list(files->rec[j]);              // struct */
				/* ++j; */
			/* } */
		/* } */
	/* } */
	/* return (i); */
/* } */
/* }} */
 	
 
 // }}}











