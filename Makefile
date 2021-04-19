CPPFLAGS = -g -I.
LDFLAGS = -lpthread

libsrc = memory_manager_base.cpp memory_manager_best_fit.cpp memory_manager_first_fit.cpp
libobj = $(libsrc:.cpp=.o)

all: execute $(libobj)

execute: execute.o $(libobj)
	$(CXX) -o $@ execute.o $(libobj) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f execute execute.o $(libobj)