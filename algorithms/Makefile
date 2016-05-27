directories = $(wildcard */)

.PHONY: all
all: ; $(foreach dir,$(directories),(cd $(dir) && $(MAKE) all --ignore-errors ) &&) :

.PHONY: clean
clean: ; $(foreach dir,$(directories),(cd $(dir) && $(MAKE) clean) &&) :
