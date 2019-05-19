#include <nan.h>
#include "testworker.h"

NAN_METHOD(addThousandToNumber) {
	auto number = Nan::To<int>(info[0]).FromJust();
	auto* callback = new Nan::Callback(info[1].As<v8::Function>());

	Nan::AsyncQueueWorker(new TestWorker(number, callback));

}

NAN_MODULE_INIT(init) {
	Nan::SetMethod(target, "addThousandToNumber", addThousandToNumber);
}

NODE_MODULE(testlib, init);