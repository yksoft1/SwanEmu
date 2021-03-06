#ifndef WSWAN_GFX_H
#define WSWAN_GFX_H

#ifndef EMSCRIPTEN
#define RGB16
#endif

#ifdef RGB16
#define WPIXEL uint16_t
#else
#define WPIXEL uint32_t
#endif

uint_fast8_t Wswan_IsVertical(void);

void WSWan_TCacheInvalidByAddr(uint32_t);

extern uint8_t	wsTCache[512*64];		  //tiles cache
extern uint8_t	wsTCacheFlipped[512*64];  	  //tiles cache (H flip)
extern uint8_t	wsTileRow[8];		  //extracted 8 pixels (tile row)
extern uint8_t	wsTCacheUpdate[512];	  //tiles cache flags
extern uint8_t	wsTCache2[512*64];		  //tiles cache
extern uint8_t	wsTCacheFlipped2[512*64];  	  //tiles cache (H flip)
extern uint8_t	wsTCacheUpdate2[512];	  //tiles cache flags
extern uint32_t	wsVMode;			  //Video Mode	

void wsMakeTiles(void);
void wsGetTile(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
void wsSetVideo(uint32_t, uint32_t);

void wsScanline(WPIXEL* restrict target);

extern uint32_t	dx_r,dx_g,dx_b,dx_sr,dx_sg,dx_sb;
extern uint32_t	dx_bits,dx_pitch,cmov,dx_linewidth_blit,dx_buffer_line;


void WSwan_SetPixelFormat(void);

void WSwan_GfxInit(void) SWANEMU_COLD;
void WSwan_GfxReset(void);
void WSwan_GfxWrite(uint32_t A, uint8_t V);
uint8_t WSwan_GfxRead(uint32_t A);
void WSwan_GfxWSCPaletteRAMWrite(uint32_t ws_offset, uint8_t data);

uint32_t wsExecuteLine(WPIXEL* restrict pixels, uint8_t pitch, const uint32_t skip);

void WSwan_SetLayerEnableMask(uint64_t mask);
void WSwan_GfxSaveState(uint32_t load, FILE* fp);

#endif
