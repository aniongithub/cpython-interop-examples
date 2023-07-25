from capi import *

CONTEXT_VAL = { "foo": "bar" }
CONTEXT_VALSIZEBYTES = sizeof(c_void_p)

@HandleCallbackFuncType
def handleCallback(context, contextSizeBytes, handle) -> Result:
    assert(contextSizeBytes == CONTEXT_VALSIZEBYTES)
    
    ctx = ctypes.cast(context, ctypes.py_object).value
    assert(ctx == CONTEXT_VAL)
    
    print("Handle callback called!")
    return OK

handle = Handle()
params = HandleParams()
params.context = id(CONTEXT_VAL)
params.contextSizeBytes = CONTEXT_VALSIZEBYTES
params.handleCallbackFunc = handleCallback

assert(createHandle(params, byref(handle)) == OK)
assert(doHandleThing(handle) == OK)
assert(destroyHandle(handle) == OK)