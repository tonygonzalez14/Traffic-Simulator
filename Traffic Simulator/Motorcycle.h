/**
 * @file Motorcycle.h
 * @author Tony Gonzalez
 * @brief Motorcycle class and member functions. Inherits from vehicle class.
 * @version 0.1
 * @date 2023-05-22
 */
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle: public Vehicle
{
    private:
        Place* loc1; // Motorcycle occupies 1 place
        string brand;
    public:
        Motorcycle();
        Motorcycle(Road&);
        void display() const;
};

#endif