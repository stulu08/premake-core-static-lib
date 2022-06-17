local corePath = _SCRIPT_DIR
premake.api.deprecations "off"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	solution "Premake5"
		configurations { "Release", "Debug", "Dist" }

		flags { "MultiProcessorCompile" }
		
		platforms { "x64" }

		


		-- MinGW AR does not handle LTO out of the box and need a plugin to be setup
		filter { "system:windows", "configurations:Release or Dist", "toolset:not mingw" }
			flags		{ "LinkTimeOptimization" }

	project "Premake5"
		targetname  "premake5"
		language    "C"
		kind        "StaticLib"
		staticruntime "on"
		targetdir ("bin/" .. outputdir .. "")
		objdir ("bin-int/" .. outputdir .. "")

		warnings    "off"

		includedirs { "contrib/lua/src", "contrib/luashim" }
		includedirs { "contrib/zlib", "contrib/libzip" }
		includedirs { "contrib/curl/include" }
		includedirs { "contrib/curl/lib", "contrib/mbedtls/include" }
		includedirs { "include" }


		-- links { "lua-lib" }
		-- links { "zip-lib", "zlib-lib" }
		-- links { "curl-lib" }
		defines {"N_FSEEKO"}
		defines { "PREMAKE_COMPRESSION" }
		defines { "PREMAKE_CURL"}
		defines { 'USE_ZLIB' }
		defines { "BUILDING_LIBCURL", "CURL_STATICLIB", "HTTP_ONLY" }
		files {
			"contrib/lua/**.h",
			"contrib/lua/**.c",

			"contrib/zlib/**.h",
			"contrib/zlib/**.c",
			"contrib/libzip/**.h",
			"contrib/libzip/**.c",

			"contrib/curl/**.h",
			"contrib/curl/**.c",

			"*.txt", "**.lua",
			"src/**.h", "src/**.c",
			"include/**.h", "src/Stulu/**.c",
			"modules/**"
		}
		excludes{
			"contrib/lua/src/lauxlib.c",
			"contrib/lua/src/lua.c",
			"contrib/lua/src/luac.c",
			"contrib/lua/src/print.c",
			"contrib/lua/**.lua",
			"contrib/lua/etc/*.c"
		}

		externalincludedirs { "include" }



		excludes
		{
			"contrib/**.lua",
			"contrib/**.txt",
		}

		filter "configurations:Debug"
			debugargs   { "--scripts=%{prj.location}/%{path.getrelative(prj.location, prj.basedir)}", "test" }


		filter "system:windows"
			links       { "ole32", "ws2_32", "advapi32", "version" }
			files { "src/**.rc" }
			defines { "_WINDOWS" }

		filter "system:linux or bsd or solaris or haiku"
			defines { "HAVE_SSIZE_T_LIBZIP", "HAVE_CONFIG_H" }

		filter { "system:windows", "toolset:mingw" }
			defines { "HAVE_SSIZE_T_LIBZIP" }

		filter "system:macosx"
			defines { "HAVE_SSIZE_T_LIBZIP" }

		filter "toolset:mingw"
			links		{ "crypt32" }

		filter "system:linux or bsd or hurd"
			defines     { "LUA_USE_POSIX", "LUA_USE_DLOPEN" }
			links       { "m" }
			linkoptions { "-rdynamic" }

		filter "system:linux or hurd"
			links       { "dl", "rt" }

		filter "system:not windows"
			defines { 'HAVE_UNISTD_H' }

		filter { "system:not windows", "system:not macosx" }
			links   { "mbedtls-lib" }

		filter "system:macosx"
			defines     { "LUA_USE_MACOSX" }
			links       { "CoreServices.framework", "Foundation.framework", "Security.framework", "readline" }
			
		filter "system:linux"
			links		{ "uuid" }

		filter { "system:macosx", "action:gmake" }
			toolset "clang"

		filter { "system:solaris" }
			links       { "m", "socket", "nsl" }

		filter "system:aix"
			defines     { "LUA_USE_POSIX", "LUA_USE_DLOPEN" }
			links       { "m" }

		filter "system:haiku"
			defines     { "LUA_USE_POSIX", "LUA_USE_DLOPEN", "_BSD_SOURCE" }
			links       { "network", "bsd" }

		filter "configurations:Debug"
			defines     "_DEBUG"
			flags       { "Symbols" }

		filter "configurations:Release"
			defines     "NDEBUG"
			optimize    "Full"
			flags       { "NoBufferSecurityCheck", "NoRuntimeChecks" }

		filter "configurations:Dist"
			defines     "NDEBUG"
			optimize    "Full"
			flags       { "NoBufferSecurityCheck", "NoRuntimeChecks" }

	-- optional 3rd party libraries
	-- group "contrib"
		-- include "contrib/lua"
		-- include "contrib/zlib"
		-- include "contrib/libzip"
		-- include "contrib/curl"