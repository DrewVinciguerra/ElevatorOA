#pragma once
#include <vector>


class Elevator
{
public:
	Elevator();
	~Elevator();

	void StartingFloor(int floor);
	void FloorStops(std::vector<int> stops_vector);
	void FloorsVisited(std::vector<int>& floors);
	int CalculateTravelTime();

private:
	const int kSingleFloorTravelTime = 10;
	int starting_floor;
	std::vector<int> stops_vector;
		 
};

