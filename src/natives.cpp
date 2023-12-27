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
	} catch (const fs::filesystem_error& e) {
		logprintf("[Filesystem]: Exception occurred on %s: %s", __func__, e.what());
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

cell AMX_NATIVE_CALL Natives::CreateFile(AMX* amx, cell* params) {
	CHECK_PARAMS(params[0] / sizeof(cell));

	std::ofstream handle;

	std::ios_base::openmode mode{};

	for (size_t i = 2; i < params[0] / sizeof(cell); i++) {
		cell* addr = nullptr;

		amx_GetAddr(amx, params[i], &addr);

		if (addr == nullptr) break;

		if (*addr == 0) mode = mode | std::ios_base::in;
		else if (*addr == 1) mode = mode | std::ios_base::out;
		else if (*addr == 2) mode = mode | std::ios_base::ate;
		else if (*addr == 3) mode = mode | std::ios_base::app;
		else if (*addr == 4) mode = mode | std::ios_base::trunc;
		else if (*addr == 5) mode = mode | std::ios_base::binary;
	}

	handle.open(amx_GetCppString(amx, params[1]), mode);

	if (handle.is_open()) {
		handle.close();
		return 1;
	}
	return 0;
}

cell AMX_NATIVE_CALL Natives::OpenFile(AMX* amx, cell* params) {
	CHECK_PARAMS(params[0] / sizeof(cell));

	fstream* file = new fstream();


	std::ios_base::openmode mode{};

	for (size_t i = 2; i <= params[0] / sizeof(cell); i++) {
		cell* addr = nullptr;
		amx_GetAddr(amx, params[i], &addr);

		if (addr == nullptr) break;

		if (*addr == 0) mode = mode | std::ios_base::in;
		else if (*addr == 1) mode = mode | std::ios_base::out;
		else if (*addr == 2) mode = mode | std::ios_base::ate;
		else if (*addr == 3) mode = mode | std::ios_base::app;
		else if (*addr == 4) mode = mode | std::ios_base::trunc;
		else if (*addr == 5) mode = mode | std::ios_base::binary;
	}

	file->open(amx_GetCppString(amx, params[1]), mode);


	if(file->is_open()) {
		return (cell)file;
	}

	delete file;

	logprintf("File couldn't be opened.");
	return 0;
}

cell AMX_NATIVE_CALL Natives::FileExists(AMX* amx, cell* params) {
	CHECK_PARAMS(1);

	std::error_code ex;
	cell retval = fs::is_regular_file(amx_GetCppString(amx, params[1]), ex);

	if (ex.value() != 0) {
		logprintf("[filesystem]: Exception occurred on function %s: %s", __func__, ex.message().c_str());
	}
	return retval;
}

cell AMX_NATIVE_CALL Natives::DelFile(AMX* amx, cell* params) {
	CHECK_PARAMS(1);

	cell retval{0};

	try {
		fs::remove(amx_GetCppString(amx, params[1]));
	} catch (const fs::filesystem_error& e) {
		logprintf("[Filesystem]: Exception occurred on %s: %s", __func__, e.what());
	}
	return retval;
}

cell AMX_NATIVE_CALL Natives::CopyFile(AMX* amx, cell* params) {
	CHECK_PARAMS(params[0] / sizeof(cell));
	cell retval{0};
	fs::copy_options mode{};

	for (size_t i = 3; i <= params[0] / sizeof(cell); i++) {
		cell* addr = nullptr;

		amx_GetAddr(amx, params[i], &addr);

		if (addr == nullptr) break;

		if (*addr == 0) mode = mode | fs::copy_options::none;
		else if (*addr == 1) mode = mode | fs::copy_options::skip_existing;
		else if (*addr == 2) mode = mode | fs::copy_options::overwrite_existing;
		else if (*addr == 3) mode = mode | fs::copy_options::update_existing;
		else if (*addr == 4) mode = mode | fs::copy_options::recursive;
		else if (*addr == 5) mode = mode | fs::copy_options::copy_symlinks;
		else if (*addr == 6) mode = mode | fs::copy_options::skip_symlinks;
		else if (*addr == 7) mode = mode | fs::copy_options::directories_only;
		else if (*addr == 8) mode = mode | fs::copy_options::create_symlinks;
		else if (*addr == 9) mode = mode | fs::copy_options::create_hard_links;
	}

	try {
		retval = fs::copy_file(amx_GetCppString(amx, params[1]), amx_GetCppString(amx, params[2]), mode);
	} catch (const fs::filesystem_error& e) {
		logprintf("[Filesystem]: Exception occurred on %s: %s", __func__, e.what());
	}


	return retval;
}

cell AMX_NATIVE_CALL Natives::CountFiles(AMX* amx, cell* params) {
	CHECK_PARAMS(1);
	cell retval{0};

	try {
		for (const auto& entry : fs::directory_iterator(amx_GetCppString(amx, params[1]))) {
			if (fs::is_regular_file(entry)) {
				retval++;
			}
		}
	} catch (const fs::filesystem_error& e) {
		logprintf("[Filesystem]: Exception occurred on %s: %s", __func__, e.what());
	}
	return retval;
}