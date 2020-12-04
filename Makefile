CPPFLAGS = -g -I.
LDFLAGS = -lpthread

libsrc = memory_manager_base.cpp memory_manager_best_fit.cpp memory_manager_first_fit.cpp
libobj = $(libsrc:.cpp=.o)

all: run_memory $(libobj)

run_memory: run_memory.o $(libobj)
	$(CXX) -o $@ run_memory.o $(libobj) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f run_memory run_memory.o $(libobj)