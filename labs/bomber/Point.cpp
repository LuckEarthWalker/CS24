#include "Point.h"

std::ostream& operator << (std::ostream& stream, const Point& point) {
  return stream << '(' << point.lat << ", " << point.lng << ')';
}

std::istream& operator >> (std::istream& stream, Point& point) {
  return stream >> point.lat >> point.lng;
}

bool operator == (Point pt1, Point pt2) {
  if (pt1.lat == pt2.lat && pt1.lng == pt2.lng) {
    return true;
  } else {
    return false;
  }
}