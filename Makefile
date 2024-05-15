CXX = g++
CXXFLAGS = -std=c++20 -Iinclude

SRCS = main.cpp src/time.cpp src/club.cpp src/event.cpp
OBJS = ${SRCS:.cpp=.o}

all: test clean

test: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ $^

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

clean:
	rm -f ${OBJS}
