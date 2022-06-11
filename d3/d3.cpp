#include <iostream>
#include <string>
#include <fstream>
#include <set>

int part1() {
    std::ifstream file("input.txt");
    std::set<std::pair<int, int>> houses;
    std::pair<int, int> santa;
    char in;

    while(file >> std::noskipws >> in) 
    {
        switch(in) 
        {
            case '^':
                santa.second++;
                break;
            
            case '>':
                santa.first++;
                break;
            
            case '<':
                santa.first--;
                break;
            
            case 'v':
                santa.second--;
                break;
        }
        houses.insert(santa);
    }

    return houses.size();
}

int part2() {
    std::ifstream file("input.txt");
    std::set<std::pair<int, int>> houses;
    std::pair<int, int> santa;
    std::pair<int, int> robo;
    bool turn = true;
    char in;

    while(file >> std::noskipws >> in) 
    {
        switch(in) 
        {
            case '^':
                turn ? santa.second++ : robo.second++;
                break;
            
            case '>':
                turn ? santa.first++ : robo.first++;
                break;
            
            case '<':
                turn ? santa.first-- : robo.first--;
                break;
            
            case 'v':
                turn ? santa.second-- : robo.second--;
                break;
        }

        turn ? houses.insert(santa) : houses.insert(robo);
        turn ? turn = false : turn = true;
    }

    return houses.size();
}

int main() {
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl;
}