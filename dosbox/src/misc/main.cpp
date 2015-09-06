#include "3ds.h"
#include "stdio.h"
#include "h.h"
#include "dosbox.h"
#undef main

int main(int argc, char*argv[]){
	srvInit();
	aptInit();
	
	hidInit(NULL);
	irrstInit(NULL);

	gfxInitDefault();
	_Z11mainforinitiPPc;
	while (aptMainLoop())
	{
		Normal_Loop;
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}
}