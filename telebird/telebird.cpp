#include "pch.h"
#using <C:\Users\Марк\source\repos\telebird\Debug\WTelegramClient.dll>

using namespace System;

void Init()
{
    //telebird_tg::Class1^ x = gcnew telebird_tg::Class1;
    //x->TEST();
    //delete x;
    WTelegram::Client^ cl;
    
}

extern "C"
{
    __declspec(dllexport) void init()
    {
    }
    __declspec(dllexport) void loop()
    {

    }
}

int main(array<System::String ^> ^args)
{
    
    return 0;
}
