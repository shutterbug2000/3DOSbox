OBJS:=$(wildcard *.o)

all:
	arm-none-eabi-g++  $(OBJS) -static-libgcc -static-libstdc++ -s -g -march=armv6k -mtune=mpcore -mfloat-abi=hard -specs=3dsx.specs ./libctru.a ./libm.a ./libSDL.a 