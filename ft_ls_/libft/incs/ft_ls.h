/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/27 16:39:26 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdarg.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>

# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <limits.h>

# define E_FLAGS -1
# define E_DIRS -2
# define E_PRINTS -4
# define E_FILES -8

# define F_SET(FLAGS, F_OFF, F_ON) FLAGS = (FLAGS & ~(F_OFF)) | (F_ON);

# define F_0 0

# define F_1 1
# define F_l 2
# define F_g 4
# define F_t 8
# define F_u 16
# define F_r 32
# define F_f 64
# define F_a 128

# define F_R 256
# define F_d 512
# define F_F 1024
# define F_G 2048
# define F_L 4096
# define F_P 8192
# define F_00 16384
# define F_X 32768

# define F_I 65536
# define F_M 131072
# define F_REG 262144
# define F_5 524288
# define F_6 1048576
# define F_7 2097152
# define F_8 4194304
# define F_9 8388608

/* # define F_I 65536 */
/* # define F_M 131072 */
/* # define F_4 262144 */
/* # define F_5 524288 */
/* # define F_6 1048576 */
/* # define F_7 2097152 */
/* # define F_8 4194304 */
/* # define F_9 8388608 */

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_info
{
	int					dirc;
	char				*total;
	char				*root;
	char				*path;
	char				*name;
	t_stat				s_stat;
}						t_info;

int						ft_print_f(char *format, ...);

void					ft_files(int *flags, char *path);

int						ft_flags(int *flags, char **argv);
int						ft_flag_check(int *flags, char flag);
int						ft_lflag_check(int *flags, char *option);
int						ft_flag_set(int *flags, int flagc, ...);
void					ft_flag_print(int *flags);

int						ft_dirs(int *flags, char *arg);
int						ft_dir_info(int *flags, char *path);

char					*ft_dir_path(char *path, char *d_name);
void					ft_dir_clean(t_info dirs[]);
int						ft_dir_check(char *path);

void					ft_sorts(int *flags, t_info dirs[]);
void					ft_sort_tim(int *flags, t_info dirs[], int size);
void					ft_sort_merge(int *flags, t_info dirs[], int left, int mid, int right);
void					ft_sort_ins(int *flags, t_info dirs[], int left, int right);
int						ft_sort_comp(int *flags, t_info dirs[], int i, int j);

int						ft_prints(int *flags, t_info dirs[]);
int						ft_print_def(int *flags, t_info dir);
int						ft_print_lst(int *flags, t_info dir);
void					ft_print_perm(t_stat *s_stat);
void					ft_print_time(t_stat s_stat, int *flags);

int						ft_errors(int *flags, int code, char *error);
int						ft_error_flag(char *arg);
int						ft_error_print(int *flags, char *arg);
int						ft_error_dir(char *arg);
int						ft_error_file(char *arg);

#endif
