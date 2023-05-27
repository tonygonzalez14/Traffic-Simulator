#include "Bus.h"

// Default constructor
Bus::Bus() { }

// Constructs a bus object on a given road reference
Bus::Bus(Road& r)
{
    if(r.getLane()[0]->getNorth() != NULL) // S_N lane
    {
        if(r.getLane()[46]->getVehicle() == NULL
        && r.getLane()[47]->getVehicle() == NULL 
        && r.getLane()[48]->getVehicle() == NULL
        && r.getLane()[49]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[46]; // set locations 1-4 pointer to starting place
            loc2 = r.getLane()[47]; 
            loc3 = r.getLane()[48]; 
            loc4 = r.getLane()[49]; 
            r.getLane()[49]->setVehicle(this); // set place vehicle pointers to the new Bus
            r.getLane()[48]->setVehicle(this); 
            r.getLane()[47]->setVehicle(this); 
            r.getLane()[46]->setVehicle(this); 

            setTailIndex(49); // set tail index to starting place index
            setHeadIndex(46); // set head index to starting place index

            setDirection(r); // set bus's direction to north
        }
    }
    else if(r.getLane()[50]->getSouth() != NULL) // N_S lane
    {
        if(r.getLane()[3]->getVehicle() == NULL
        && r.getLane()[2]->getVehicle() == NULL 
        && r.getLane()[1]->getVehicle() == NULL
        && r.getLane()[0]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[3]; // set locations 1-4 pointer to starting place
            loc2 = r.getLane()[2];
            loc3 = r.getLane()[1];
            loc4 = r.getLane()[0];
            r.getLane()[3]->setVehicle(this); // set place vehicle pointers to the new Bus
            r.getLane()[2]->setVehicle(this); 
            r.getLane()[1]->setVehicle(this); 
            r.getLane()[0]->setVehicle(this); 

            setTailIndex(0); // set tail index to starting place index
            setHeadIndex(3); // set head index to starting place index

            setDirection(r); // set bus's direction to south
        }
    }
    else if(r.getLane()[50]->getWest() != NULL) // E_W lane
    {
        if(r.getLane()[46]->getVehicle() == NULL
        && r.getLane()[47]->getVehicle() == NULL 
        && r.getLane()[48]->getVehicle() == NULL
        && r.getLane()[49]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[46]; // set locations 1-4 pointer to starting place
            loc2 = r.getLane()[47];
            loc3 = r.getLane()[48];
            loc4 = r.getLane()[49];
            r.getLane()[49]->setVehicle(this); // set place vehicle pointers to the new Bus
            r.getLane()[48]->setVehicle(this);
            r.getLane()[47]->setVehicle(this);
            r.getLane()[46]->setVehicle(this);

            setTailIndex(49); // set tail index to starting place index
            setHeadIndex(46); // set head index to starting place index

            setDirection(r); // set bus's direction to west
        }
    }
    else // W_E lane
    {
        if(r.getLane()[3]->getVehicle() == NULL
        && r.getLane()[2]->getVehicle() == NULL 
        && r.getLane()[1]->getVehicle() == NULL
        && r.getLane()[0]->getVehicle() == NULL) // if no vehicle is already in the road
        {
            loc1 = r.getLane()[3]; // set locations 1-4 pointer to starting place
            loc2 = r.getLane()[2];
            loc3 = r.getLane()[1];
            loc4 = r.getLane()[0];
            r.getLane()[3]->setVehicle(this); // set place vehicle pointers to the new Bus
            r.getLane()[2]->setVehicle(this); 
            r.getLane()[1]->setVehicle(this); 
            r.getLane()[0]->setVehicle(this); 

            setTailIndex(0); // set tail index to starting place index
            setHeadIndex(3); // set head index to starting place index

            setDirection(r); // set bus's direction to east
        }
    }
}

// Displays bus
void Bus::display() const {cout << "B";}