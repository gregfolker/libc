#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "types.h"
#include "lib.h"

void SeedRNG(void)
{
   struct timeval t;
   gettimeofday(&t, NULL);
   srand(t.tv_usec * t.tv_sec);
}

BYTE RandByte(BYTE max_value)
{
   return (rand() % max_value);
}

UINT RandUint(UINT max_value)
{
   return (rand() % max_value);
}

UINT16 RandUint16(UINT16 max_value)
{
   return (rand() % max_value);
}

UINT32 RandUint32(UINT32 max_value)
{
   return (rand() % max_value);
}

UINT64 RandUint64(UINT64 max_value)
{
   return (rand() % max_value);
}
