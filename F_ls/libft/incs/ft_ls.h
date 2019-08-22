/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/21 16:18:59 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <stdarg.h>
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

# define E_FLAGS	-1
# define E_DIRS		-2
# define E_PRINTS	-4
# define E_FILES	-8

# define B_IS(x , y) (x & y) ? 1 : 0
# define B_0(x , y) (x = x & ~y)
# define B_1(x , z) (x = x | z)

# define IS_DOT(x) (x[0] == '.' && x[1] == '\0') ? 1 : 0
# define IS_DDOT(x) (x[0] == '.' && x[1] == '.' && x[2] == '\0') ? 1 : 0

# define F_0 0
# define F_1 1
# define F_l 2
# define F_g 4
# define F_t 8
# define F_u 1
# define F_r 32
# define F_f 64
# define F_a 128
# define F_G 256
# define F_d 512
# define F_R 1024
# define F_P 16384
# define F_M 32768
/* # define F_0 32768 */
/* # define F_0 32768 */
/* # define F_0 32768 */

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;
typedef struct winsize	t_wins;

typedef struct			s_info
{
	char				*total;
	size_t				dirc;
	char				*root;
	char				*path;
	char				*name;
	t_stat				s_stat;
}						t_info;

typedef struct			s_dirs
{
	t_info				dirs[1024];
}						t_dirs;

typedef struct			s_terms
{
	size_t				w_row;
	size_t				w_col;
}						t_terms;

typedef struct			s_format
{
	size_t				f_perm;
	size_t				f_link;
	size_t				f_user;
	size_t				f_group;
	size_t				f_size;
	size_t				f_time;
	size_t				f_name;
	char				*line[7];
}						t_format;

int						ft_print_f(char *format, ...);

int						ft_flags(int *flags, char **argv);
int						ft_flag_check(int *flags, char flag);
int						ft_lflag_check(int *flags, char *option);
int						ft_flag_set(int *flags, int flagc, ...);
void					ft_flag_print(int *flags);

int						ft_dirs(int *flags, t_info dirs[], char *arg);
int						ft_dir_info(char *path, t_info dirs[]);
char					*ft_dir_path(char *path, char *d_name);
void					ft_dir_clean(t_info dirs[]);
int						ft_dir_check(char *path);

int						ft_sorts(t_info dirs[]);
void					ft_sort_tim(t_info dirs[], int size);
void					ft_sort_merge(t_info dirs[], int left, int mid, int right);
void					ft_sort_ins(t_info dirs[], int left, int right);
void					ft_sort_min(int *flags, t_info dir_a, t_info dir_b);

int						ft_prints(int *flags, t_info dirs[]);
int						ft_print_def(t_info dir);
int						ft_print_lst(int *flags, t_info dir);
void					ft_print_perm(t_stat *s_stat);

void					ft_print_time(t_stat s_stat, int *flags);
void					print_time_str(time_t secs);

int						ft_errors(int code, char *error);
int						ft_error_flag(char *arg);
int						ft_error_print(char *arg);
int						ft_error_dir(char *arg);
int						ft_error_file(char *arg);

void					ft_dir_cleans(t_info dirs[]);
#endif
