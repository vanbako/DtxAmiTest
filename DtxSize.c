#include "DtxSize.h"

void DtxSize_Construct(struct DtxSize *this, ULONG width, ULONG height)
{
    this->mWidth = width;
    this->mHeight = height;
}

void DtxSize_Destruct(struct DtxSize *this)
{
}
