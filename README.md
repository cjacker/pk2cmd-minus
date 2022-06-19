# pk2cmd-minus is an improved pk2cmd to support PICKIT2/3 and nearly all 8-bit PIC microcontrollers

This repo is not my work, it's a mirror of http://kair.us/projects/pickitminus/.

# Features
- Supports nearly all, if not all, 8-bit PIC microcontrollers
- Supports PICkit2 and PICkit3 programmers
- Improved auto detection of parts
- PICkit2 supports programmer-to-go also with recent MSB1st families
- Optimized programming scripts for MSB1st families to reduce write and verify times
- Improved blank section skipping for write and verify, to further reduce programming times
- GUI software works on Windows 2000, XP, 7, 10
- Command line software works on Windows XP, 7, 10, Linux and MacOS
- Retains all the good features from original Microchip PICkit2 and PICkit3 stand-alone software

# Background (copy from http://kair.us/projects/pickitminus/)

Microchip has obsoleted the PICkit2 programmer over ten years ago. It had very easy to use and reliable stand-alone software, but Microchip stopped it's development already in 2009. Luckily, the PICkit2 has always been open source, so anyone can make modifications and improvements are share them with others. Also, dougy83 has created a device file editor which can be used to add support for new parts for the PICkit2 software. Using this editor, people have added support for new microcontroller types. However, recent PIC controllers use SPI-like programming protocol. It isn't possible to support that only by adding new scripts using the [device file editor](https://sites.google.com/site/pk2devicefileeditor/). Either the PICkit2 software or firmware must be modified.

I was recently looking a way to program PIC16F15355 using PICkit2, and came across [this post](https://www.eevblog.com/forum/microcontrollers/pic16f18857-programming-with-pickit2/) by bequest333. He had modified the PICkit software to support SPI-type programming protocol, and created the required new scripts. I developed his software further, by adding support for PIC18F SPI -type chips. I also fixed the device ID bit order for these families, so now it is possible to use [the last publicly available device file](https://github.com/Anobium/PICKitPlus) from PICKitPlus project. The download packages below include device file which has new parts added by me. It has support for 1066 parts ([listed here](http://kair.us/projects/pickitminus/pk2cmdminus_supported_devices.txt)), but I don't know if all of them work with my modified software. I have fixed errors in almost 100 devices already, so I am quite sure there are still many errors. If you find problems with some part, please send me an email.

I named the software PICkit2minus, or PICkit2- for short. It is based on Microchip's original PICkit2 v2.61 software. Many thanks for bequest333 for making most of the hard work to support the SPI-type PICs. Thanks also for [PICKitPlus](https://pickitplus.co.uk/) team for their hard work on updating the device file.

Later I made a new version, based on PICkit3 original software. I modified it to work with both PICkit2 and PICkit3. They will be recognized automatically. Benefit is, only one software to maintain. The PICkitminus is available for download below. It requires .NET framework 2.0, which is available for Windows 2000 and later versions.

The latest addition is command line tool, PK2CMDminus. It is based on the last unofficial version from [MichaelS / Microchip](https://www.microchip.com/forums/tm.aspx?m=540021), and updates by [Miklós Márton](https://github.com/martonmiklos/pk2cmd) to add support for PICkit3. The support for SPI-type MSB1st -family PICs is based on work by bequest333. The PK2CMD Windows version is 32-bit statically linked application targeted for XP, so it should run on Windows versions from XP to 10. It compiles and works fine on Linux and macOS as well. I have tested it on Ubuntu 16.04 and OSX 10.13 High Sierra. On Linux, you need to install libusb-dev with apt-get, or alternatively download libusb-0.1.12 from sourceforge. There are also Linux prebuilt binaries in AppImage format, which should run on many distributions. For Mac, there is also compiled executable available for download below. It is compiled on OSX 10.13, I don't know if it works with other versions.

If you run pk2cmd on Linux and get a message 'PICkit2 not found', quite probable reason is that normal user doesn't have proper rights to the USB device. A simple solution is to run pk2cmd as root, but this is a bit ugly. On systems with udev, you can use [this udev rules file](http://kair.us/projects/pickitminus/60-pickit.rules) which gives appropriate rights for PICkit2 and PICkit3. Just copy this file to /etc/udev/rules.d/ and restart udev (or restart PC). You will also need to re-plug the PICkit.


