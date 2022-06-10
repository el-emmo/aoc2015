#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

int part1() {
    std::ifstream file("input.txt");
    int length, width, height, total = 0;
    std::string segment;
    std::string in;
    std::istringstream ss(in);
    std::vector<std::string> list;

    while(file >> in) {
        while(std::getline(ss, segment, 'x')) //thought this should work but it does not
        {
            list.push_back(segment);
        }

        length = std::stoi(list[0]);
        width = std::stoi(list[1]);
        height = std::stoi(list[2]);

       total += squareFeet(length, width, height);
    }
    return total;
}

int squareFeet(int l, int w, int h) {
    int lw = 2 * l * w;
    int wh = 2 * w * h;
    int lh = 2 * l * h;
    int min = std::min(std::min(lw, wh), lh);
    return lw + wh + lh + min;
}

int main() {
    std::cout << "Part 1: " << part1() << std::endl;
}