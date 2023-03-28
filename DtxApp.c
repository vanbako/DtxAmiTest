#include "DtxApp.h"
#include <clib/exec_protos.h>

DtxBool DtxApp_Construct(struct DtxApp *this)
{
	this->mDtxWindowCount = 0;
    return DtxTrue;
}

void DtxApp_Destruct(struct DtxApp *this)
{
    for (ULONG i = 0; i < this->mDtxWindowCount; ++i)
        DtxWindow_Destruct(&this->mDtxWindows[i]);
}

struct DtxWindow *DtxApp_AddWindow_Rect_MinMaxSize(struct DtxApp *this, char* title, struct DtxRect dtxRect, struct DtxSize dtxMinSize, struct DtxSize dtxMaxSize)
{
    if (this->mDtxWindowCount >= 10)
        return NULL;
    struct DtxWindow *pDtxWindow = &(this->mDtxWindows[this->mDtxWindowCount]);
    if (DtxWindow_Construct(pDtxWindow, title, dtxRect, dtxMinSize, dtxMaxSize) != DtxTrue)
        return NULL;
    ++(this->mDtxWindowCount);
    return pDtxWindow;
}

struct DtxWindow *DtxApp_AddWindow_Rect(struct DtxApp *this, char* title, struct DtxRect dtxRect)
{
    struct DtxSize
        dtxMinSize,
        dtxMaxSize;
    DtxSize_Construct(&dtxMinSize, 320, 240);
    DtxSize_Construct(&dtxMaxSize, 640, 480);
    struct DtxWindow *pDtxWindow = DtxApp_AddWindow_Rect_MinMaxSize(this, title, dtxRect, dtxMinSize, dtxMaxSize);
    DtxSize_Destruct(&dtxMinSize);
    DtxSize_Destruct(&dtxMaxSize);
    return pDtxWindow;
}

struct DtxWindow *DtxApp_AddWindow(struct DtxApp *this, char* title)
{
    struct DtxRect dtxRect;
    DtxRect_Construct(&dtxRect, 0, 0, 320, 240);
    struct DtxWindow *pDtxWindow = DtxApp_AddWindow_Rect(this, title, dtxRect);
    DtxRect_Destruct(&dtxRect);
    return pDtxWindow;
}

void DtxApp_Loop(struct DtxApp *this)
{
    ULONG signalMask, signals;
    signalMask = 0;
    for (ULONG i = 0; i < this->mDtxWindowCount; ++i)
        signalMask |= DtxWindow_GetSignalMask(&(this->mDtxWindows[i]));
    DtxBool isDone = DtxFalse;
    struct IntuiMessage *pIntuiMessage;
    while (isDone == DtxFalse)
    {
        signals = Wait(signalMask);
        for (ULONG i = 0; i < this->mDtxWindowCount; ++i) {
            if (signals & DtxWindow_GetSignalMask(&(this->mDtxWindows[i]))) {
                while ((pIntuiMessage = (struct IntuiMessage *)GetMsg(this->mDtxWindows[i].mpWindow->UserPort)) != NULL)
                {
                    switch (pIntuiMessage->Class)
                    {
                        case IDCMP_CLOSEWINDOW:
                            isDone = DtxTrue;
                            break;
                    }
                    ReplyMsg((struct Message *)pIntuiMessage);
                }
            }
        }
    }
}
