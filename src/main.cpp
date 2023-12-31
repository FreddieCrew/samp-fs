#include <amx/amx.h>
#include <plugincommon.h>

#include "common.hpp"
#include "natives.hpp"
#include "version.hpp"

logprintf_t logprintf;

extern void* pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
    logprintf("\n\n Filesystem version %s loaded.\n", PLUGIN_VERSION);
    return true;
}

extern "C" const AMX_NATIVE_INFO native_list[] = {
    { "fs_CreateDirectory", Natives::Dir },
    { "fs_Directory_Exists", Natives::DirExists },
    { "fs_MoveFile", Natives::Mov },
    { "fs_DeleteDirectory", Natives::DelDir },
    { "fs_fcreate", Natives::CreateFile },
    { "fs_fdel", Natives::DelFile },
    { "fs_fexists", Natives::FileExists },
    { "fs_count", Natives::CountFiles },
    { "fs_fcopy", Natives::CopyFile },
    { NULL, NULL }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
    return amx_Register(amx, native_list, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload() {
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
    logprintf("\n\nFilesystem unloaded.\n");
    return 1;
}
