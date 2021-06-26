#include "types.h"

UINT MSBit(UINT total_bits)
{
   switch (total_bits)
   {
      case BITS_IN_BYTE:
         return (UINT)(MSBIT_OF_BYTE);
      case BITS_IN_UINT16:
         return (UINT)(MSBIT_OF_UINT16);
      case BITS_IN_UINT32:
         return (UINT)(MSBIT_OF_UINT32);
      case BITS_IN_UINT64:
         return (UINT)(MSBIT_OF_UINT64);
   }

   return 0;
}

const char *TypeToAscii(enum t_typename type)
{
   switch (type)
   {
      case TYPENAME_BOOL:
         return "_Bool";
      case TYPENAME_UNSIGNED_CHAR:
         return "unsigned char";
      case TYPENAME_CHAR:
         return "char";
      case TYPENAME_SIGNED_CHAR:
         return "signed char";
      case TYPENAME_SHORT_INT:
         return "short int";
      case TYPENAME_UNSIGNED_SHORT_INT:
         return "unsigned short int";
      case TYPENAME_INT:
         return "int";
      case TYPENAME_UNSIGNED_INT:
         return "unsigned int";
      case TYPENAME_LONG_INT:
         return "long int";
      case TYPENAME_UNSIGNED_LONG_INT:
         return "unsigned long int";
      case TYPENAME_LONG_LONG_INT:
         return "long long int";
      case TYPENAME_UNSIGNED_LONG_LONG_INT:
         return "unsigned long long int";
      case TYPENAME_FLOAT:
         return "float";
      case TYPENAME_DOUBLE:
         return "double";
      case TYPENAME_LONG_DOUBLE:
         return "long double";
      case TYPENAME_POINTER_TO_CHAR:
         return "char*";
      case TYPENAME_POINTER_TO_VOID:
         return "void*";
      case TYPENAME_POINTER_TO_INT:
         return "int*";
      case TYPENAME_UNKNOWN:
         return "unknown";
   }
}
