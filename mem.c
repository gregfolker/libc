#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "print.h"

void *xmalloc(size_t size)
{
   void *ptr = malloc(size);

   assert(ptr);

   memset(ptr, 0, size);

   return ptr;
}

