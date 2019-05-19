#include <node.h>
#include <CreateWindow.h>

using namespace v8;

void Create(const FunctionCallbackInfo <Value> &args) {
    Isolate *isolate = args.GetIsolate();

    bool created = GenWindow();

    Local <Boolean> bln = Boolean::New(isolate, created);
    args.GetReturnValue().Set(bln);
}

void BG(const FunctionCallbackInfo <Value> &args) {
    Isolate *isolate = args.GetIsolate();

    switch (args.Length()) {
        case 1:
            SetBG((int)args[0]->NumberValue(), (int)args[0]->NumberValue(), (int)args[0]->NumberValue());
            break;
        case 3:
            SetBG((int)args[0]->NumberValue(), (int)args[1]->NumberValue(), (int)args[2]->NumberValue());
            break;
    }

}
void init(Local <Object> exports) {
    NODE_SET_METHOD(exports, "create", Create);
    NODE_SET_METHOD(exports, "background", BG);
}

NODE_MODULE(node_gui, init)