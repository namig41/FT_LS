#include "ft_ls.h"

t_file 	*create_file(char *name, char *full_path, t_stat *stat)
{
    t_file *node;

    if (!(node = (t_file *)ft_memalloc(sizeof(t_file))))
        return (NULL);
    node->name = ft_strdup(name);
    node->mode = stat->st_mode;
    node->size = stat->st_size;
    node->st_blocks = stat->st_blocks;
    node->st_gid = stat->st_gid;
    node->st_uid = stat->st_uid;
    node->st_rdev = stat->st_rdev;
    node->st_nlink = stat->st_nlink;
    node->time = stat->st_mtime;
    node->next = NULL;
    return (node);
}

void    append_file(t_file **files, t_file *file)
{
	t_file *head;

	if (!*files)
	{
		*files = file;
		return ;
	}
	head = *files;
	while (head->next)
		head = head->next;
	head->next = file;
}

void    init_files(char *name, t_file **files)
{
    DIR *dir;
    t_dirent *ent;
    t_stat s;
    t_file *file;

    if (dir = opendir(name))
    {
        while (ent = readdir(dir))
        {
           if (lstat(ft_strjoin(name, ent->d_name), &s) != -1)
           {
               file = create_file(ent->d_name, ent->d_name, &s);
               append_file(files, file);
           }
        }
        closedir(dir);
    } 
    else 
        ft_puterror("Error");
}
