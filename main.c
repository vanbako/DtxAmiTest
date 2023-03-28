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
	struct DtxRect dtxRect;
	DtxRect_Construct(&dtxRect, 20, 20, 400, 300);
	struct DtxWindow *pWindow1 = DtxApp_AddWindow_Rect(&gDtxApp, "DtxWindow1", dtxRect);
	dtxRect.mLeft += 10;
	dtxRect.mTop += 10;
	struct DtxWindow *pWindow2 = DtxApp_AddWindow_Rect(&gDtxApp, "DtxWindow2", dtxRect);
	dtxRect.mLeft += 10;
	dtxRect.mTop += 10;
	struct DtxWindow *pWindow3 = DtxApp_AddWindow_Rect(&gDtxApp, "DtxWindow3", dtxRect);
	DtxRect_Destruct(&dtxRect);
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
