PROGS = clean all

SOURCE = $(wildcard *.cc)
TARGETS = $(patsubst %.cc,%,$(SOURCE))

CXX = g++
CXXFLAGS += --std=c++11 -g
LIBS = -lpthread

DIR_BIN := bin

# DEPENCES = ../cpu.h ../chunk_allocator.h
# OBJ_SOURCE = ../chunk_allocator.cc

%:%.cc # $(OBJ_SOURCE) $(DEPENCES)
	$(shell if [ ! -e $(DIR_BIN) ];then mkdir -p $(DIR_BIN); fi)
	$(CXX) ${CXXFLAGS} -o $(DIR_BIN)/$@ $< $(LIBS)

all:$(TARGETS)

${DIR_BIN}:
	mkdir $@

clean:
	rm -rf *.o bin/*