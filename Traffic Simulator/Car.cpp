#include "Car.h"

// Default constructor
Car::Car() { }

// Constructs a car object on a given road reference
Car::Car(Road& r)
{
    if(r.getLane()[0]->getNorth() != NULL) // S_N lane
    {
        if(r.getLane()[48]->getVehicle() == NULL
        && r.getLane()[49]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[48]; // set location 1 & 2 pointers to starting place
            loc2 = r.getLane()[49]; 
            r.getLane()[49]->setVehicle(this); // set place vehicle pointers to the new car
            r.getLane()[48]->setVehicle(this); 

            setTailIndex(49); // set tail index to starting place index
            setHeadIndex(48); // set head index to starting place index

            setDirection(r); // set car's direction to north
        }
    }
    else if(r.getLane()[50]->getSouth() != NULL) // N_S lane
    {
        if(r.getLane()[1]->getVehicle() == NULL
        && r.getLane()[0]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[1]; // set location 1 & 2 pointers to starting place
            loc2 = r.getLane()[0];
            r.getLane()[0]->setVehicle(this); // set place vehicle pointers to the new car
            r.getLane()[1]->setVehicle(this);

            setTailIndex(0); // set tail index to starting place index
            setHeadIndex(1); // set head index to starting place index

            setDirection(r); // set car's direction to south
        }
    }
    else if(r.getLane()[50]->getWest() != NULL) // E_W lane
    {
        if(r.getLane()[48]->getVehicle() == NULL
        && r.getLane()[49]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[48]; // set location 1 & 2 pointers to starting place
            loc2 = r.getLane()[49];
            r.getLane()[49]->setVehicle(this); // set place vehicle pointers to the new car
            r.getLane()[48]->setVehicle(this);

            setTailIndex(49); // set tail index to starting place index
            setHeadIndex(48); // set head index to starting place index

            setDirection(r); // set car's direction to west
        }
    }
    else // W_E lane
    {
        if(r.getLane()[1]->getVehicle() == NULL
        && r.getLane()[0]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[1]; // set location 1 & 2 pointers to starting place
            loc2 = r.getLane()[0];
            r.getLane()[0]->setVehicle(this); // set place vehicle pointers to the new car
            r.getLane()[1]->setVehicle(this);

            setTailIndex(0); // set tail index to starting place index
            setHeadIndex(1); // set head index to starting place index

            setDirection(r); // set car's direction to east
        }
    }
}

// Displays car
void Car::display() const {cout << "C";}