<p align="center">
  <a href="https://premake.github.io/" target="blank"><img src="https://premake.github.io/img/premake-logo.png" height="200" width="200" alt="Premake" /></a>
</p>

<p align="center">
    <img src="https://img.shields.io/github/release/premake/premake-core/all.svg" alt="Latest release" />
    <img src="https://img.shields.io/github/release-date-pre/premake/premake-core.svg" alt="Release date" />
    <img src="https://img.shields.io/github/commits-since/premake/premake-core/v5.0.0-beta1.svg" alt="Commits" />
    <a href="https://opensource.org/licenses/BSD-3-Clause" target="_blank">
        <img src="https://img.shields.io/github/license/premake/premake-core" alt="BSD 3-Clause" />
    </a>
    <br/>
    <a href="https://travis-ci.org/premake/premake-core" target="_blank">
        <img src="https://img.shields.io/travis/premake/premake-core/master.svg?label=linux" alt="Linux" />
    </a>
    <a href="https://ci.appveyor.com/project/PremakeOrganization/premake-core" target="_blank">
        <img src="https://img.shields.io/appveyor/ci/PremakeOrganization/premake-core?label=windows" alt="Windows" />
    </a>
    <a href="https://github.com/premake/premake-core/graphs/contributors" target="_blank">
        <img src="https://img.shields.io/github/contributors/premake/premake-core?label=code+contributors" alt="Contributors" />
    </a>
    <a href="https://opencollective.com/premake" _target="blank">
        <img src="https://opencollective.com/premake/all/badge.svg?label=financial+contributors" alt="Contributors" />
    </a>
    <a href="https://twitter.com/premakeapp" target="_blank">
        <img src="https://img.shields.io/twitter/follow/premakeapp.svg?style=social&label=Follow">
    </a>
</p>

# Welocme to Stulu Premake - [Download](https://github.com/stulu08/premake-core-static-lib/releases/tag/STv1.0.0)
### Just premake as an static lib
Basicly I just put all the stuff premake used in in the main project, wrote like 10 lines to execute premake and build it as a static lib. 
Why? 
Because maybe you like premake and want to do something where you need to create project files directly by code and dont want to do weird things like system("premake5 -vs2022")

## NOTE:
- Its a static lib not a dll
- Large File Size
- Only x64
- Static runtime is on (/MT or /MTd)
- If u use this pls refere me

### Example

``` C
#include <StuluPremake.h>

int main() {
	int succes = stulu_premake_exec("C:/Folder/With/Premake5/File/In/It", ST_PREMAKE_ACTION_VS2022);
	return 0;
}
``` 

# Welcome to Premake

Premake is a command line utility which reads a scripted definition of a software project, then uses it to perform build configuration tasks or generate project files for toolsets like Visual Studio, Xcode, and GNU Make. Premake's scripts are little [Lua](http://www.lua.org/) programs, so the sky's the limit!

```lua
workspace "MyWorkspace"
    configurations { "Debug", "Release" }

project "MyProject"
    kind "ConsoleApp"
    language "C++"
    files { "**.h", "**.cpp" }

    filter { "configurations:Debug" }
        defines { "DEBUG" }
        symbols "On"

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"
```

## Getting Started

* [Documentation](https://premake.github.io/docs/)
* [Contributing](https://github.com/premake/premake-core/blob/master/CONTRIBUTING.md)
* [Issue Tracker](https://github.com/premake/premake-core/issues)

## Sponsors

Premake is a BSD-licensed open source project. Our many thanks to these fine people who help us spend more time adding features and supporting the community. :tada:

Want to join them? [Learn more here](https://opencollective.com/premake). Use Premake at work? Ask your manager or marketing team about contributing too; your company logo will appear on our [website](https://premake.github.io/) and README, as well as all of our [release pages](https://github.com/premake/premake-core/releases).

### Organizations

<a href="https://opencollective.com/premake#sponsors" target="_blank"><img src="https://opencollective.com/premake/sponsors.svg?width=890&avatarHeight=92&button=false"/></a>

### Individuals

<a href="https://opencollective.com/premake#backers" target="_blank"><img src="https://opencollective.com/premake/backers.svg?width=890&button=false"/></a>

## Contributing

We love getting [pull requests](https://www.quora.com/GitHub-What-is-a-pull-request) and rely heavily on the contributions of our community to keep Premake healthy and growing. If you're new to the project, [our Contributing Guide is here](https://github.com/premake/premake-core/blob/master/CONTRIBUTING.md).

A great big thank you to all of you who have already contributed your time and know-how!

<a href="https://github.com/premake/premake-core/graphs/contributors"><img src="https://opencollective.com/premake/contributors.svg?width=890&avatarHeight=32&button=false" /></a>

## Stay in touch

* Website - https://premake.github.io
* Twitter - [@premakeapp](https://twitter.com/premakeapp)

## License

[BSD 3-Clause](https://opensource.org/licenses/BSD-3-Clause)

The Lua language and runtime library is &copy; TeCGraf, PUC-Rio.
See their website at http://www.lua.org/
