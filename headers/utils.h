#pragma once

#include <string>
#include <vector>

class Utils {
    public:
        // Split a string <txt> everywhere a certain character <ch> is found, 
        // and store the resulting substrings in a vector <strs>.
        static void Split(const std::string& txt, std::vector<std::string>& strs, char ch);
};