// JS2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "quickjs.h"

JSValue get_chats(JSContext* ctx, JSValue th, int argc,JSValue*argv)
{
    int x;
    JS_ToInt32(ctx, &x, argv[0]);
    JSValue lst[] = { JS_NewInt32(ctx,x * 2 - 1), JS_DupValue(ctx,argv[0]) };
    JSValue ret = JS_NewArrayFrom(ctx, 2, lst);
    return ret;
}

int main()
{
    std::cout << "Hello World!\n";
    JSRuntime* rt = JS_NewRuntime();
    JSContext* ctx = JS_NewContext(rt);
    JS_SetMemoryLimit(rt, 1024 * 1024);
    JS_NewCFunction(ctx, get_chats, "lol", -1);
    JSCFunction exmpl;
    JS_AddIntrinsicEval(ctx);
    const char* s = "std.loadScript(\"repl.js\")";
    JS_Eval(ctx, s, strlen(s), "lol", 0);
    JS_FreeContext(ctx);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
