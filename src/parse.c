#include "ft_ls.h"

void 	parse_flags(int *argc, char **argv[])
{
    size_t i;
    size_t j;
    int offset;

    i = 1;
    offset = 0;
    while (i < *argc && (*argv)[i][0] == '-')
    {
        j = 1;
        while (*argv[i][j] && (offset = ft_strchri(LS_FLAGS, *argv[i][1])) != -1)
        {
            g_f |= (1 << offset);
            j++;
        }
        i++;
    }
    *argc -= i;
    *argv += i;
}

void     parse_files(int argc, char **argv, t_file **files)
{
    size_t i;

    i = 0;
    if (!*argv)
    {
        init_files(".", files);
    }
    else 
    {
        while (i < argc)
        {
            init_files(argv[i], files);
            i++;
        }
    }
    print_files(*files);
}
