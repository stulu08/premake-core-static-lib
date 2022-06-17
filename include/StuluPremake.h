/**
 * \file   StuluPremake.h
 * \brief  Program-wide constants and definitions.
 * \author Copyright (c) 2022-2022 Julian Bents
 */

#ifndef STULUPREMAKE_H
#define STULUPREMAKE_H

#define ST_PREMAKE_ACTION_VS2022 "vs2022"
#define ST_PREMAKE_ACTION_VS2019 "vs2019"
#define ST_PREMAKE_ACTION_VS2015 "vs2015"
#define ST_PREMAKE_ACTION_VS2013 "vs2013"
#define ST_PREMAKE_ACTION_VS2012 "vs2012"
#define ST_PREMAKE_ACTION_VS2010 "vs2010"
#define ST_PREMAKE_ACTION_VS2008 "vs2008"
#define ST_PREMAKE_ACTION_VS2005 "vs2005"
#define ST_PREMAKE_ACTION_GMAKE "gmake"
#define ST_PREMAKE_ACTION_GMAKE2 "gmake2"
#define ST_PREMAKE_ACTION_XCODE4 "xcode4"
#define ST_PREMAKE_ACTION_CODELITE "codelite"


#ifdef __cplusplus
#define ST_PREMAKE_API extern "C"
#else
#define ST_PREMAKE_API
#endif


ST_PREMAKE_API int stulu_premake_exec(const char* path, const char* action);
ST_PREMAKE_API int stulu_premake_exec_args(const char* path, const char** argv, int argc);
#endif /* STULUPREMAKE_H */
