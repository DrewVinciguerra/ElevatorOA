
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

    const std::string ARG_START = "start=";
    const std::string ARG_FLOOR = "floor=";

    int starting_floor = 0;
    std::vector<int> floors;
    //std::vector<int> stops_vector;

    std::cout << "Welcome to Elevator Sim\n";
    std::cout << "argc=" << argc << "\n";
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[] = " << argv[i] << "\n";
    }

    std::vector<std::string> arguments_vector;
    for (int i = 0; i < argc; i++) {
        arguments_vector.push_back(argv[i]);
    }

    //For real production code, I would check the passed in command more and return a friendly message on any errors I would find. 

    for (std::string current_arg : arguments_vector) {

        //Convert param to lower case
        std::transform(current_arg.begin(), current_arg.end(), current_arg.begin(), std::tolower);

        int target_index = current_arg.find(ARG_FLOOR);
        if (target_index > -1) {

            // Parse input arguments into floors vector
            std::string floor_list = current_arg.substr(ARG_FLOOR.length());
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

        target_index = current_arg.find(ARG_START);
        if (target_index > -1) {
            // Get value after "start="
            std::string start_value = current_arg.substr(ARG_START.length());
            starting_floor = std::stoi(start_value);  //Turn into vector
        }



    }

    std::cout << "Start = " << starting_floor << "\n";
    std::cout << "Floors = " << floors.size() << "\n";

    //ParseParams(int argc, char* argv[]);

    // argv[] = start=12
    // argv[] = floor = 2, 9, 1, 32





    char x;
    std::cin >> x;


}


