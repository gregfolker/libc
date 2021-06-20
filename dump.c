#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "types.h"

static void _UintToBinaryString(UINT val, UINT start_bit, char *sep, char *binary, UINT *ret_val)
{
   BYTE bit_count = 0;

   for (UINT bit = (UINT32)start_bit; bit > 0; bit >>= 1)
   {
      strcat(binary, ((val & bit) == bit) ? "1" : "0");

      if (ret_val)
      {
         *ret_val |= (val & bit);
      }

      /*
       * Break out early if we are done in order to avoid appending a non-empty
       * separator to the constructed string
       */
      if (bit == 1)
      {
         strcat(binary, "\n");
         break;
      }

      /*
       * Do not add separators if one was not specified
       */
      if (sep == NULL)
      {
         continue;
      }

      bit_count += 1;

      /*
       * Add the separator for every 8-bits that are appended to the string
       */
      if (bit_count == BITS_IN_BYTE)
      {
         strcat(binary, sep);
         bit_count = 0;
      }
   }
}

UINT32 BinaryDumpUint32(FILE *fd, UINT32 val, char *sep)
{
   char binary[BITS_IN_UINT32];
   UINT32 ret_val = 0;

   memset(binary, '\0', BITS_IN_UINT32);

   _UintToBinaryString((UINT)val, (1 << (BITS_IN_UINT32 - 1)), sep, binary, (UINT *)&ret_val);

   fputs(binary, fd);

   return ret_val;
}
