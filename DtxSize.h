#ifndef DTXSIZE_H
#define DTXSIZE_H

#include <exec/types.h>

struct DtxSize
{
    ULONG mWidth;
    ULONG mHeight;
};

void DtxSize_Construct(struct DtxSize *this, ULONG width, ULONG height);
void DtxSize_Destruct(struct DtxSize *this);

#endif
