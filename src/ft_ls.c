#include "ft_ls.h"

int main(int argc, char *argv[])
{
    t_file *files;

    parse_flags(&argc, &argv);

    parse_files(argc, argv, &files);

    return (0);
}
