#include "Place.h"

// Default constructor
Place::Place()
{
    loc.first = -1;
    loc.second = -1;

    veh = NULL;
    light = NULL;
    N = NULL;
    S = NULL;
    E = NULL;
    W = NULL;
}

// Constructs a place object from a location pair
Place::Place(pair<int, int> p)
{
    loc.first = p.first;
    loc.second = p.second;

    veh = NULL;
    light = NULL;
    N = NULL;
    S = NULL;
    E = NULL;
    W = NULL;
}

// Returns the location pair
pair<int, int> Place::getLocation() const {return loc;}

// Sets the location to a given x and y coordinate
void Place::setLocation(int x, int y)
{
    loc.first = x;
    loc.second = y;
}

// Sets the vehicle field for a place object to a given vehicle address
void Place::setVehicle(Vehicle* v) {veh = v;}

// Sets the traffic light field for a place object to a given traffic light address
void Place::setTrafficLight(TrafficLight* l) {light = l;}

// Returns a pointer to the vehicle object in the place object
Vehicle* Place::getVehicle() const {return veh;}

// Returns a pointer to the traffic light object in the place object
TrafficLight* Place::getTrafficLight() const {return light;}

// Returns a pointer to the place object's north pointer
Place* Place::getNorth() const {return N;}

// Returns a pointer to the place object's south pointer
Place* Place::getSouth() const {return S;}

// Returns a pointer to the place object's east pointer
Place* Place::getEast() const {return E;}

// Returns a pointer to the place object's west pointer
Place* Place::getWest() const {return W;}

// Sets the place object's north pointer to a given place address
void Place::setNorth(Place* p) {N = p;}

// Sets the place object's south pointer to a given place address
void Place::setSouth(Place* p) {S = p;}

// Sets the place object's east pointer to a given place address
void Place::setEast(Place* p) {E = p;}

// Sets the place object's west pointer to a given place address
void Place::setWest(Place* p) {W = p;}