#include "ft_ls.h"
#include <stdio.h>

void 	print_files(t_file *files)
{
    while (files)
    {
        printf("%s\n", files->name);
        files = files->next;
    }
}

