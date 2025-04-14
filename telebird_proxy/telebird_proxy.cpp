#include "pch.h"

using namespace System;

extern "C"
{
    __declspec(dllexport) void* CreateClassObject()
    {
        void* ptr = (void*)System::Runtime::InteropServices::Marshal::GetComInterfaceForObject(gcnew test2::A(), test2::IPlugin::typeid);
        return ptr;
    }
}

int main(array<System::String ^> ^args)
{
    test2::A^ gt = gcnew test2::A();
    return 0;
}
