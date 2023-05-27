/**
 * @file Bus.h
 * @author Tony Gonzalez
 * @brief Bus class and member functions. Inherits from vehicle class.
 * @version 0.1
 * @date 2023-05-22
 */
#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus: public Vehicle
{
    private:
        Place* loc1; // Bus occupies 4 places
        Place* loc2;
        Place* loc3;
        Place* loc4;
        string name;
        int numPassengers;
    public:
        Bus();
        Bus(Road&);
        void display() const;
};

#endif