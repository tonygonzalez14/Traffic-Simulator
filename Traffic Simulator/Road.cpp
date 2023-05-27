#include "Road.h"

// Default constructor
Road::Road() {}

// Constructs a road object and connects all place objects together to form a lane
Road::Road(int x[], int y[], int nPlaces, int direction)
{
    for(int i = 0; i < nPlaces; i++) // fill lane with place objects
    {
        pair<int, int> tempLoc(x[i], y[i]); 
        Place* temp = new Place(tempLoc);
        lane.push_back(temp); // push place into lane vector
    }

    switch (direction) // link places together
    {
        case NORTH: // north bound

            for(int i = 0; i < nPlaces-1; i++) // loops through north lane and connects place objects
            {
                lane[i]->setNorth(lane[i+1]); // set current place's next field to next place
            }
            lane[nPlaces-1]->setNorth(NULL); // set final place's next field to NULL
            break;

        case SOUTH: // south bound

            for(int i = nPlaces-1; i > 0; i--) // loops through south lane and connects place objects
            {
                lane[i]->setSouth(lane[i-1]); // set current place's next field to next place
            }
            lane[0]->setSouth(NULL); // set final place's next field to NULL
            break;

        case EAST: // east bound

            for(int i = 0; i < nPlaces-1; i++) // loops through east lane and connects place objects
            {
                lane[i]->setEast(lane[i+1]); // set current place's next field to next place
            }
            lane[nPlaces-1]->setEast(NULL); // set final place's next field to NULL
            break;

        case WEST: // west bound

            for(int i = nPlaces-1; i > 0; i--) // loops through west lane and connects place objects
            {
                lane[i]->setWest(lane[i-1]); // set current place's next field to next place
            }
            lane[0]->setWest(NULL); // set final place's next field to NULL

    } // swtich
}

// Returns lane vector of place pointers
vector<Place*> Road::getLane() const {return lane;} 

// Connects all place objects to form a lane 
void Road:: setLane(int x[], int y[], int nPlaces, int direction)
{
    lane.clear();
    for(int i = 0; i < nPlaces; i++) // fill lane with places
    {
        pair<int, int> tempLoc(x[i], y[i]);
        Place* temp = new Place(tempLoc);
        lane.push_back(temp);
    }

    switch (direction) // link places together
    {
        case NORTH: // north bound

            for(int i = 0; i < nPlaces-1; i++) // loops through north lane and connects place objects
            {
                lane[i]->setNorth(lane[i+1]); // set current place's next field to next place
            }
            lane[nPlaces-1]->setNorth(NULL); // set final place's next field to NULL
            break;

        case SOUTH: // south bound

            for(int i = nPlaces-1; i > 0; i--) // loops through south lane and connects place objects
            {
                lane[i]->setSouth(lane[i-1]); // set current place's next field to next place
            }
            lane[0]->setSouth(NULL); // set final place's next field to NULL
            break;

        case EAST: // east bound

            for(int i = 0; i < nPlaces-1; i++) // loops through east lane and connects place objects
            {
                lane[i]->setEast(lane[i+1]); // set current place's next field to next place
            }
            lane[nPlaces-1]->setEast(NULL); // set final place's next field to NULL
            break;

        case WEST: // west bound

            for(int i = nPlaces-1; i > 0; i--) // loops through west lane and connects place objects
            {
                lane[i]->setWest(lane[i-1]); // set current place's next field to next place
            }
            lane[0]->setWest(NULL); // set final place's next field to NULL

    } // swtich
}