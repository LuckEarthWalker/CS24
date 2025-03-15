#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
  int lat;  // Latitude
  int lng;  // Longitude

  Point() {
    // Beware of junk values!
  }

  Point(int lat, int lng) {
    this->lat = lat;
    this->lng = lng;
  }

  Point(const Point& other) {
    this->lat = other.lat;
    this->lng = other.lng;
  }

  Point& operator=(const Point& other) = default;
};

// Operators for easier (and consistent) input and output:
std::ostream& operator << (std::ostream& stream, const Point& point);
std::istream& operator >> (std::istream& stream, Point& point);

bool operator == (Point pt1, Point pt2);

#endif
