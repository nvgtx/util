directories = $(wildcard */)

.PHONY: all
all: ; $(foreach dir,$(directories),(cd $(dir) && $(MAKE) all) &&) :

.PHONY: clean
clean: ; $(foreach dir,$(directories),(cd $(dir) && $(MAKE) clean) &&) :
