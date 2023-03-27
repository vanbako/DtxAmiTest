#ifndef DTXLIBS_H
#define DTXLIBS_H

#include "DtxMacros.h"
#include <clib/exec_protos.h>

struct DtxLibs
{
	struct Library
		*mpIntuition,
		*mpGfx;
};

DtxBool DtxLibs_Construct(struct DtxLibs *this);
void DtxLibs_Destruct(struct DtxLibs *this);

#endif
