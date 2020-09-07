#ifndef HEADER_ARGS_PARSER_H
#define HEADER_ARGS_PARSER_H

#define VERSION "v1.0.0"

struct  Args
{
    char *fileName;
};


void show_version();
void show_help();
int parse_args(const int *argc, char **argv, struct Args *args);

#endif