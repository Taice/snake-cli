CC := g++
CFLAGS := -Wall -g

SRCFILES := $(wildcard ./src/*.cpp)
OBJFILES := $(wildcard ./src/objfiles/*.o)

LINK := -lncursesw

OUTPUT := snake

all : $(OUTPUT)

$(OUTPUT) : $(OBJFILES)
	$(CC) $(CFLAGS) $^ -o ./bin/$@ $(LINK)

%.o : %.cpp $.hpp
	$(CC) $(CFLAGS) -c $^ $(LINK)
	mv $^ ./src/objfiles/

run : 
	make
	./bin/$(OUTPUT)

clean : 
	rm $(OBJFILES) $(OUTPUT)

debug :
	make
	gdb ./$(OUTPUT)
