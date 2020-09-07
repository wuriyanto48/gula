#ifndef HEADER_IO_H
#define HEADER_IO_H

#include <stdio.h>
#include <stdlib.h>

/* Size of each input chunk to be
   read and allocate for. */

#ifndef READALL_CHUNK
#define READALL_CHUNK 262144 
#endif

#define READALL_OK 0 /* Success */
#define READALL_INVALID -1 /* Invalid parameters */
#define READALL_ERROR -2 /* Stream error */
#define READALL_TOOMUCH -3 /* To many input */
#define READALL_NOMEM -4 /* Out if memory */


int read_all(FILE *in, char **dataptr, size_t *sizeptr);

#endif