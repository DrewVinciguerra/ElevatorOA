#include <iostream>

#include "Elevator.h"

Elevator::Elevator()
{
	starting_floor = -1;
	stops_vector = {};

}

Elevator::~Elevator()
{

}

void Elevator::StartingFloor(int floor)
{
	starting_floor = floor;
}

void Elevator::FloorStops(std::vector<int> stops)
{
	stops_vector = stops;
}

void Elevator::FloorsVisited(std::vector<int>& floors) {
	floors.push_back(starting_floor);

	for (int current_stop : stops_vector) {
		floors.push_back(current_stop);
	}

}

// This function calculates the time is takes to travel to all the floors that have been requested.
// If there is an error, it returns -1;
int Elevator::CalculateTravelTime()
{
	int travel_time = 0;
	int current_floor = starting_floor;

	if (starting_floor != -1 and stops_vector.size() > 0) {
		for (int current_stop : stops_vector) {
			
			int diff = abs(current_floor - current_stop);
			travel_time += diff * kSingleFloorTravelTime;
			current_floor = current_stop;
		}
	}
	else {
		travel_time = -1;
	}

	return travel_time;


}
