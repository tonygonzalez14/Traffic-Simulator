/**
 * @file Car.h
 * @author Tony Gonzalez
 * @brief Car class and member functions. Inherits from vehicle class.
 * @version 0.1
 * @date 2023-05-22
 */
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car: public Vehicle
{
    private:
        Place* loc1; // Car occupies 2 places 
        Place* loc2;
        string color;
    public:
        Car();
        Car(Road&);
        void display() const;
};

#endif