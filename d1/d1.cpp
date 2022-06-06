#include <iostream>
#include <string>
#include <fstream>

int part1() {
    std::fstream file("input.txt");
    int floor = 0;
    char in;

    while(file >> std::noskipws >> in) {
        in == '(' ? floor++ : floor--;
    }

    return floor;
}

int part2() {
    std::fstream file("input.txt");
    int floor = 0;
    int position = 0;
    char in;

    while(file >> std::noskipws >> in) {
        if(floor < 0)
            break;
         
        in == '(' ? floor++ : floor--;
        position++;
    }

    return position;
}

int main() {
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl; 
}
