/**
 * \file   StuluPremake.c
 * \brief  Program-wide constants and definitions.
 * \author Copyright (c) 2022-2022 Julian Bents
 */
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

int stulu_premake_exec_options(const char* path, const char* action, const char** options, int optionsCount) {
	const char* startingPath = getCurDir();

	const int argc = optionsCount + 2;
	const char** argv = malloc(sizeof(char*) * argc);
	argv[0] = path;
	argv[1] = action;

	for (int i = 0; i < optionsCount; i++) {
		argv[i + 2] = options[i];
	}

	changeDir(path);
	int succes = stulu_premake_app_main(argc, argv);
	changeDir(startingPath);

	free(argv);

	return succes;
}

int stulu_premake_exec(const char* path, const char* action) {
	const char* startingPath = getCurDir();

	const char* argv[2] = {
		path, action
	};
	changeDir(path);
	int succes = stulu_premake_app_main(2, argv);
	changeDir(startingPath);

	return succes;
}

int stulu_premake_app_main(int argc, const char** argv) {
	printf("Running Premake %s %s\n", PREMAKE_VERSION, PREMAKE_COPYRIGHT);

	for (int32_t i = 0; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	putchar('\n');
	
	int succes = app_main(argc, argv);
	return succes;
}