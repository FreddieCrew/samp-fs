/*
# natives.hpp

Contains all the `PAWN_NATIVE_DECL` for native function declarations.
*/

#pragma once
#ifndef PROJECTNAME_NATIVES_H
#define PROJECTNAME_NATIVES_H

#include <string>

#include <amx/amx2.h>

#include "common.hpp"
#define CHECK_PARAMS(n) \
	if (params[0] != (n * 4)) \
	{ \
		logprintf("%s: Expecting %d parameter(s), but found %d.", __func__, n, params[0] / sizeof(cell)); \
		return 0; \
	}


namespace Natives {
	cell Dir(AMX* amx, cell* params);
	cell DirExists(AMX* amx, cell* params);
	cell DelDir(AMX* amx, cell* params);
	cell Mov(AMX* amx, cell* params);
	cell Copy(AMX* amx, cell* params);
	cell OpenFile(AMX* amx, cell* params);
	cell CreateFile(AMX* amx, cell* params);
	cell DelFile(AMX* amx, cell* params);
	cell FileExists(AMX* amx, cell* params);
	cell CountFiles(AMX* amx, cell* params);
	cell CopyFile(AMX* amx, cell* params);
	//cell CloseFile(AMX* amx, cell* params); - W.I.P
}

#endif
