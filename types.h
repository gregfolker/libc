#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

enum t_typename
{
   TYPENAME_BOOL,
   TYPENAME_UNSIGNED_CHAR,
   TYPENAME_CHAR,
   TYPENAME_SIGNED_CHAR,
   TYPENAME_SHORT_INT,
   TYPENAME_UNSIGNED_SHORT_INT,
   TYPENAME_INT,
   TYPENAME_UNSIGNED_INT,
   TYPENAME_LONG_INT,
   TYPENAME_UNSIGNED_LONG_INT,
   TYPENAME_LONG_LONG_INT,
   TYPENAME_UNSIGNED_LONG_LONG_INT,
   TYPENAME_FLOAT,
   TYPENAME_DOUBLE,
   TYPENAME_LONG_DOUBLE,
   TYPENAME_POINTER_TO_CHAR,
   TYPENAME_POINTER_TO_VOID,
   TYPENAME_POINTER_TO_INT,
   TYPENAME_UNKNOWN
};

#define typename(x) _Generic((x),                                                                         \
            _Bool: TYPENAME_BOOL,                        unsigned char: TYPENAME_UNSIGNED_CHAR,           \
             char: TYPENAME_CHAR,                          signed char: TYPENAME_SIGNED_CHAR,             \
        short int: TYPENAME_SHORT_INT,              unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,      \
              int: TYPENAME_INT,                          unsigned int: TYPENAME_UNSIGNED_INT,            \
         long int: TYPENAME_LONG_INT,                unsigned long int: TYPENAME_UNSIGNED_LONG_INT,       \
    long long int: TYPENAME_LONG_LONG_INT,      unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT,  \
            float: TYPENAME_FLOAT,                              double: TYPENAME_DOUBLE,                  \
      long double: TYPENAME_LONG_DOUBLE,                        char *: TYPENAME_POINTER_TO_CHAR,         \
           void *: TYPENAME_POINTER_TO_VOID,                     int *: TYPENAME_POINTER_TO_INT,          \
          default: TYPENAME_UNKNOWN)

#define BYTE   uint8_t
#define UINT   uintmax_t
#define UINT16 uint16_t
#define UINT32 uint32_t
#define UINT64 uint64_t

#define BYTES_IN_UINT    sizeof(uintmax_t)
#define BYTES_IN_UINT8   sizeof(uint8_t)
#define BYTES_IN_UINT16  sizeof(uint16_t)
#define BYTES_IN_UINT32  sizeof(uint32_t)
#define BYTES_IN_UINT64  sizeof(uint64_t)

#define BITS_IN_BYTE   8
#define BITS_IN_UINT   (BYTES_IN_UINT    * BITS_IN_BYTE)
#define BITS_IN_UINT16 (BYTES_IN_UINT16  * BITS_IN_BYTE)
#define BITS_IN_UINT32 (BYTES_IN_UINT32  * BITS_IN_BYTE)
#define BITS_IN_UINT64 (BYTES_IN_UINT64  * BITS_IN_BYTE)

#define NUM_ARRAY_ELEMENTS(_x) (sizeof(_x) / sizeof(_x[0]))

#define BIT_SHIFT(_x, _n)  (_x << _n)
#define BYTE_SHIFT(_x, _n) (_x << (_n * BITS_IN_BYTE))

#define MAX_BYTE   0xFF

#define MSBYTE_MASK_BYTE   MAX_BYTE
#define MSBYTE_MASK_UINT16 BYTE_SHIFT(MAX_BYTE, BYTES_IN_UINT16 - 1)
#define MSBYTE_MASK_UINT32 BYTE_SHIFT(MAX_BYTE, BYTES_IN_UINT32 - 1)
#define MSBYTE_MASK_UINT64 BYTE_SHIFT(MAX_BYTE, BYTES_IN_UINT64 - 1)

#define MSBIT_OF_BYTE   (BYTE)BIT_SHIFT(1, (BITS_IN_BYTE - 1))
#define MSBIT_OF_UINT16 (UINT16)BIT_SHIFT(1, (BITS_IN_UINT16 - 1))
#define MSBIT_OF_UINT32 (UINT32)BIT_SHIFT(1, (BITS_IN_UINT32 - 1))
#define MSBIT_OF_UINT64 (UINT64)BIT_SHIFT(1UL, (BITS_IN_UINT64 - 1))

#define KILOBYTE pow(10, 3)
#define MEGABYTE pow(10, 6)
#define GIGABYTE pow(10, 9)

#define KIBIBYTE (2 << 10)
#define MEBIBYTE (2 << 20)
#define GIBIBYTE (2 << 30)

/*
 * Protoypes
 */
UINT MSBit(UINT total_bits);
const char *TypeToAscii(enum t_typename type);
