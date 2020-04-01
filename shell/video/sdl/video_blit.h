#ifndef VIDEO_BLIT_H
#define VIDEO_BLIT_H

#include <SDL/SDL.h>

#if !defined(_WIN32) && !defined(EMSCRIPTEN)
#define HOST_WIDTH_RESOLUTION 320
#define HOST_HEIGHT_RESOLUTION 240
#else
#define HOST_WIDTH_RESOLUTION 448
#define HOST_HEIGHT_RESOLUTION 320
#endif

#define INTERNAL_WSWAN_WIDTH 224
#define INTERNAL_WSWAN_HEIGHT 144

#ifndef EMSCRIPTEN
#define SCREEN_BPP 16
#define PIXEL uint16_t
#else
#define SCREEN_BPP 32
#define PIXEL uint32_t
#endif

#define LOCK_VIDEO SDL_LockSurface(sdl_screen);
#define UNLOCK_VIDEO SDL_UnlockSurface(sdl_screen);

extern SDL_Surface *sdl_screen, *wswan_vs, *backbuffer;

extern uint32_t width_of_surface;
extern uint32_t* Draw_to_Virtual_Screen;

extern void Init_Video();
extern void Set_Video_Menu();
extern void Set_Video_InGame();
extern void Close_Video();
extern void Update_Video_Menu();
extern void Update_Video_Ingame();
extern void Set_Video_Menu_Quit();

#endif
