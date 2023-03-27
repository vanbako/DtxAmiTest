#ifndef DTXAPP_H
#define DTXAPP_H

#include "DtxWindow.h"

#define smDtxApp_MaxDtxWindows 10;

struct DtxApp
{
    ULONG mDtxWindowCount;
	struct DtxWindow mDtxWindows[10];
};

DtxBool DtxApp_Construct(struct DtxApp *this);
void DtxApp_Destruct(struct DtxApp *this);
struct DtxWindow *DtxApp_AddWindow(struct DtxApp *this, char* title);
void DtxApp_Loop(struct DtxApp *this);

#endif
