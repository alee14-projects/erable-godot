if "%APPVEYOR_REPO_TAG_NAME%"=="continuous" (

    exit 1

)

set QTDIR=C:\Qt\5.14\msvc2017_64
set PATH=%PATH%;%QTDIR%\bin
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

qmake AleePlayer.pro "CONFIG+=release"
nmake release
mkdir deploy
copy release\AleePlayer.exe deploy
cd deploy
windeployqt AleePlayer.exe -multimedia
