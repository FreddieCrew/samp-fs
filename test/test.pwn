#include <a_samp>
#include <filesystem>
#include <sscanf2>
#include <pcmd>

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

	if (Directory_Exists(name)) return SendClientMessage(playerid, -1, "Error: This directory already exists");

	CreateDirectory(name);
	return 1;
}

CMD:deldir(playerid, params[]) {
	new name[MAX_PATH];
	
	if (sscanf(params, "s[256]", name)) return SendClientMessage(playerid, -1, "/deldir [path]");
	
	if (!Directory_Exists(name)) return SendClientMessage(playerid, -1, "Error: This directory does not exist.");
	
	DeleteDirectory(name);
	return 1;
}

CMD:move(playerid, params[]) {
	new from[MAX_PATH], to[MAX_PATH];
	
	if (sscanf(params, "s[256]s[256]", from, to)) return SendClientMessage(playerid, -1, "/move [from] [to]");
	
	MoveFile(from, to);
	return 1;
}

CMD:copy(playerid, params[]) {
	new from[MAX_PATH], to[MAX_PATH];
	
	if (sscanf(params, "s[256]s[256]", from, to)) return SendClientMessage(playerid, -1, "/copy [from] [to]");
	
	MoveFile(from, to);
	return 1;
}
