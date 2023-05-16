#pragma once
#include <vector>

class Elevator
{
public:
	enum ErrorCode {
		Success,
		MissingArgument
	};

	Elevator();
	~Elevator();

	void StartingFloor(int floor);
	void FloorStops(std::vector<int> stops_vector);
	void FloorsVisited(std::vector<int>& floors);
	ErrorCode CalculateTravelTime(int& travel_time);

private:
	const int kSingleFloorTravelTime = 10;
	int starting_floor;
	std::vector<int> stops_vector;
		 
};

