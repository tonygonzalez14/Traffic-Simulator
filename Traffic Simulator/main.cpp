/**
 * @file main.cpp
 * @author Tony Gonzalez
 * @brief Main driver for traffic simulator
 * @version 0.1
 * @date 2023-05-26
 */
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "Place.h"
#include "Road.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include "Motorcycle.h"

#define NUM_PLACES 50
#define MAP_SIZE 49
#define NUM_CYCLES 50
#define LANE 0
#define DIVIDER 1

using namespace std;

void initializeSNArray(int [], int []);
void initializeNSArray(int [], int []);
void initializeEWArray(int [], int []);
void initializeWEArray(int [], int []);
void generateRandomVehicle(Road&, Road&, Road&, Road&, 
vector<Vehicle*>&, vector<Vehicle*>&, vector<Vehicle*>&, vector<Vehicle*>&);
void moveAllVehicles(Road&, Road&, Road&, Road&, 
vector<Vehicle*>&, vector<Vehicle*>&, vector<Vehicle*>&, vector<Vehicle*>&);
void checkLane(Road&, int, int);
void checkIntersection(Road&, int, int, int);
void printMap(Road&, Road&, Road&, Road&, int);

int main()
{
    srand(time(0)); // set rand seed

    Road S_N, N_S, E_W, W_E;

    int S_N_x[NUM_PLACES], S_N_y[NUM_PLACES]; // south to north road
    int N_S_x[NUM_PLACES], N_S_y[NUM_PLACES]; // north to south road
    int E_W_x[NUM_PLACES], E_W_y[NUM_PLACES]; // east to west road
    int W_E_x[NUM_PLACES], W_E_y[NUM_PLACES]; // west to east road

    initializeSNArray(S_N_x, S_N_y); // init S_N lane
    initializeNSArray(N_S_x, N_S_y); // init N_S lane
    initializeEWArray(E_W_x, E_W_y); // init E_W lane
    initializeWEArray(W_E_x, W_E_y); // init W_E lane

    S_N.setLane(S_N_x, S_N_y, 51, NORTH); // place south to north lane in road
    N_S.setLane(N_S_x, N_S_y, 51, SOUTH); // place north to south lane in road
    E_W.setLane(E_W_x, E_W_y, 51, WEST); // place east to west lane in road
    W_E.setLane(W_E_x, E_W_y, 51, EAST); // place west to east lane in road
    
    TrafficLight S_N_l(S_N); // south to north traffic light
    TrafficLight N_S_l(N_S); // north to south traffic light
    TrafficLight E_W_l(E_W); // east to west traffic light
    TrafficLight W_E_l(W_E); // west to east traffic light

    vector<Vehicle*> S_N_v, N_S_v, E_W_v, W_E_v; // north, sound, east, and west vehicle collections
    
    N_S_l.setState(1); // start north traffic light to green
    S_N_l.setState(1); // start south traffic light to green
    E_W_l.setState(0); // start east traffic light to red
    W_E_l.setState(0); // start west traffic light to red

    // Main loop for performing simulation
    for(int cycle = 0; cycle < NUM_CYCLES; cycle++) // runs 50 cycles
    {
        Sleep(500); // wait half of a second in between cycles

        S_N_l.update(); // update south to north traffic light
        N_S_l.update(); // update north to south traffic light
        E_W_l.update(); // update east to west traffic light
        W_E_l.update(); // update west to east traffic light

        generateRandomVehicle(N_S, S_N, E_W, W_E, S_N_v, N_S_v, E_W_v, W_E_v); // generate random vehicles

        moveAllVehicles(N_S, S_N, E_W, W_E, S_N_v, N_S_v, E_W_v, W_E_v); // move all vehicles in the map
        
        cout << "\n"; // print a space in between each map

        printMap(S_N, N_S, E_W, W_E, cycle); // print map
    }

    return 0;
} // main 

// Initializes the south to north lane
void initializeSNArray(int S_N_x[], int S_N_y[]) 
{
    for (int i = 0; i < NUM_PLACES; i++) 
    {
        S_N_y[i] = NUM_PLACES / 2 + 1;
        S_N_x[i] = i;
    }
}

// Initializes the north to south lane
void initializeNSArray(int N_S_x[], int N_S_y[]) 
{
    for (int i = 0; i < NUM_PLACES; i++) 
    {
        N_S_y[i] = NUM_PLACES / 2 - 1;
        N_S_x[i] = i;
    }
}

// Initializes the east to west lane
void initializeEWArray(int E_W_x[], int E_W_y[]) 
{
    for (int i = 0; i < NUM_PLACES; i++) 
    {
        E_W_x[i] = NUM_PLACES / 2 - 1;
        E_W_y[i] = i;
    }
}

// Initializes the west to east lane
void initializeWEArray(int W_E_x[], int W_E_y[]) 
{
    for (int i = 0; i < NUM_PLACES; i++) 
    {
        W_E_x[i] = NUM_PLACES / 2 + 1;
        W_E_y[i] = i;
    }
}

// Generates random vehicles to enter the map
void generateRandomVehicle(Road& N_S, Road& S_N, Road& E_W, Road& W_E, 
vector<Vehicle*>& S_N_v, vector<Vehicle*>& N_S_v, vector<Vehicle*>& E_W_v, vector<Vehicle*>& W_E_v) 
{
    int randomVehicle = rand() % 100; // Generate a random number between 0 and 99
    int randomLane = rand() % 4; // Generate a random number between 0 and 3

    if (randomVehicle >= 0 && randomVehicle <= 24) // 25% chance of car arriving
    { 
        switch (randomLane) 
        {
            case NORTH: // place Car in north to south lane
                N_S_v.push_back(new Car(N_S));
                break;
            case SOUTH: // place Car in south to north lane
                S_N_v.push_back(new Car(S_N));
                break;
            case EAST: // place Car in east to west lane
                E_W_v.push_back(new Car(E_W));
                break;
            case WEST: // place Car in west to east lane
                W_E_v.push_back(new Car(W_E));
                break;
        }
    } 
    else if (randomVehicle >= 25 && randomVehicle <= 44) // 20% chance of truck arriving
    { 
        switch (randomLane) 
        {
            case NORTH: // place Truck in north to south lane
                N_S_v.push_back(new Truck(N_S));
                break;
            case SOUTH: // place Truck in south to north lane
                S_N_v.push_back(new Truck(S_N));
                break;
            case EAST: // place Truck in east to west lane
                E_W_v.push_back(new Truck(E_W));
                break;
            case WEST: // place Truck in west to east lane
                W_E_v.push_back(new Truck(W_E));
                break;
        }
    } 
    else if (randomVehicle >= 45 && randomVehicle <= 59) // 15% chance of motorcycle arriving
    { 
        switch (randomLane) 
        {
            case NORTH: // place Motorcycle in north to south lane
                N_S_v.push_back(new Motorcycle(N_S));
                break;
            case SOUTH: // place Motorcycle in south to north lane
                S_N_v.push_back(new Motorcycle(S_N));
                break;
            case EAST: // place Motorcycle in east to west lane
                E_W_v.push_back(new Motorcycle(E_W));
                break;
            case WEST: // place Motorcycle in west to east lane
                W_E_v.push_back(new Motorcycle(W_E));
                break;
        }
    } 
    else if (randomVehicle >= 60 && randomVehicle <= 69) // 10% chance of bus arriving
    { 
        switch (randomLane) 
        {
            case NORTH: // place Bus in north to south lane
                N_S_v.push_back(new Bus(N_S));
                break;
            case SOUTH: // place Bus in south to north lane
                S_N_v.push_back(new Bus(S_N));
                break;
            case EAST: // place Bus in east to west lane
                E_W_v.push_back(new Bus(E_W));
                break;
            case WEST: // place Bus in west to east lane
                W_E_v.push_back(new Bus(W_E));
                break;
        }
    }
}

// Move all vehicles in map by 1 space if possible
void moveAllVehicles(Road& N_S, Road& S_N, Road& E_W, Road& W_E, 
vector<Vehicle*>& S_N_v, vector<Vehicle*>& N_S_v, vector<Vehicle*>& E_W_v, vector<Vehicle*>& W_E_v) 
{
    // Loop through north to south lane and move all vehicles by 1 if possible
    for (int N_S_i = 0; N_S_i < N_S_v.size(); N_S_i++) 
    {
        N_S_v[N_S_i]->move(N_S);
    }
    // Loop through south to north lane and move all vehicles by 1 if possible
    for (int S_N_i = 0; S_N_i < S_N_v.size(); S_N_i++) 
    {
        S_N_v[S_N_i]->move(S_N);
    }
    // Loop through east to west lane and move all vehicles by 1 if possible
    for (int E_W_i = 0; E_W_i < E_W_v.size(); E_W_i++) 
    {
        E_W_v[E_W_i]->move(E_W);
    }
    // Loop through west to east lane and move all vehicles by 1 if possible
    for (int W_E_i = 0; W_E_i < W_E_v.size(); W_E_i++) 
    {
        W_E_v[W_E_i]->move(W_E);
    }
}

// Traverses each lane and prints any vehicles and traffic lights 
void checkLane(Road& r, int row, int col)
{
    bool found = false;

    if(row == 22 && col == 25) // print north to south traffic light if called from that location
    {
        r.getLane()[22]->getTrafficLight()->display();
        return;
    }
    else if(row == 28 && col == 25) // print south to north traffic light if called from that location
    {
        r.getLane()[28]->getTrafficLight()->display();
        return;
    }
    else if(row == 25 && col == 22) // print east to west traffic light if called from that location
    {
        r.getLane()[28]->getTrafficLight()->display();
        return;
    }
    else if(row == 25 && col == 28) // print west to east traffic light if called from that location
    {
        r.getLane()[22]->getTrafficLight()->display();
        return;
    }

    for(int i = 0; i < 50; i++) // traverse road and display vehicles & traffic lights in lane
    {   
        if(r.getLane()[i]->getVehicle() != NULL && r.getLane()[i]->getLocation().first == row 
        && r.getLane()[i]->getLocation().second == col) // if a place contains a vehicle, display
        {
            r.getLane()[i]->getVehicle()->display();
            found = true; 
        }
    }

    if(!found) cout << " "; // print a space if no vechicle is found
}

// Checks the intersection to see if any vehicles from opposite lanes are present
void checkIntersection(Road& r, int row, int col, int flag)
{
    bool found = false;

    if(r.getLane()[col]->getVehicle() != NULL && r.getLane()[col]->getLocation().first == row 
    && r.getLane()[col]->getLocation().second == col) // if a place contains a vehicle, display
    {
        r.getLane()[col]->getVehicle()->display();
        found = true;
    }
    
    if(!found && flag == LANE) {cout << " ";} // print a space if no vehicle is found
    else if(!found && flag == DIVIDER) {cout << "|";} // print a divider if no vehicle is found 
}

// Prints the entire map with all vehicles and traffic lights
void printMap(Road& S_N, Road& N_S, Road& E_W, Road& W_E, int cycle) 
{
    for (int i = 1; i < MAP_SIZE; i++) // row
    { 
        for (int j = 1; j < MAP_SIZE; j++) // col
        { 
            switch (j) 
            {
                case 23: // left divider
                    if(i == 24) {checkIntersection(E_W, i, j, DIVIDER);} // check if there's a vehicle from the east to west lane
                    else if(i == 26) {checkIntersection(W_E, i, j, DIVIDER);} // check if there's a vehicle from the west to east lane
                    else {cout << "|";} // print divider as normal
                    break;
                case 24: // N_S lane
                    if(i == 24) {checkIntersection(E_W, i, j, LANE);} // check if there's a vehicle from the east to west lane
                    else if(i == 26) {checkIntersection(W_E, i, j, LANE);} // check if there's a vehicle from the west to east lane
                    else {checkLane(N_S, i, j);} // check north to south lane as normal
                    break;
                case 25: // middle divider
                    if(i == 22) {checkLane(N_S, i, j);} // print north to south traffic light
                    else if(i == 24) {checkIntersection(E_W, i, j, DIVIDER);} // check if there's a vehicle from the east to west lane
                    else if(i == 26) {checkIntersection(W_E, i, j, DIVIDER);} // check if there's a vehicle from the west to east lane
                    else if(i == 28) {checkLane(S_N, i, j);} // print south to north traffic light
                    else {cout << "|";} // print divider as normal
                    break;
                case 26: // S_N lane
                    if(i == 24) {checkIntersection(E_W, i, j, LANE);} // check if there's a vehicle from the east to west lane
                    else if(i == 26) {checkIntersection(W_E, i, j, LANE);} // check if there's a vehicle from the west to east lane
                    else {checkLane(S_N, i, j);} // check north to south lane as normal
                    break;
                case 27: // right divider
                    if(i == 24) {checkIntersection(E_W, i, j, DIVIDER);} // check if there's a vehicle from the east to west lane
                    else if(i == 26) {checkIntersection(W_E, i, j, DIVIDER);} // check if there's a vehicle from the west to east lane
                    else {cout << "|";} // print divider as normal
                    break;
                default:
                    switch (i) 
                    {
                        case 23: // top divider
                            cout << "-";
                            break;
                        case 24: // E_W lane
                            checkLane(E_W, i, j);
                            break;
                        case 25: // middle divider
                            if(j == 22) {checkLane(E_W, i, j);}// prints west to east traffic light
                            else if(j == 28) {checkLane(W_E, i, j);} // prints east to west traffic light
                            else {cout << "-";} // print divider as normal
                            break;
                        case 26: // W_E lane
                            checkLane(W_E, i, j);
                            break;
                        case 27: // bottom divider
                            cout << "-";
                            break;
                        default: // empty space
                            cout << "#";
                    } // i switch case
            } // j switch case
        } // j loop
        cout << "\n";
    } // i loop
    cout << "Cycle: " << cycle + 1 << endl;
}