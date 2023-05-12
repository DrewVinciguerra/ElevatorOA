#pragma once
#include <vector>


class Elevator
{
public:
	Elevator();
	~Elevator();

	void StartingFloor(int floor);
	void AddStops(std::vector<int> stops_vector);
};

