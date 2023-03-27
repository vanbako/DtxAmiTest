#include "DtxWindow.h"

DtxBool DtxWindow_Construct(struct DtxWindow *this, char* title)
{
	this->mpWindow = OpenWindowTags(
        NULL,
        WA_Left, 0,
        WA_Top, 0,
        WA_Width, 320,
        WA_Height, 256,
        WA_MinWidth, 320,
        WA_MinHeight, 256,
        WA_MaxWidth, 640,
        WA_MaxHeight, 512,
        WA_Title, title,
        WA_CloseGadget, TRUE,
        WA_DepthGadget, TRUE,
        WA_SizeGadget, TRUE,
        WA_DragBar, TRUE,
        WA_Activate, TRUE,
        WA_IDCMP, IDCMP_CLOSEWINDOW,
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
