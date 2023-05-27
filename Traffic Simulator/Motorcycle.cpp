#include "Motorcycle.h"

// Default constructor
Motorcycle::Motorcycle() { }

// Constructs a motorcycle object on a given road reference
Motorcycle::Motorcycle(Road& r)
{
    if(r.getLane()[0]->getNorth() != NULL) // S_N lane
    {
        if(r.getLane()[49]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[49]; // set location 1 pointer to starting place
            r.getLane()[49]->setVehicle(this); // set place vehicle pointer to the new Motorcycle

            setTailIndex(49); // set tail index to starting place index
            setHeadIndex(49); // set head index to starting place index

            setDirection(r); // set motorcycle's direction to north
        }
    }
    else if(r.getLane()[50]->getSouth() != NULL) // N_S lane
    {
        if(r.getLane()[1]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[1]; // set location 1 pointer to starting place
            r.getLane()[1]->setVehicle(this); // set place vehicle pointer to the new Motorcycle

            setTailIndex(1); // set tail index to starting place index
            setHeadIndex(1); // set head index to starting place index

            setDirection(r); // set motorcycle's direction to south
        }
    }
    else if(r.getLane()[50]->getWest() != NULL) // E_W lane
    {
        if(r.getLane()[49]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[49]; // set location 1 pointer to starting place
            r.getLane()[49]->setVehicle(this); // set place vehicle pointer to the new Motorcycle

            setTailIndex(49); // set tail index to starting place index
            setHeadIndex(49); // set head index to starting place index

            setDirection(r); // set motorcycle's direction to west
        }
    }
    else // W_E lane
    {
        if(r.getLane()[0]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[0]; // set location 1 pointer to starting place
            r.getLane()[0]->setVehicle(this); // set place vehicle pointer to the new Motorcycle

            setTailIndex(0); // set tail index to starting place index
            setHeadIndex(0); // set head index to starting place index

            setDirection(r); // set motorcycle's direction to east
        }
    }
}

// Displays motorcycle
void Motorcycle::display() const {cout << "M";}