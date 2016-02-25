#include <node.h>
#include <v8.h>
#include <nan.h>
#include <string>
#include "../src/lib.cpp"

using namespace v8;
using std::string;

void constFunction(const FunctionCallbackInfo<Value>& info) {

    Isolate* isolate = info.GetIsolate();
    HandleScope scope(isolate);

    info.GetReturnValue().Set(
        String::NewFromUtf8(isolate, hmm())
    );
}

void singleParamFunction(const FunctionCallbackInfo<Value>& info) {

    Isolate* isolate = info.GetIsolate();
    HandleScope scope(isolate);

    if (info.Length() < 2) {
        return info.GetReturnValue().SetUndefined();
    }

//    Local<String> param = info[0]->ToString();
//    String::Utf8Value pre_conversion(param);
//    string result = appendString(string(*pre_conversion));
//    Local<String> converted_result = Nan::New(result);

    double param = info[0]->NumberValue();
    double param2 = info[1]->NumberValue();
    Local<Number> converted_result = Nan::New(param + param2);

    return info.GetReturnValue().Set(converted_result);
}

void init(Local<Object> target) {
    NODE_SET_METHOD(target, "main", constFunction);
    NODE_SET_METHOD(target, "sub", singleParamFunction);
}

NODE_MODULE(binding, init);