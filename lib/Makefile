LIB_DIRS = $(shell find . -maxdepth 1 -type d -name "lib_*")

default-target: all

all:
		for n in $(LIB_DIRS); do cd $$n && make all && cd ..; done


clean:
		$(RM) *.lib
		for n in $(LIB_DIRS); do cd $$n && make clean && cd ..; done

.PHONY: default-target all clean