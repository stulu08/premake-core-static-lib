#include "StuluPremake.h"

#include "../host/premake.h"

#include <stdlib.h>

#if PLATFORM_WINDOWS
#else
#include <linux/limits.h>
#endif

int app_main(int argc, const char** argv)
{

	lua_State* L;
	int z;

	L = luaL_newstate();
	luaL_openlibs(L);

	z = premake_init(L);
	if (z == OKAY) {
		z = premake_execute(L, argc, argv, "src/_premake_main.lua");
	}

	lua_close(L);
	return z;
}



const char* getCurDir() {
#if PLATFORM_WINDOWS
	char path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, path);
	return path;
#else
	char path[PATH_MAX];
	getcwd(path, PATH_MAX);
	return path;
#endif
}
int changeDir(const char* newDir) {
	int succes;
#if PLATFORM_WINDOWS
	wchar_t wide_buffer[PATH_MAX];
	if (MultiByteToWideChar(CP_UTF8, 0, newDir, -1, wide_buffer, PATH_MAX) == 0) {
		//Error
		printf("Error: Could not map string to UTF-16 string in changeDir(const char* newDir)");
		return -1;
	}
	succes = SetCurrentDirectoryW(wide_buffer);
#else
	(void)(L);  /* warning: unused parameter */
	succes = !chdir(newDir);
#endif
	return succes;
}

int stulu_premake_exec(const char* path, const char* action) {
	const char* startingPath = getCurDir();

	int argc = 2;
	const char* argv[2] = {
		path, action
	};
	changeDir(path);
	int succes = app_main(argc, argv);
	changeDir(startingPath);

	return succes;
}

int stulu_premake_exec_args(const char* path, const char** argv, int argc) {
	const char* startingPath = getCurDir();
	changeDir(path);
	int succes = app_main(argc, argv);
	changeDir(startingPath);

	return succes;
}
