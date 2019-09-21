@echo off

setlocal

call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x86

cd /d %~dp0
devenv clua_cpp.sln /build "debug|x86" /project ccpp_lua

devenv clua_cpp.sln /build "debug|x86" /project cluacpp


if "%1" == "" pause