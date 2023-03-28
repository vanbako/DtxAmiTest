#ifndef DTXWINDOW_H
#define DTXWINDOW_H

#include "DtxMacros.h"
#include "DtxRect.h"
#include "DtxSize.h"
#include <clib/intuition_protos.h>


struct DtxWindow
{
	struct Window *mpWindow;
};

DtxBool DtxWindow_Construct(struct DtxWindow *this, char* title, struct DtxRect dtxRect, struct DtxSize dtxMinSize, struct DtxSize dtxMaxSize);
void DtxWindow_Destruct(struct DtxWindow *this);
ULONG DtxWindow_GetSignalMask(struct DtxWindow *this);
//void DtxWindow_AddButtonGadget(struct DtxWindow *this);

#endif
