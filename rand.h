#include "lib.h"

#define MAX_RAND_BYTE   RandByte(MAX_BYTE)
#define MAX_RAND_UINT   RandUint(MaxValue(BYTES_IN_UINT))
#define MAX_RAND_UINT16 RandUint16((UINT16)MaxValue(BYTES_IN_UINT16))
#define MAX_RAND_UINT32 RandUint32((UINT32)MaxValue(BYTES_IN_UINT32))
#define MAX_RAND_UINT64 RandUint64((UINT64)MaxValue(BYTES_IN_UINT64))

/*
 * Prototypes
 */
void SeedRNG(void);
BYTE RandByte(BYTE max_value);
UINT RandUint(UINT max_value);
UINT16 RandUint16(UINT16 max_value);
UINT32 RandUint32(UINT32 max_value);
UINT64 RandUint64(UINT64 max_value);
