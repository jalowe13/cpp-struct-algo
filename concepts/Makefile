# Conecpts Makefile for ease of building
# Jacob Lowe
CXX = g++
EXE = LSearchTest
SOURCES = linear-search.cpp
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
CXXFLAGS = -std=c++14 -g -Wall -Wformat -static-libgcc -static-libstdc++
# Compile Objs

all: check_file $(EXE)

check_file:
	del -f $(EXE).exe
	@echo Deleted and rebuilding
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
# EXE Output from compilinug
$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)
clean:
	del -f $(EXE).exe
