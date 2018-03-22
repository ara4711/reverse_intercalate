@echo off 

REM Sets environment variables in the callers enviroment.
REM Appends to the path, so take care no not call this script multiple times!

REM warning! vsdevcmd changes CWD! we must restore it.
pushd .
set "_VSVARS_FILE=C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\vsdevcmd.bat"    
call "%_VSVARS_FILE%"
popd

set "PATH=%PATH%;C:/p4files/sssdrg_RD0049204_dev3/Atlas/main/out/emul"
set "PATH=%PATH%;C:/p4files/sssdrg_RD0049204_dev3/Atlas/main"
set "PATH=%PATH%;C:/Scania/ProgramsForBuild/CMake/3.9.4/bin"
set "PATH=%PATH%;C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/MSBuild/15.0/Bin"
set "PATH=%PATH%;C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.12.25827/bin/Hostx86/x86"
set "PATH=%PATH%;C:/Scania/ProgramsForBuild/Perl/5.10.0/bin"
set "PATH=%PATH%;C:/Scania/ProgramsForBuild/Python/2.7.5"
