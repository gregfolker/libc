#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "types.h"
#include "print.h"
#include "mem.h"

static char *_UintToBinaryString(UINT val, UINT total_bits, char *sep, UINT *ret_val)
{
   char *binary;
   BYTE bit_count = 0;
   UINT msbit;

   msbit = MSBit(total_bits);

   FPRINTF_DEBUG("val=0x%08lX, bits=%lu, msbit=%lu\n\n", val, total_bits, msbit);

   binary = (char *)xmalloc(total_bits);

   for (UINT bit = msbit; bit > 0; bit >>= 1)
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

   strcat(binary, "\n");
   return binary;
}

BYTE BinaryDumpByte(BYTE val, char *sep)
{
   char *binary;
   BYTE ret_val = 0;

   binary = _UintToBinaryString((UINT)val, BITS_IN_BYTE, sep, (UINT *)&ret_val);

   Print(binary);

   free(binary);

   return ret_val;
}


UINT16 BinaryDumpUint16(UINT16 val, char *sep)
{
   char *binary;
   UINT16 ret_val = 0;

   binary = _UintToBinaryString((UINT)val, BITS_IN_UINT16, sep, (UINT *)&ret_val);

   Print(binary);

   free(binary);

   return ret_val;
}

UINT32 BinaryDumpUint32(UINT32 val, char *sep)
{
   char *binary;
   UINT32 ret_val = 0;

   binary = _UintToBinaryString((UINT)val, BITS_IN_UINT32, sep, (UINT *)&ret_val);

   Print(binary);

   free(binary);

   return ret_val;
}

UINT64 BinaryDumpUint64(UINT64 val, char *sep)
{
   char *binary;
   UINT64 ret_val = 0;

   binary = _UintToBinaryString((UINT)val, BITS_IN_UINT64, sep, (UINT *)&ret_val);

   Print(binary);

   free(binary);

   return ret_val;
}
