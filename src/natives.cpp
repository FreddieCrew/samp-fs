/*
# natives.cpp

This source file contains the bridge between natives and implementations. I
prefer to keep the actual implementation separate. The implementation contains
no instances of `cell` or `AMX*` and is purely C++ and external library code.
The code here acts as the translation between AMX data types and native types.
*/

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include "natives.hpp"

using namespace std;
namespace fs = std::filesystem;


// Directory functions
cell AMX_NATIVE_CALL Natives::Dir(AMX* amx, cell* params) {
	CHECK_PARAMS(1);

	cell retval;

	retval = fs::create_directory(amx_GetCppString(amx, params[1]));
	return retval;
}

cell AMX_NATIVE_CALL Natives::DirExists(AMX* amx, cell* params) {
	CHECK_PARAMS(1);
	return fs::exists(amx_GetCppString(amx, params[1]));
}

cell AMX_NATIVE_CALL Natives::DelDir(AMX* amx, cell* params) {
	CHECK_PARAMS(1);

	cell retval(0);

	try {
		retval = params[2] ? static_cast<cell>(fs::remove_all(amx_GetCppString(amx, params[1]))) : static_cast<cell>(fs::remove(amx_GetCppString(amx, params[1])));
	}
	catch (const fs::filesystem_error& e) {
		logprintf("[Filesystem]: Exception occurred in %s: %s", __func__, e.what());
	}
	return retval;
}

// File functions
cell AMX_NATIVE_CALL Natives::Mov(AMX* amx, cell* params) {
	CHECK_PARAMS(2);

	cell retval(-1);
	
	fs::rename(amx_GetCppString(amx, params[1]), amx_GetCppString(amx, params[2]));
	retval = 0;
	return retval;
}

cell AMX_NATIVE_CALL Natives::Copy(AMX* amx, cell* params) {
	CHECK_PARAMS(2);

	cell retval(-1);

	fs::copy(amx_GetCppString(amx, params[1]), amx_GetCppString(amx, params[2]));
	retval = 0;
	return retval;
}

// TODO: create file, open file, delete file functions