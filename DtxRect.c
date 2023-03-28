#include "DtxRect.h"

void DtxRect_Construct(struct DtxRect *this, ULONG left, ULONG top, ULONG width, ULONG height)
{
    this->mLeft = left;
    this->mTop = top;
    this->mWidth = width;
    this->mHeight = height;
}

void DtxRect_Destruct(struct DtxRect *this)
{
}
