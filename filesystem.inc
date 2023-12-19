#if defined _inc_FS_INCLUDE
	#undef _inc_FS_INCLUDE
#endif
#if defined _FS_INCLUDE_included
	#endinput
#endif
#define _FS_INCLUDE_included

// Include version
public INCLUDE_VERSION = 0x100;

#pragma unused INCLUDE_VERSION

// Windows maximum path length
const MAX_PATH	= 256;


// Natives
native CreateDirectory(const dir[]);
native bool:Directory_Exists(const dir[]);
native MoveFile(const path[], const path_to[]);
native DeleteDirectory(const dir[]);
