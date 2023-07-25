#include "capi.h"

struct Handle_t
{
    private:
        void* impl;
        HandleParams params;
    public:
        Handle_t() = delete;
        Handle_t(const Handle_t&) = delete;
        Handle_t(HandleParams params):
            params(params),
            impl(nullptr) // for now
        {}
        const HandleParams& getParams() { return params; }
};

Result createHandle(HandleParams params, Handle* handle) 
{
    *handle = new Handle_t(params);
    return Result::OK;
}

Result doHandleThing(Handle handle)
{
    int errCode = 0;
    handle->getParams().handleCallbackFunc(
        handle->getParams().context, 
        handle->getParams().contextSizeBytes,
        handle);
    
    return Result::OK;
}

Result destroyHandle(Handle handle) 
{
    if (!handle)
        return Result::INVALID_ARGS;
    
    delete handle;
    return Result::OK;
}