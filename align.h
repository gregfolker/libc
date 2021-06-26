#ifndef ALIGN_H
#define ALIGN_H

#include "types.h"

#define UINT16_ALIGNED(_val) ((_val % BYTES_IN_UINT16) ? false : true)
#define UINT32_ALIGNED(_val) ((_val % BYTES_IN_UINT32) ? false : true)
#define UINT64_ALIGNED(_val) ((_val % BYTES_IN_UINT64) ? false : true)

#endif /* ALIGN_H */
