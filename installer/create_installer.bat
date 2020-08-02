@echo off
title Alee Audio Player Installer Creator
echo Creating Installer...
C:\Qt\QtIFW-3.2.2\bin\binarycreator.exe -v --offline-only -c config\config.xml -p packages AleePlayer-Installer.exe
pause