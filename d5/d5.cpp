#include <iostream>
#include <string>
#include <fstream>

//functions for part 1

bool hasThreeVowels(const std::string& s) {
    int count = 0;
    bool res = false;

    for(std::string::size_type i = 0; i < s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
            count++;
        
        if(count > 2) {
            res = true;
            break;
        }
    }
    return res;
    
}

bool letterAppearsTwiceInARow(const std::string& s) {
    bool res = false;

    for(std::string::size_type i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i+1]) {
            res = true;
            break;
        }
    }
    return res;
}

bool doesNotContainOneOfGiven(const std::string& s) {
    if((s.find("ab") == std::string::npos) && (s.find("cd") == std::string::npos) && (s.find("pq") == std::string::npos) && (s.find("xy") == std::string::npos))
        return true;
    return false;
}

int part1() {
    std::ifstream file("input.txt");
    std::string in;
    int count = 0;
    
    while(file >> in)
    {
        if(hasThreeVowels(in) && letterAppearsTwiceInARow(in) && doesNotContainOneOfGiven(in))
            count++;
    }

    return count;
}

//functions for part 2

bool containsPair(const std::string& s) {
    bool res = false;

    for(std::string::size_type i = 0; i < s.length() - 1; i++) {
        std::string word = s.substr(i, 2);
        std::size_t found = s.find(word, i+2);

        if((found != std::string::npos)) {
            res = true;
            break;
        }
    }

    return res;
}

bool repeatsWithLetterInbetween(const std::string& s) {
    bool res = false;

    for(std::string::size_type i = 0; i < s.length() - 2; i++) {
        if(s[i] == s[i+2]) {
            res = true;
            break;
        }
    }

    return res;
}

int part2() {
    std::ifstream file("input.txt");
    std::string in;
    int count = 0;
    
    while(file >> in)
    {
        if(containsPair(in) && repeatsWithLetterInbetween(in))
            count++;
    }

    return count;
}

int main() {
    std::cout << "Part 1: " << part1() << std::endl;
    std::cout << "Part 2: " << part2() << std::endl;
}