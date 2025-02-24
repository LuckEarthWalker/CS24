#include "WordList.h"
#include <cmath>

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
    Heap candidates(maxcount);
    for (std::string buffer : mWords) {
        if (buffer.length() == points.size()) {
            double s_sum = 0;
            for (size_t i = 0; i < points.size(); i++) {
                double d = pow(pow(points[i].x-QWERTY[buffer[i]-'a'].x, 2) + pow(points[i].y-QWERTY[buffer[i]-'a'].y, 2), .5); //pythagoran theorem
                s_sum += 1/(10*pow(d,2)+1);
            }
            candidates.push(buffer, (float)(s_sum/points.size()));
        }
    }
    while (candidates.top().score < cutoff) {
        candidates.pop();
    }
    Heap stub(3);
    return stub;
}