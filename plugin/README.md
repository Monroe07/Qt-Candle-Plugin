### Qt6 plugin for the candleLight firmware compatible USB devices.

This project contains the source code for the Qt6 serial bus module plug-in for interfacing with Windows and USB devices flashed with [candleLight_fw](https://github.com/candle-usb/candleLight_fw).<br>

#### Building (Windows only):
* Download [the latest stable version of Qt6](https://www.qt.io/download/), for example 6.8.2 (This modified from the SavvyCAN Candle Plugin for Qt5).
* Open the project file.
* Select the kit that is Qt6 or greater. Again, It was origianlly modified for use with 6.8.2 using Desktop 6.8.2 MSVC2022 64bit. Then choose a Release build configuration.
* Build the project.
* Copy the built qtcandlelightcanbus.dll to canbus folder of Qt's plugin directory

#### Usage:
* Connect your device or devices to Windows via USB.
* An example can be found in the "Examples" folder of this repository.
