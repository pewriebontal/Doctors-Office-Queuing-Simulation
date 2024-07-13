CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES= lqueue.h empty_collection_exception.h patient.cpp doctor.cpp doctors_office.cpp simulation.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Simulation

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
