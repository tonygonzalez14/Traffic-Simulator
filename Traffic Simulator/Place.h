/**
 * @file Place.h
 * @author Tony Gonzalez
 * @brief Place class and member functions.
 * @version 0.1
 * @date 2023-05-22
 */
#ifndef PLACE_H
#define PLACE_H

#include <utility>
#include <cstddef>

using namespace std;

class Vehicle; // forward declaration

class TrafficLight; // forward declaration

class Place
{
    private:
        pair<int, int> loc;
        Place *N, *S, *E, *W;
        Vehicle *veh;
        TrafficLight *light;

    public:
        Place();
        Place(pair<int, int>);
        pair<int, int> getLocation() const;
        void setLocation(int, int);
        void setVehicle(Vehicle *);
        void setTrafficLight(TrafficLight *);
        Vehicle* getVehicle() const;
        TrafficLight* getTrafficLight() const;
        void setNorth(Place *);
        void setSouth(Place *);
        void setEast(Place *);
        void setWest(Place *);
        Place* getNorth() const;
        Place* getSouth() const;
        Place* getEast() const;
        Place* getWest() const;
};

#endif