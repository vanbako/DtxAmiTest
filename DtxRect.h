#ifndef DTXRECT_H
#define DTXRECT_H

#include <exec/types.h>

struct DtxRect
{
    ULONG mLeft;
    ULONG mTop;
    ULONG mWidth;
    ULONG mHeight;
};

void DtxRect_Construct(struct DtxRect *this, ULONG left, ULONG top, ULONG width, ULONG height);
void DtxRect_Destruct(struct DtxRect *this);

#endif
