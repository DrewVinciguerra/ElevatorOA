
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

    const std::string ARG_START = "start";
    const std::string ARG_FLOOR = "floor";

    int starting_floor = 0;
    std::vector<int> stops_vector;

    std::cout << "Welcome to Elevator Sim\n";
    std::cout << "argc=" << argc << "\n";
    for (int i = 0; i < argc; i++) {
        std::cout << "argv[] = " << argv[i] << "\n";
    }

    std::vector<std::string> arguments_vector;
    for (int i = 0; i < argc; i++) {
        arguments_vector.push_back(argv[i]);
    }

    for (std::string current_arg : arguments_vector) {
        //Convert param to lower case
        std::transform(current_arg.begin(), current_arg.end(), current_arg.begin(), [](unsigned char c) { return std::tolower(c); });
        int x = current_arg.find(ARG_FLOOR);


    }

    //ParseParams(int argc, char* argv[]);

    // argv[] = start=12
    // argv[] = floor = 2, 9, 1, 32





    char x;
    std::cin >> x;


}


