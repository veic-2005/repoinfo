// dllmain.h : Declaration of module class.

class CrepoInfoModule : public CAtlDllModuleT< CrepoInfoModule >
{
public :
	DECLARE_LIBID(LIBID_repoInfoLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_REPOINFO, "{988058AB-5FCC-4A17-8247-B015F4BCB4FE}")
};

extern class CrepoInfoModule _AtlModule;
