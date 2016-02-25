#include <node.h>
#include <v8.h>
#include <nan.h>
#include <string>
#include "../src/lib.cpp"

using namespace v8;
using std::string;

void addNumbers(const FunctionCallbackInfo<Value>& info) {
    Isolate* isolate = info.GetIsolate();
    HandleScope scope(isolate);
    // needs 2 args
    if (info.Length() < 2) {
        return info.GetReturnValue().SetUndefined();
    }
    // get arguments
    double param = info[0]->NumberValue();
    double param2 = info[1]->NumberValue();
    // get return value
    // close out
    Local<Number> converted_result = Nan::New(param + param2);
    return info.GetReturnValue().Set(converted_result);
}

void stringIdentityFn(const FunctionCallbackInfo<Value>& info) {
    Isolate* isolate = info.GetIsolate();
    HandleScope scope(isolate);
    // needs one argument
    if (info.Length() < 1) {
        return info.GetReturnValue().SetUndefined();
    }
    // get arguments
    String::Utf8Value arg1(info[0]->ToString());
    string arg1_string = string(*arg1);
    // get functional return
    string return_string = stringIdentity(arg1_string);

    // close out
    Local<String> set_return = String::NewFromUtf8(isolate, return_string.c_str());
    info.GetReturnValue().Set(set_return);
}

void init(Local<Object> target) {
    NODE_SET_METHOD(target, "main", stringIdentityFn);
    NODE_SET_METHOD(target, "add", addNumbers);
}

NODE_MODULE(binding, init);