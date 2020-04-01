#ifndef SCALER_H
#define SCALER_H

#include <stdint.h>

/* Generic */
extern void bitmap_scale(uint32_t startx, uint32_t starty, uint32_t viswidth, uint32_t visheight, uint32_t newwidth, uint32_t newheight,uint32_t pitchsrc,uint32_t pitchdest, PIXEL* restrict src, PIXEL* restrict dst);

#endif
