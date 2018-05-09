HEADERS = Board.h
OBJECTS = Board.o
all: $(OBJECTS)

%.o: %.cpp $(HEADERS)
	g++ -c -std=c++11 $< -o $@
clean:
	rm -i *.o exe