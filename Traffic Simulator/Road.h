/**
 * @file Road.h
 * @author Tony Gonzalez
 * @brief Road class and member functions.
 * @version 0.1
 * @date 2023-05-22
 */
#ifndef ROAD_H
#define ROAD_H

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

#include <vector>
#include "Place.h"

using namespace std;

class Road
{
    private:
        vector<Place*> lane;
    public:
        Road();
        Road(int x[], int y[], int nPlaces, int direction);
        vector<Place*> getLane() const;
        void setLane(int x[], int y[], int nPlaces, int direction);
};

#endif