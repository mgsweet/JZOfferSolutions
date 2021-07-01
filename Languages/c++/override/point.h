#ifndef OVERRIDE_POINT_H
#define OVERRIDE_POINT_H

#include <iostream>

class Point {
public:
  Point(int x, int y): x_(x), y_(y) {};
  Point operator-() const; // -p
  Point operator+(const Point & point) const; // p1 + p2
  Point operator-(const Point & point) const; // p1 - p2
  Point & operator+=(const Point & point); // p1 += p2
  Point & operator-=(const Point & point); // p1 -= p2
  const Point operator++(int); // p++
  Point & operator++(); // ++p
  const Point operator--(int); // p--
  Point & operator--(); // --p
  friend std::ostream & operator<<(std::ostream & os, const Point& point);
private:
  int x_, y_;
};

Point Point::operator+(const Point &point) const {
  return Point(x_ + point.x_, y_ + point.y_);
}

Point Point::operator-(const Point &point) const {
  return *this + -point;
}

Point Point::operator-() const {
  return Point(-x_, -y_);
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
  return os << "point(" << point.x_ << ", " << point.y_ << ')';
}

Point &Point::operator+=(const Point &point) {
  x_ += point.x_;
  y_ += point.y_;
  return *this;
}

Point &Point::operator-=(const Point &point) {
  return *this += (-point);
}

Point &Point::operator++() {
  this->x_++;
  this->y_++;
  return *this;
}

Point &Point::operator--() {
  this->x_--;
  this->y_--;
  return *this;
}

const Point Point::operator++(int) {
  Point temp = Point(x_, y_);
  x_++;
  y_++;
  return temp;
}

const Point Point::operator--(int) {
  Point temp = Point(x_, y_);
  x_--;
  y_--;
  return temp;
}


#endif //OVERRIDE_POINT_H
