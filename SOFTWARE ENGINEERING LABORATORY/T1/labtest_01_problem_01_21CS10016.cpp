/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

// Add Header files
#include <bits/stdc++.h>
using namespace std;
// Add shapes hierarchy codes

class Shape
{
public:
  // pure virtual functions for derived classes
  virtual string getType() = 0;
  virtual float getArea() = 0;
  virtual float getPerimeter() = 0;
};

class RightTriangle : public Shape
{
  // date members
  double base;
  double height;

public:
  // constructor
  RightTriangle(double b, double h) : base(b), height(h)
  {
  }
  // destructor
  ~RightTriangle() {}
  // implementation of getType
  string getType()
  {
    return "Right Triangle";
  }
  // implementation of getArea
  float getArea()
  {
    return 0.5 * base * height;
  }
  // implementation of getPerimeter
  float getPerimeter()
  {
    return base + height + sqrt(base * base + height * height);
  }
};

class Rectangle : public Shape
{
  // date members
  double base;
  double height;

public:
  // constructor
  Rectangle(double b, double h) : base(b), height(h)
  {
  }
  // destructor
  ~Rectangle() {}
  // implementation of getType
  string getType()
  {
    return "Rectangle";
  }
  // implementation of getArea
  float getArea()
  {
    return base * height;
  }
  // implementation of getPerimeter
  float getPerimeter()
  {
    return (base + height) * 2;
  }
};

class Square : public Shape
{
  // date members
  double side;

public:
  // constructor
  Square(double s) : side(s)
  {
  }
  // destructor
  ~Square() {}
  // implementation of getType
  string getType()
  {
    return "Square";
  }
  // implementation of getArea
  float getArea()
  {
    return side * side;
  }
  // implementation of getPerimeter
  float getPerimeter()
  {
    return 4 * side;
  }
};

class Circle : public Shape
{
  // date members
  double radius;

public:
  // constructor
  Circle(double r) : radius(r)
  {
  }
  // destructor
  ~Circle() {}
  // implementation of getType
  string getType()
  {
    return "Circle";
  }
  // implementation of getArea
  float getArea()
  {
    return M_PI * radius * radius;
  }
  // implementation of getPerimeter
  float getPerimeter()
  {
    return 2 * M_PI * radius;
  }
};

// Main code
int main()
{
  vector<Shape *> shapeList;

  int selection = -1;
  while (selection != 0)
  {
    cout << "Choose an option:" << endl;
    cout << "=================" << endl;
    cout << "Enter '0' to quit" << endl;
    cout << "Enter '1 base height' for a right triangle with given base and height" << endl;
    cout << "Enter '2 width length' for a rectangle with given width and length" << endl;
    cout << "Enter '3 side' for a square with given side length" << endl;
    cout << "Enter '4 radius' for a circle with given radius length" << endl;
    cout << "> ";
    cin >> selection;

    if (selection == 1)
    { // Right Triangle case
      double b, h;
      cin >> b >> h;
      shapeList.push_back(new RightTriangle(b, h));
    }
    else if (selection == 2)
    { // Rectangle case
      double b, h;
      cin >> b >> h;
      shapeList.push_back(new Rectangle(b, h));
    }
    else if (selection == 3)
    { // Square case
      double s;
      cin >> s;
      shapeList.push_back(new Square(s));
    }
    else if (selection == 4)
    { // Circle case
      double r;
      cin >> r;
      shapeList.push_back(new Circle(r));
    }
  }

  for (vector<Shape *>::iterator it = shapeList.begin(); // Display
       it != shapeList.end();
       ++it)
  {
    Shape *s = *it;
    cout << s->getType() << ": Area=" << s->getArea() << " Perim=" << s->getPerimeter() << endl;
    delete s;
  }
  return 0;
}