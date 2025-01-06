CXX = g++
CXXFLAGS = -std=c++17 -g

all: call

call: call.o loading.o
	$(CXX) $(CXXFLAGS) -o call call.o loading.o

call.o: call.cpp loading.h
	$(CXX) $(CXXFLAGS) -c call.cpp

loading.o: loading.cpp loading.h
	$(CXX) $(CXXFLAGS) -c loading.cpp

clean:
	rm -f *.o call
