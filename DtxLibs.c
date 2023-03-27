#include "DtxLibs.h"

DtxBool DtxLibs_Construct(struct DtxLibs *this)
{
	this->mpIntuition = OpenLibrary("intuition.library", DtxIntuitionVersion);
	if (this->mpIntuition == NULL)
		return DtxFalse;
	this->mpGfx = OpenLibrary("graphics.library", DtxGfxVersion);
	if (this->mpGfx == NULL)
		return DtxFalse;
    return DtxTrue;
}

void DtxLibs_Destruct(struct DtxLibs *this)
{
    if (this->mpIntuition != NULL)
        CloseLibrary(this->mpIntuition);
    if (this->mpGfx != NULL)
        CloseLibrary(this->mpGfx);
}
