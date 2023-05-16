
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Elevator.h"

int main(int argc, char* argv[]) {
/*
    •       Provide code (in C++) that simulates an elevator.
    •       Upload to github for discussion during interview.
    •       Document all assumptions and any features that weren’t implemented.
    •       The result should be an executable, or script, that can be run with the following inputs and generate the following outputs.
    •       Inputs: [list of floors to visit] (e.g elevator start=12 floor=2,9,1,32)
    •       Outputs: [total travel time, floors visited in order] (e.g 560 12,2,9,1,32)
    •       Program Constants: Single floor travel time: 10
*/

    const std::string kArgStart = "start=";
    const std::string kArgFloor = "floor=";

    int starting_floor = -1;
    std::vector<int> floors;

    std::vector<std::string> arguments_vector;
    for (int i = 0; i < argc; i++) {
        arguments_vector.push_back(argv[i]);
    }


    // For real production code, I would check the passed in command more and return a friendly message on any errors I find. 
 
    // If this function was going to be added to in the future, I would break up this large main function into smaller ones like:  
    //   ProcessArguments() and OperateElevator()

    for (std::string current_arg : arguments_vector) {

        //Convert param to lower case
        std::transform(current_arg.begin(), current_arg.end(), current_arg.begin(), std::tolower);

        size_t target_index = current_arg.find(kArgStart);
        if (target_index != std::string::npos ) {
            // Get value after "start="
            std::string start_value = current_arg.substr(kArgStart.length());
            starting_floor = std::stoi(start_value);  //Turn into vector
        }

        target_index = current_arg.find(kArgFloor);
        if (target_index != std::string::npos) {

            // Parse input arguments into floors vector
            std::string floor_list = current_arg.substr(kArgFloor.length());
            size_t pos = 0;
            std::string current_value;

            bool parse_floors = true;

            while (parse_floors) {
                pos = floor_list.find(",");

                // Is this the last value?
                if (pos == std::string::npos) {
                    parse_floors = false;
                    pos = floor_list.length();
                }

                current_value = floor_list.substr(0, pos);
                floors.push_back(std::stoi(current_value));
                floor_list.erase(0, pos + 1);
            }
        }
    }

    // Make sure the needed variables have values
    if (starting_floor != -1 and floors.size() != 0) {
        Elevator::ErrorCode result;
        Elevator elevator;
        elevator.StartingFloor(starting_floor);
        elevator.FloorStops(floors);

        std::vector<int> floors_visited;

        elevator.FloorsVisited(floors_visited);
        int time = 0;
        result = elevator.CalculateTravelTime(time);

        if (result == Elevator::ErrorCode::Success) {

            std::cout << time << " ";

            size_t vector_length = floors_visited.size();
            for (size_t index = 0; index < vector_length; index++) {

                std::cout << floors_visited[index];
                if (index < vector_length - 1) {
                    std::cout << ",";
                }
            }
        }
        else {
            std::cout << "ERROR Example usage: elevator start=12 floor=2,9,1,32 \n";
        }

    }
    else {
        std::cout << "ERROR Example usage: elevator start=12 floor=2,9,1,32 \n";
    }


    std::cout << "Exit";

}


