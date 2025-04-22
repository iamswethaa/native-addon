#include <node_api.h>
#include <stdio.h>

//C function
int add(int a, int b) {
    printf("add(%d, %d) called\n", a, b); // For debug
    return a + b;
}

// N-API wrapper function
napi_value AddWrapped(napi_env env, napi_callback_info info) {
    napi_status status;

    size_t argc = 2;
    napi_value args[2];
    status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
    if (status != napi_ok) return NULL;

    int32_t a, b;
    napi_get_value_int32(env, args[0], &a);
    napi_get_value_int32(env, args[1], &b);

    int result = add(a, b);

    napi_value resultValue;
    napi_create_int32(env, result, &resultValue);
    return resultValue;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_value fn;
    napi_create_function(env, NULL, 0, AddWrapped, NULL, &fn);
    napi_set_named_property(env, exports, "add", fn);
    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)