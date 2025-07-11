// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "TeleClient_i.h"
#include "dllmain.h"

CTeleClientModule _AtlModule;

class CTeleClientApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CTeleClientApp, CWinApp)
END_MESSAGE_MAP()

CTeleClientApp theApp;

BOOL CTeleClientApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CTeleClientApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
