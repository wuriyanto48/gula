#include "args_parser.h"
#include "type.h"
#include <stdio.h>

void show_version()
{
    printf("gula version %s\n", VERSION);
}

void show_help()
{
    printf("----- gula usage -----\n");
    printf("\t--help (show help)\n");
    printf("\t--version (show version)\n");
}

int parse_args(const int *argc, char **argv, struct Args *args)
{
    if (*argc == 1)
    {
        show_help();
        return FALSE;
    }

    args->fileName = argv[1];

    return TRUE;
}