#!/bin/bash

if [ $STAGE = "script" ]; then
  if [ $TRAVIS_OS_NAME = "linux" ]; then
    echo "[TRAVIS] Running qmake"
    qmake
    echo "[TRAVIS] Building project"
    make
    echo "[TRAVIS] Installing into appdir"
    make install INSTALL_ROOT=~/appdir
    echo "[TRAVIS] Getting linuxdeployqt"
    wget -c -nv "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage"
    chmod a+x linuxdeployqt-continuous-x86_64.AppImage
    echo "[TRAVIS] Building AppImage"
    ./linuxdeployqt-continuous-x86_64.AppImage ~/appdir/usr/share/applications/*.desktop -appimage
  else
    echo "[TRAVIS] Building for macOS"
    export PATH="/usr/local/opt/qt/bin:$PATH"
    export PKG_CONFIG_PATH="/usr/local/opt/libffi/lib/pkgconfig"
    export CURRENT_BREW_QT_VERSION="5.13.0"
    export CURRENT_BREW_GSTREAMER_VERSION="1.16.0_1"
    cd ..
    mkdir "build-aleeplayer"
    cd "build-aleeplayer"
    echo "[TRAVIS] Running qmake"
    qmake "INCLUDEPATH += /usr/local/opt/qt/include" "LIBS += -L/usr/local/opt/qt/lib" ../AleePlayer/AleePlayer.pro
    echo "[TRAVIS] Building project"
    make
    echo "[TRAVIS] Deploying Qt Libraries"
    macdeployqt AleePlayer.app -dmg

  fi
elif [ $STAGE = "before_install" ]; then
  if [ $TRAVIS_OS_NAME = "linux" ]; then
    sudo apt-get install libtag1-dev qt5-qmake libqt5x11extras5-dev qt5-default qttools5-dev-tools libqt5svg5-dev qtmultimedia5-dev libgtk2.0-dev
  else
    echo "[TRAVIS] Preparing to build for macOS"
  fi
elif [ $STAGE = "after_success" ]; then
  if [ $TRAVIS_OS_NAME = "linux" ]; then
    echo "[TRAVIS] Publishing AppImage"
    wget -c https://github.com/probonopd/uploadtool/raw/master/upload.sh
    cp AleePlayer*.AppImage AleePlayer-linux.AppImage
    cp AleePlayer*.AppImage.zsync AleePlayer-linux.AppImage.zsync
    bash upload.sh AleePlayer-linux.AppImage*
  else
    echo "[TRAVIS] Publishing Disk Image"
    cd ~
    wget -c https://github.com/probonopd/uploadtool/raw/master/upload.sh
    bash upload.sh AleePlayer-macOS.dmg
  fi
fi
