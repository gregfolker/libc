#include <stddef.h>

#include "types.h"

UINT MaxValue(size_t byte_count)
{
   UINT ret_val = 0;

   for (int byte = 0; byte < BYTES_IN_UINT; byte++)
   {
      ret_val |= (MAX_BYTE << (byte * BITS_IN_BYTE));
   }

   return ret_val;
}
