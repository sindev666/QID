// dllmain.h : Declaration of module class.

class CTeleClientModule : public ATL::CAtlDllModuleT< CTeleClientModule >
{
public :
	DECLARE_LIBID(LIBID_TeleClientLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TELECLIENT, "{45044d1b-9ae6-45f1-86b6-426280cf3e3f}")
};

extern class CTeleClientModule _AtlModule;
