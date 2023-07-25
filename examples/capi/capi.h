#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define CONST_STRING const char*

#ifdef __cplusplus
    #define EXPORT_API extern "C" __attribute__((visibility("default")))
  #else
    #define EXPORT_API __attribute__((visibility("default")))
#endif

enum Result_t
{
    INVALID_ARGS = -3,
    NOT_IMPLEMENTED = -2,
    UNKNOWN_ERROR = -1,
    OK = 0
};
typedef enum Result_t Result;

struct Handle_t;
typedef struct Handle_t* Handle;

enum CallbackType_t
{
    HANDLE_CREATED,
    HANDLE_DESTROYED
};

typedef Result (*HandleCallbackFunc)(void* context, size_t contextSizeBytes, Handle handle);

struct HandleParams_t
{
    char* name;
    size_t nameSizeBytes;
    void* context;
    size_t contextSizeBytes;

    HandleCallbackFunc handleCallbackFunc;
};
typedef struct HandleParams_t HandleParams;

EXPORT_API Result createHandle(HandleParams params, Handle* handle);
EXPORT_API Result doHandleThing(Handle handle);
EXPORT_API Result destroyHandle(Handle handle);