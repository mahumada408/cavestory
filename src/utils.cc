#include "utils.h"

void Utils::Split(const std::string& txt, std::vector<std::string>& strs, char ch) {
    int ch_position = txt.find(ch);
    int initial_position = 0;
    strs.clear();

    // 5,56,78
    // Loop through the string untill you can't find any occurences of ch.
    while (ch_position != std::string::npos) {
        strs.push_back(txt.substr(initial_position, ch_position - initial_position + 1));
        initial_position = ch_position + 1;
        ch_position = txt.find(ch, initial_position);
    }

    // Add the last one. 
    strs.push_back(txt.substr(initial_position, std::min<int>(ch_position, txt.size() - (initial_position + 1))));
}