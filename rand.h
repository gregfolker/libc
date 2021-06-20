#include "lib.h"

#define RandByteMax()   RandByte((BYTE)MaxValue(1))
#define RandUintMax()   RandByte(MaxValue(BYTES_IN_UINT))
#define RandUint16Max() RandByte((UINT16)MaxValue(BYTES_IN_UINT16))
#define RandUint32Max() RandUint32((UINT32)MaxValue(BYTES_IN_UINT32))
#define RandUint64Max() RandUint64((UINT64)MaxValue(BYTES_IN_U64))

/*
 * Prototypes
 */
void SeedRNG(void);
BYTE RandByte(BYTE max_value);
UINT RandUint(UINT max_value);
UINT16 RandUint16(UINT16 max_value);
UINT32 RandUint32(UINT32 max_value);
UINT64 RandUint64(UINT64 max_value);
