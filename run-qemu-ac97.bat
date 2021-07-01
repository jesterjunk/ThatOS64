qemu-system-x86_64 -drive format=raw,unit=0,file=drive/drive.hdd -bios bios64.bin -m 1024M -display sdl -vga std -name TESTOS -machine q35 -usbdevice tablet -device AC97

pause