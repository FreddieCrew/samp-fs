#if defined _inc_FS_INCLUDE
	#undef _inc_FS_INCLUDE
#endif
#if defined _FS_INCLUDE_included
	#endinput
#endif
#define _FS_INCLUDE_included

// Include version
public INCLUDE_VERSION = 0x101;

#pragma unused INCLUDE_VERSION

// OpenModes
enum OpenModes {
	fs_read_only,
	fs_append
	fs_io
};

// Copy Modes
enum CopyModes {
	fs_none,
	fs_skip_existing,
	fs_overwrite_existing,
	fs_update_existing,
	fs_recursive,
	fs_copy_symlinks,
	fs_skip_symlinks,
	fs_directories_only,
	fs_create_symlinks,
	fs_create_hard_links
};

// Windows maximum path length
const MAX_PATH	= 256;


// Directory Natives
native fs_CreateDirectory(const dir[]);
native bool:fs_Directory_Exists(const dir[]);
native fs_DeleteDirectory(const dir[]);

// File Natives
native fs_MoveFile(const path[], const path_to[]);
native fs_fcreate(const path[], {OpenModes, _}:...);
native File:fs_fopen(const path[], {OpenModes, _}:...);
native fs_fdel(const path[]);
native fs_fexists(const path[]);
native fs_count(const path[]);
native fs_fcopy(const path_from[], const path_to[], {CopyModes, _}:...);

// W.I.P
//native File:fs_fclose(const path[]);

