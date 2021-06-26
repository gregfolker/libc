#ifndef DUMP_H
#define DUMP_H

/*
 * Prototypes
 */
BYTE BinaryDumpByte(BYTE val, char *sep);
UINT16 BinaryDumpUint16(UINT16 val, char *sep);
UINT32 BinaryDumpUint32(UINT32 val, char *sep);
UINT64 BinaryDumpUint64(UINT64 val, char *sep);

#endif /* DUMP_H */
