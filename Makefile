HEADERS = Board.h
OBJECTS = main.o Board.o
exe: $(OBJECTS)
	g++ -std=c++11 $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c -std=c++11 $< -o $@
clean:
	rm -i *.o exe