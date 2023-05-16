// Add Header files
// Add shapes hierarchy codes


// Main code
int main()
{
  vector<Shape *> shapeList;

  int selection = -1;
  while(selection != 0){
    cout << "Choose an option:" << endl;
    cout << "=================" << endl;
    cout << "Enter '0' to quit" << endl;
    cout << "Enter '1 base height' for a right triangle with given base and height" << endl;
    cout << "Enter '2 width length' for a rectangle with given width and length" << endl;
    cout << "Enter '3 side' for a square with given side length" << endl;
    cout << "Enter '4 radius' for a circle with given radius length" << endl;
    cout << "> ";
    cin >> selection;
    
    if(selection == 1){                                   // Right Triangle case
      double b, h;
      cin >> b >> h;
      shapeList.push_back(new RightTriangle(b,h));
    }
    else if(selection == 2){                              // Rectangle case
      double b, h;
      cin >> b >> h;
      shapeList.push_back(new Rectangle(b,h));
    }
    else if(selection == 3){                              // Square case
      double s;
      cin >> s;
      shapeList.push_back(new Square(b,h));
    }
    else if(selection == 4){                              // Circle case
      double r;
      cin >> r;
      shapeList.push_back(new Circle(b,h));
    }
  }

  for (vector<Shape *>::iterator it = shapeList.begin() ; //Display
       it != shapeList.end(); 
       ++it)
    {
      Shape *s = *it;
      cout << s->getType() << ": Area=" << s->getArea() << " Perim=" << s->getPerimeter() << endl;
      delete s;
    }
  return 0;
}