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

struct DtxWindow *DtxApp_AddWindow(struct DtxApp *this, char* title)
{
    if (this->mDtxWindowCount >= 10)
        return NULL;
    struct DtxWindow *pDtxWindow = &(this->mDtxWindows[this->mDtxWindowCount]);
    if (DtxWindow_Construct(pDtxWindow, title) != DtxTrue)
        return NULL;
    ++(this->mDtxWindowCount);
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
