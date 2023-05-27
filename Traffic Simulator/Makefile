CC = g++
CFLAGS = -Wall -Wextra

# List of all the source files
SOURCES = Car.cpp Bus.cpp Vehicle.cpp Truck.cpp TrafficLight.cpp Road.cpp Place.cpp Motorcycle.cpp main.cpp

# Generate the object file names from the source file names
OBJECTS = $(SOURCES:.cpp=.o)

# Specify the main executable name
EXECUTABLE = TrafficSim

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)