#pragma once
#ifndef FS_COMMON_H
#define FS_COMMON_H

extern void** ppPluginData;
extern void* pAMXFunctions;
typedef void (*logprintf_t)(const char* szFormat, ...);
extern logprintf_t logprintf;
#endif