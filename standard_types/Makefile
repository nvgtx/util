CC=gcc
LD=gcc
CFLAGS=-Wall
LDFLAGS=-Wall

find=$(shell find -type f -name $(1))

SRCS:=$(call find, '*.c')
OBJS:=$(SRCS:.c=.o)

#keep intermediate files
.SECONDARY:
#keep additional files
.PRECIOUS: *.map

%.o: %.c
	@ echo ".compiling"
	$(CC) -c $^ -o $@ $(CFLAGS)

%.elf: $(OBJS)
	@ echo "..linking"
	$(LD) $^ -o $@ $(LDFLAGS) -Wl,-Map,$*.map

.PHONY: all
all: build.elf
	@ echo "...completing"

.PHONY: clean
clean:
	@ echo ".cleaning"
	@rm -f $(call find, '*.o')
	@rm -f $(call find, '*~')
	@rm -f *.elf
	@rm -f *.map

