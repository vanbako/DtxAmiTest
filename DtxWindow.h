#ifndef DTXWINDOW_H
#define DTXWINDOW_H

#include "DtxMacros.h"
#include <clib/intuition_protos.h>


struct DtxWindow
{
	struct Window *mpWindow;
};

DtxBool DtxWindow_Construct(struct DtxWindow *this, char* title);
void DtxWindow_Destruct(struct DtxWindow *this);
ULONG DtxWindow_GetSignalMask(struct DtxWindow *this);
//void DtxWindow_AddButtonGadget(struct DtxWindow *this);

#endif
