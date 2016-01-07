#include <node.h>
#include <v8.h>

#include "src/main.cpp"

void Function(const v8::FunctionCallbackInfo<v8::Value>& args) {

    v8::Isolate* isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);

    args.GetReturnValue().Set(
            v8::String::NewFromUtf8(isolate, hmm())
    );
}

void init(v8::Local<v8::Object> target) {
    /**
     * sets the property main to the function Function
     */
    NODE_SET_METHOD(target, "main", Function);
}

NODE_MODULE(binding, init);