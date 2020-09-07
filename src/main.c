#include "args_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "jsmn.h"
#include "type.h"
#include "ioutil.h"

int main(int argc, char **argv)
{
	struct Args args;
	int valid = parse_args(&argc, argv, &args);
	if (!valid) 
	{
		printf("required at least one argument\n");
		exit(1);
	}

	printf("fileName : %s\n", args.fileName);

	FILE *file;
	char *text;
	file = fopen(args.fileName, "r");
	if (!file)
	{
		printf("file not exist\n");
		exit(1);
	}

	// while ((nread = fread(buffer, 1, sizeof buffer, file)) > 0)
	// {
	// 	fwrite(buffer, 1, nread, text);
	// 	if (ferror(file)) 
	// 	{
	// 		printf("error reading file\n");
	// 		exit(1);
	// 	}
	// }

	// ------------------------------------------

	// fseek(file, 0, SEEK_END);
	// long fsize = ftell(file);
	// fseek(file, 0, SEEK_SET);

	// text = malloc(fsize + 1);

	// fread(text, 1, fsize, file);

	// fclose(file);

	// text[fsize] = 0;
	
	//printf("file size %ld\n", fsize);
	//printf("%s", text);
	// ------------------------------------------

	char *dataptr;
	size_t sizeptr;

	int success = read_all(file, &dataptr, &sizeptr);
	printf("%d\n", success);
	if (success != READALL_OK) 
	{
		printf("error reading file\n");
		exit(-1);
	}

	// ------------------------------------------

	jsmn_parser parser;
	jsmn_init(&parser);

	jsmntok_t t[sizeptr];

	unsigned num_token = sizeof(t) / sizeof(t[0]);
	printf("size of token %d\n", num_token);

	int r = jsmn_parse(&parser, dataptr, sizeptr, t, num_token);
	if (r < 0)
	{
		printf("error parsing json\n");
		exit(-1);
	}

	for (int i = 0; i < r; i++)
	{
		printf("start=%u, end=%u, size=%u, type=%u\n", t[i].start, t[i].end, t[i].size, t[i].type);
	}

	return 0;
}
