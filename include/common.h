#include "global.h"
#include "fault.h"
#include "n64dd.h"
#include "n64dd_internal.h"
#include "ultra64/leo_internal.h"

// For -g bss...
#define EXPAND2(a, b) a##b
#define EXPAND(a, b) EXPAND2(a, b)
#define DUMMY_STRUCT struct EXPAND(dummy, __LINE__);
