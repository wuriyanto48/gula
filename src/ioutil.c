#include "ioutil.h"

#include <stdio.h>
#include <stdlib.h>

int read_all(FILE *in, char **dataptr, size_t *sizeptr) {

    char *data = NULL, *temp;
    size_t size = 0, used = 0, n;

    if (in == NULL || dataptr == NULL || sizeptr == NULL) 
    {
        return READALL_INVALID;
    }
    
    // read error already occured
    if (ferror(in)) 
    {
        return READALL_ERROR;
    }

    while (!0)
    {
        if ((used + READALL_CHUNK + 1) > 1) {
            size = used + READALL_CHUNK + 1;

            /* Overflow check. Some ANSI C compilers
               may optimize this away, though. */
            if (size <= used) 
            {
                free(data);
                return READALL_TOOMUCH;
            }

            temp = realloc(data, size);
            if (temp == NULL) 
            {
                free(data);
                return READALL_NOMEM;
            }

            data = temp;
        }

        n = fread(data + used, 1, READALL_CHUNK, in);
        if (n == 0)
        {
            break;
        }

        used += n;
    }

    if (ferror(in)) 
    {
        free(data);
        return READALL_ERROR;
    }

    temp = realloc(data, used + 1);
    if (temp == NULL)
    {
        free(data);
        return READALL_NOMEM;
    }

    data = temp;
    data[used] = 0;

    *dataptr = data;
    *sizeptr = used;
    
    return READALL_OK;
}