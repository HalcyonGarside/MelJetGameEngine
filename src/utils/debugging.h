#ifndef MJ_DEBUGGING
#define MJ_DEBUGGING

#ifdef DBG_VERBOSE
#define PRINT_ERROR(msg) printf("%s::%d: %s\n", __FILE__, __LINE__, msg);
#else
#define PRINT_ERROR(msg)
#endif

#endif