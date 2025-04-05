#include "pch.h"
#using <C:\Users\Марк\source\repos\telebird\Debug\WTelegramClient.dll>

using namespace System;

void Init()
{
    //telebird_tg::Class1^ x = gcnew telebird_tg::Class1;
    //x->TEST();
    //delete x;
    
}

WTelegram::Client^* x;

WTelegram::Client^ client()
{
    if (x)
        return *x;
    return nullptr;
}

extern "C"
{
    __declspec(dllexport) void init()
    {
        

    }
    __declspec(dllexport) void loop()
    {

    }

    _declspec(dllexport) void release(void* x)
    {
        delete x;
    }

    _declspec(dllexport) int login(char* buf)
    {

    }
}

int main(array<System::String ^> ^args)
{
    
    return 0;
}
