#include "WordList.h"

WordList::WordList(std::istream& stream) {
    std::string buffer;
    while (getline(stream, buffer)) {
        for (size_t i = 0; i < buffer.length(); i++) {
            if (isspace(buffer[i])) {
                buffer.erase(i,1);
            } else if (!(isalpha(buffer[i]) && islower(buffer[i]))) {
                break;
            }
        }
        mWords.push_back(buffer);
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const {
    Heap stub(3);
    return stub;
}