PRGNAME     = swanemu.bc
CC          = emcc

#Set maximum RAM that Emscripten use (in bytes).
EMSCRIPTEN_TOTAL_MEMORY=67108864

WASM=1

# change compilation / linking flag options

INCLUDES	= -Ishell/input/sdl -Icore -Icore/sound -Ishell/menu -Ishell/video/sdl -Ishell/audio -Ishell/scalers -Ishell/headers
DEFINES		= -s USE_SDL=1 -DLSB_FIRST -DINLINE="" 
DEFINES		+= -DOSS_SOUND -DFRAMESKIP

CFLAGS		= -O3 -std=gnu99 $(INCLUDES) $(DEFINES)
LDFLAGS     = -lm

# Files to be compiled
SRCDIR 		= ./core ./core/sound ./core/wswan
SRCDIR 		+= ./shell/video/sdl ./shell/audio/sdl ./shell/input/sdl ./shell/menu ./shell/emu ./shell/scalers
VPATH		= $(SRCDIR)
SRC_C		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
OBJ_C		= $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJS		= $(OBJ_C)

all:	$(PRGNAME)

# Rules to make executable
$(PRGNAME): $(OBJS)  
	$(CC) $(CFLAGS) -o $(PRGNAME) $^ $(LDFLAGS)
	
$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(PRGNAME)$(EXESUFFIX) *.o
	rm *.html
	rm *.js
	rm *.wasm
	rm *.mem

html: $(PRGNAME)
ifeq ($(PRELOAD), 1)
	$(CC) -O3 -s USE_SDL=1 -s WASM=$(WASM) -s TOTAL_MEMORY=$(EMSCRIPTEN_TOTAL_MEMORY) -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 \
	-s EMTERPRETIFY_WHITELIST=@em.txt  --profiling-funcs --memory-init-file 0 $(PRGNAME) \
	--preload-file $(PREFILE) -o $(basename $(PRGNAME)).html 
else
	$(CC) -O3 -s USE_SDL=1 -s WASM=$(WASM) -s TOTAL_MEMORY=$(EMSCRIPTEN_TOTAL_MEMORY) -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 \
	-s EMTERPRETIFY_WHITELIST=@em.txt --profiling-funcs --memory-init-file 0 $(PRGNAME) -o $(basename $(PRGNAME)).html 
endif