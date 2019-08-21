/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/21 12:24:21 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"


/* static void get_process_name(const pid_t pid, char * name) { */
/* 	char procfile[BUFSIZ]; */
/* 	sprintf(procfile, "/proc/%d/cmdline", pid); */
/* 	FILE* f = fopen(procfile, "r"); */
/* 	if (f) { */
/* 		size_t size; */
/* 		size = fread(name, sizeof (char), sizeof (procfile), f); */
/* 		if (size > 0) { */
/* 			if ('\n' == name[size - 1]) */
/* 				name[size - 1] = '\0'; */
/* 		} */
/* 		fclose(f); */
/* 	} */
/* } */

/**
 * Get the parent PID from a PID
 * @param pid pid
 * @param ppid parent process id
 *
 * Note: init is 1 and it has a parent id of 0.
 */

/* static void get_process_parent_id(const pid_t pid, pid_t * ppid) { */
/* 	char buffer[BUFSIZ]; */
/* 	sprintf(buffer, "/proc/%d/stat", pid); */
/* 	FILE* fp = fopen(buffer, "r"); */
/* 	if (fp) { */
/* 		size_t size = fread(buffer, sizeof (char), sizeof (buffer), fp); */
/* 		if (size > 0) { */
/* 			// See: http://man7.org/linux/man-pages/man5/proc.5.html section /proc/[pid]/stat */
/* 			strtok(buffer, " "); // (1) pid  %d */
/* 			strtok(NULL, " "); // (2) comm  %s */
/* 			strtok(NULL, " "); // (3) state  %c */
/* 			char * s_ppid = strtok(NULL, " "); // (4) ppid  %d */
/* 			*ppid = atoi(s_ppid); */
/* 		} */
/* 		fclose(fp); */
/* 	} */
/* } */


/* Your should get something like that:
 24090 - ./a.out
 24084 - bash
  2425 - bash
  1369 - /usr/bin/xfce4-terminal
 13056 - init
 12994 - lightdm
  1428 - lightdm
     1 - /sbin/initsession-child
*/



int	ft_terms(t_terms *terms)
{
	t_wins		wins;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins);
	terms->w_row = wins.ws_row;
	terms->w_col = wins.ws_col;
	return (0);
}

/* int	main() */
int	main(int argc, char **argv)
{

	t_flags		flags;
	t_info		dirs[1024];
	int			i;
	int			j;

	/* pid_t pid = getpid(); */
	/* while (pid != 0) */
	/* { */
	/* 	char name[BUFSIZ]; */
	/* 	get_process_name(pid, name); */
	/* 	printf("%6d - %s\n", pid, name); */
	/* 	get_process_parent_id(pid, & pid); */
	/* } */









	/* t_terms		terms; */
	/* ft_terms(&terms); */
	/* ft_putstr("rows:		"); */
	/* ft_putnbr(terms.w_row); */
	/* ft_putchar('\n'); */
	/* ft_putstr("cols:		"); */
	/* ft_putnbr(terms.w_col); */
	/* ft_putchar('\n'); */


	i = 0;
	F(!(flags = 0), B_1(flags, F_1));
	F_((i = ft_flags(&flags, argv)) == E_FLAGS, errno);
	F(argc - i > 1, flags |= F_M);
	
	/* ft_flag_print(&flags); */
	/* ft_putendl(""); */
	/* ft_putendl("v"); */
	
	j = i - 1;
	F_(!argv[i], ft_dirs(&flags, dirs, "."));
	___(argv[++j], F(!(ft_dir_check(argv[j])), ft_errors(E_PRINTS, argv[j])));
	j = i - 1;
	___(argv[++j], F(ft_dir_check(argv[j]), ft_dirs(&flags, dirs, argv[j])));

	return (0);
}
