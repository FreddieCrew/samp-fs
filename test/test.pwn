#include <a_samp>
#include <filesystem>
#include <sscanf2> // https://github.com/Y-Less/sscanf
#include <pcmd> // https://github.com/FreddieCrew/pcmd

main() {
	print("Hello");
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success) {
	if(!success) {
		SendClientMessage(playerid, -1, "Invalid command");
	}
	return 1;
}

CMD:createdir(playerid, params[]) {
	new name[MAX_PATH];

	if (sscanf(params, "s[256]", name)) return SendClientMessage(playerid, -1, "/createdir [path]");

	if (fs_Directory_Exists(name)) return SendClientMessage(playerid, -1, "Error: This directory already exists");

	fs_CreateDirectory(name);
	return 1;
}

CMD:deldir(playerid, params[]) {
	new name[MAX_PATH];
	
	if (sscanf(params, "s[256]", name)) return SendClientMessage(playerid, -1, "/deldir [path]");
	
	if (!fs_Directory_Exists(name)) return SendClientMessage(playerid, -1, "Error: This directory does not exist.");
	
	fs_DeleteDirectory(name);
	return 1;
}

CMD:move(playerid, params[]) {
	new from[MAX_PATH], to[MAX_PATH];
	
	if (sscanf(params, "s[256]s[256]", from, to)) return SendClientMessage(playerid, -1, "/move [from] [to]");
	
	fs_MoveFile(from, to);
	return 1;
}

CMD:copy(playerid, params[]) {
	new from[MAX_PATH], to[MAX_PATH];
	
	if (sscanf(params, "s[256]s[256]", from, to)) return SendClientMessage(playerid, -1, "/copy [from] [to]");
	
	fs_MoveFile(from, to);
	return 1;
}

CMD:fcreate(playerid, params[]) {
	new path[MAX_PATH];
	
	if (sscanf(params, "s[256]", path)) return SendClientMessage(playerid, -1, "/create [path]");
	
	if(fs_fexists(path)) return SendClientMessage(playerid, -1, "The file already exists");
	
	fs_fcreate(path, ios_base_app);
	return 1;
}

CMD:fexists(playerid, params[]) {
	new path[MAX_PATH];
	
	if (sscanf(params, "s[256]", path)) return SendClientMessage(playerid, -1, "/fexists [path]");
	
	if (fs_fexists(path)) {
		return SendClientMessage(playerid, -1, "The file exists!");
	} else {
		SendClientMessage(playerid, -1, "The file does not exist :(");
	}
	return 1;
}

CMD:fdel(playerid, params[]) {
	new path[MAX_PATH];
	
	if (sscanf(params, "s[256]", path)) return SendClientMessage(playerid, -1, "/fdel [path]");
	
	if (!fs_fexists(path)) return SendClientMessage(playerid, -1, "The file does not exist");
	
	fs_fdel(path);
	return 1;
}

CMD:fmov(playerid, params[]) {
	new path_from[MAX_PATH], path_to[MAX_PATH];
	
	if (sscanf(params, "s[256]s[256]", path_from, path_to)) return SendClientMessage(playerid, -1, "/fmov [from] [to]");
	
	if (!fs_fexists(path_from)) return SendClientMessage(playerid, -1, "The file does not exist");
	
	fs_MoveFile(path_from, path_to);
	return 1;
}

CMD:fcount(playerid, params[]) {
	new path[MAX_PATH], string[35];
	
	if (sscanf(params, "s[256]", path)) return SendClientMessage(playerid, -1, "/fcount [path]");
	
	if (fs_count(path) <= 0) return SendClientMessage(playerid, -1, "The folder is empty");
	
	format(string, sizeof(string), "%d files", fs_count(path));
	SendClientMessage(playerid, -1, string);
	return 1;
}
