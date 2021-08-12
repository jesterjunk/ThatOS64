# Step by Step Tutorials on how to code a 64-Bit loader and kernel for OS Development

![GitHub stars](https://img.shields.io/github/stars/ThatOSDev/ThatOS64?style=social)  
![GitHub forks](https://img.shields.io/github/forks/ThatOSDev/ThatOS64?style=social)  
![GitHub watchers](https://img.shields.io/github/watchers/ThatOSDev/ThatOS64?style=social)  
![GitHub followers](https://img.shields.io/github/followers/ThatOSDev?style=social)  

# THIS PROJECT IS ON HOLD 
August 11th, 2021   
The reason I am putting this project on hold is do to how the GDT has convinced me that I need to write the loader file in assembly. Since the GDT is such a pain in the rump, I have decided to write that one file with FASM. The GDT will not work with inline assembly in a C file. I have never seen anyone actually acomplish this with GCC. I have read from others that they got it working, but when you actually test their code with GCC, it fails every time. So they are boasting for nothing. By using FASM, this will allow me to bootstrap the OS into a working state, that once I get to the point of writing the kernel, I can use C once more. This also allows me to work out the details for a proper Linker, so that I can link obj files together. Once that milestone is accomplished, then I can rewrite the loader once again in C. Bottom line, this is a catch-22 situation, since I am not using ELF or PE32+.  So this was the only solution I am able to work with at this time.  

# NOTES  
- Starting with CODE5, the resolution from the EFI file sets the screen height and width to 1920x1080.
- Although this can work on real hardware, I do NOT recommend doing so unless you know what you are doing. Use virtualbox or qemu until **you know** you have solid working code.
- For CODE1, you will need the BOOTX64.EFI file from my other GitHub Repo. https://github.com/ThatOSDev/UEFI-Tuts  
- The drive.hdd file is included, I didn't realize this when I made the first video.  
- The bios64.bin file is for qemu to work. Otherwise QEMU will fail to load.  
- Although the BUILD INSTRUCTIONS shows Windows, MAC or Linux, this tutorial series is using a windows host. However all code and makefile command switches should all work if you follow the build instructions.  

# TOOLS NEEDED  
- OSFMount ---- https://www.osforensics.com/tools/mount-disk-images.html  
- QEMU ( Optional ) ---- https://www.qemu.org/  
- VirtualBox ( Optional ) ---- https://www.virtualbox.org/  
- GCC for windows ---- https://nuwen.net/mingw.html  

# BUILD INSTRCUTIONS  
[https://github.com/ThatOSDev/ThatOS64/tree/master/BUILD.md](https://github.com/ThatOSDev/ThatOS64/tree/master/BUILD.md)  

# SOCIAL MEDIA LINK
**YOUTUBE** : https://www.youtube.com/channel/UCouyC9D6WFBwc24sqdkS-jw  
**DISCORD** : ThatOSDev#5516  

# READ THIS !!!
- THINGS YOU SHOULD KNOW BEFORE STARTING OS DEVELOPMENT  
    - The C Language  
    - Assembly Language  
    - How to read Hex Code ( Example : 0x8664 )  
    - How your Host Operating System works ( Such as windows or linux )  
    - How your compiler works ( Such as GCC )  
    - How to do research ( Don't be lazy )  
- **BEGINNER MISTAKES** : [https://wiki.osdev.org/Beginner_Mistakes](https://wiki.osdev.org/Beginner_Mistakes)  


# STRUCT FROM THE EFI BOOTLOADER
**NOTE: This is current starting with CODE5**  
```c
typedef struct BLOCKINFO
{
    uint64_t*               BaseAddress;
    uint64_t                BufferSize;
    uint32_t                ScreenWidth;
    uint32_t                ScreenHeight;
    uint32_t                PixelsPerScanLine;
    uint64_t*               LoaderFileSize;
    EFI_MEMORY_DESCRIPTOR*  MMap;
    uint64_t                MMapSize;
    uint64_t                MMapDescriptorSize;
    void*                   rsdp;
} __attribute__((__packed__)) BLOCKINFO;
```
  
# TUTORIALS
- RIGHT CLICK THE LINKS AND OPEN IN NEW TAB  
	- INITIAL SETUP &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; --- [YT&nbsp;&nbsp; 1](https://www.youtube.com/watch?v=WCFEEboRHNg)  ---  [CODE](https://github.com/ThatOSDev/ThatOS64/tree/master/src/code1)  
	- ABI INTERFACE &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; --- [YT&nbsp;&nbsp; 2a](https://www.youtube.com/watch?v=T7iXp1UwaiA) | [YT&nbsp;&nbsp; 2b](https://www.youtube.com/watch?v=zkCHrM-B0Ig) | [YT&nbsp;&nbsp; 2c](https://www.youtube.com/watch?v=eUOr01eVGVM) ---  [CODE](https://github.com/ThatOSDev/ThatOS64/tree/master/src/code2)  
	- GRAPHIC TEXT &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; --- [YT&nbsp;&nbsp; 3](https://www.youtube.com/watch?v=9d7TWvGsbts) ---  [CODE](https://github.com/ThatOSDev/ThatOS64/tree/master/src/code3)   
	- ORGANIZATION AND TEXT POSITION &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; --- [YT&nbsp;&nbsp; 4](https://www.youtube.com/watch?v=wa75ifmBmro) ---  [CODE](https://github.com/ThatOSDev/ThatOS64/tree/master/src/code4)  
	- MEMORY MANAGER - MMap / Paging / GDT / IDT &nbsp; &nbsp; --- [YT&nbsp;&nbsp; 5a](https://www.youtube.com/watch?v=o6Z67fHswd4) | [YT&nbsp;&nbsp; 5b](https://www.youtube.com/watch?v=gsH_UHQ0DyI) | [YT&nbsp;&nbsp; 5c](https://www.youtube.com/watch?v=k9dp54Mh0Ew) | [YT&nbsp;&nbsp; 5d](https://www.youtube.com/watch?v=QDg10w5EvJk) | [YT&nbsp;&nbsp; 5e]  
	&nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; ---  [CODE](https://github.com/ThatOSDev/ThatOS64/tree/master/src/code5)  


More Tuts Coming soon... ( **NOTE : The order of this list is subject to change** )  

	* BMP / TGA Image Loading  
	* PCI  
	* AHCI  
	* Mouse  


![Current Progress](progress1.png)  

![Current Progress](progress2.png)  

![Current Progress](progress3.png)  

![Current Progress](progress4.png)  
 
