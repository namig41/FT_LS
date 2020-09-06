/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:42:11 by jbloodax          #+#    #+#             */
/*   Updated: 2020/08/03 13:42:44 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>

# define LS_A	(1 << 0) // выдавать все файлы в каталогах, включая скрытые файлы, начинающиеся с точки.
# define LS_L	(1 << 1) // выдавать один файл на строку
# define LS_RR	(1 << 2) // рекурсивно выдавать список содержимого всех каталогов
# define LS_R	(1 << 3) // сортировать содержимое каталога в обратном порядке
# define LS_T	(1 << 4) // сортировать по времени последней модификации (поле `mtime' в inode)
# define LS_D	(1 << 5) // выдавать имена каталогов, как будто они обычные файлы, вместо того, чтобы показывать их содержимое
# define LS_G	(1 << 6) // не отображать информацию о группе в длинном формате вывода
# define LS_ONE (1 << 7) // выдавать один файл на строку
# define LS_SS	(1 << 8) // производить сортировку по размеру файла, вместо сортировки по алфавиту
# define LS_S	(1 << 9) // выдавать размер каждого файла в блоках по 1024 байта слева от имени файла

# define LS_FLAGS "alRrtdG1Ss"

typedef struct stat		t_stat;
typedef struct dirent 	t_dirent;

typedef enum 			e_sort
{
	SORT_ASCII, 
	SORT_TIME, 
	SORT_SIZE, 
	SORT_REVERSE
}						t_sort;

typedef struct			s_file
{
	blkcnt_t			st_blocks;
	mode_t				mode;
	nlink_t				st_nlink;
	uid_t				st_uid;
	gid_t				st_gid;
	off_t				size;
	dev_t				st_rdev;
	time_t				time;
	long				ntime;
	char				*name;
	char				full_path[PATH_MAX];
	struct s_file		*next;
}						t_file;

t_ui 					g_f;


/* ------------------------ PARSE -----------------------------------*/

void 	parse_flags(int *argc, char **argv[]);
void 	parse_files(int argc, char *argv[], t_file **files);

/* ------------------------ ERROR ------------------------------------*/

/* ------------------------ SORT -------------------------------------*/

void 	sort_switch(t_file **files);
void 	sort_time(t_file **files);
void 	sort_ascii(t_file **files);
void 	sort_size(t_file **files);
void 	sort_reverse(t_file **files);

/* ------------------------ PRINT -------------------------------------*/

void 	print_files(t_file *files);

/* ------------------------ LIST --------------------------------------*/

t_file 	*create_file(char *name, char *full_path, t_stat *stat);
void 	init_files(char *name, t_file **files);
void 	append_file(t_file **files, t_file *file);

#endif
