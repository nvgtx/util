CC=g++
LD=g++
LIBS=-lm
CFLAGS=-Wall $(LIBS)
LDFLAGS=-Wall $(LIBS)

SRCS=$(wildcard *.cpp) $(wildcard */*.cpp)
OBJS=$(SRCS:.cpp=.o)

%.o: %.c
	@ echo ".compiling"
	$(CC) -c $^ -o $@ $(CFLAGS)

build.elf: $(OBJS)
	@ echo "..linking"
	$(LD) $^ -o $@ $(LDFLAGS)

.PHONY: all
all: build.elf
	@ echo "...completing"

.PHONY: clean
clean:
	@ echo ".cleaning"
	@rm -rf *.o
	@rm -rf */*.o
	@rm -rf *.elf
	@rm -rf *.map
	@rm -rf *~
	@rm -rf */*~

