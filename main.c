#include "DtxLibs.h"
#include "DtxApp.h"

struct DtxLibs gDtxLibs;
struct DtxApp gDtxApp;

DtxBool Init()
{
	if (DtxLibs_Construct(&gDtxLibs) != DtxTrue)
		return DtxFalse;
	if (DtxApp_Construct(&gDtxApp) != DtxTrue)
		return DtxFalse;
	struct DtxWindow *pWindow1 = DtxApp_AddWindow(&gDtxApp, "DtxWindow1");
	struct DtxWindow *pWindow2 = DtxApp_AddWindow(&gDtxApp, "DtxWindow2");
	struct DtxWindow *pWindow3 = DtxApp_AddWindow(&gDtxApp, "DtxWindow3");
	//DtxWindow_AddButtonGadget(pWindow3);
	DtxApp_Loop(&gDtxApp);
	return DtxTrue;
}

void CleanUp()
{
	DtxApp_Destruct(&gDtxApp);
	DtxLibs_Destruct(&gDtxLibs);
}

int main(int argc, char **argv)
{
	DtxBool isOk = Init();
	CleanUp();
	if (isOk == DtxTrue)
		return 0;
	else
		return -1;
}
