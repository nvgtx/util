CC=g++
LD=g++
LIBS=-lm
CFLAGS=-Wall $(LIBS)
LDFLAGS=-Wall $(LIBS)

recursive=$(foreach d,$(wildcard $1*),$(call recursive,$d/,$2) $(filter $(subst *,%,$2),$d))

SRCS=$(call recursive, , *.cpp)
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
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
	@rm -f $(call recursive, , *.o *~)
	@rm -f *.elf
	@rm -f *.map

