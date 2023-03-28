#include "DtxWindow.h"
//#include <clib/gadtools_protos.h>

DtxBool DtxWindow_Construct(struct DtxWindow *this, char* title, struct DtxRect dtxRect, struct DtxSize dtxMinSize, struct DtxSize dtxMaxSize)
{
	this->mpWindow = OpenWindowTags(
        NULL,
        WA_Left, dtxRect.mLeft,
        WA_Top, dtxRect.mTop,
        WA_Width, dtxRect.mWidth,
        WA_Height, dtxRect.mHeight,
        WA_MinWidth, dtxMinSize.mWidth,
        WA_MinHeight, dtxMinSize.mHeight,
        WA_MaxWidth, dtxMaxSize.mWidth,
        WA_MaxHeight, dtxMaxSize.mHeight,
        WA_Title, title,
        WA_CloseGadget, TRUE,
        WA_DepthGadget, TRUE,
        WA_SizeGadget, TRUE,
        WA_DragBar, TRUE,
        WA_Activate, TRUE,
        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_GADGETUP | IDCMP_GADGETDOWN,
        TAG_DONE
    );
	if (this->mpWindow == NULL)
		return DtxFalse;
    return DtxTrue;
}

void DtxWindow_Destruct(struct DtxWindow *this)
{
    if (this->mpWindow != NULL)
        CloseWindow(this->mpWindow);
}

ULONG DtxWindow_GetSignalMask(struct DtxWindow *this)
{
    return (1L << this->mpWindow->UserPort->mp_SigBit);
}

/*
void DtxWindow_AddButtonGadget(struct DtxWindow *this)
{
    struct DrawInfo *pDrawInfo = GetScreenDrawInfo(this->mpWindow->WScreen);
    struct Gadget *pBoolGadget = (struct Gadget *)CreateContext(
        pDrawInfo, "gadgetclass",
        GA_RightBorder, TRUE,
        GA_Text, "My Boolean Gadget",
        GA_ID, MY_BOOLGADGET_ID,
        TAG_DONE);
    pBoolGadget->Activation |= GACT_IMMEDIATE;

    // Add button gadget to the window
    AddGadget(this->mpWindow, pBoolGadget, -1);

    // Refresh window
    RefreshWindowFrame(this->mpWindow);
}
*/
