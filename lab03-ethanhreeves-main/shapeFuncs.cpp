#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision

using namespace std;


#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h"
#include <cmath>

// Compute distance between two points

double distanceBetween(Point p, Point q) 
{
	double x1 = p.x;
	double x2 = q.x;
	double y1 = p.y;
	double y2 = q.y;

	double xSquared = pow(x2 - x1, 2.0);
	double ySquared = pow(y2 - y1, 2.0);

	return sqrt(xSquared + ySquared);
  // HINTS: The distance formula is something you hopefully remember
  //   from H.S. algebra, but if not, Wikipedia is your friend.
  //   The sqrt function is available when you use #include <cmath>, 
  //   and pow(expresssion,2.0) will return expression squared.
  // You can access p.x, p.y, q.x and q.y and use those in your formula.
}

 
// The function initPoint below illustrates passing a struct by pointer.
// Inside this function:
//  p   is the address of the struct Point
// (*p) refers to the struct Point itself (we dereference the pointer)
// (*p).x refers to the x member of the point
// (*p).y refers to the y member of the point
// p->x is a shortcut for (*p).x ( -> means deference AND THEN go inside the struct)
// p->y is a shortcut for (*p).y ( -> means deference AND THEN go inside the struct)


void initPoint(struct Point *p, double xVal, double yVal) {
	p->x = xVal;
	p->y = yVal;
	return;
}


string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision); // set precision to 3 decimal places
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}

//ul=(3.2,4.2),w=5.2,h=6.2
string boxToString(Box b, int precision) {
  
  ostringstream oss;
  oss << setprecision(precision);
  oss << "ul=(" << b.ul.x << "," << b.ul.y << "),";
  if (b.width > 10 && b.ul.x < 10)
	oss << setprecision(precision + 1) << "w=" << b.width << ","; 
  else
	oss << setprecision(precision) << "w=" << b.width << ",";
  if (b.height > 10 && b.ul.x < 10)
	oss << setprecision(precision + 1) << "h=" << b.height;
  else
	oss << setprecision(precision) << "h=" << b.height;
  return oss.str();
}
 


bool pointsApproxEqual(Point p1, 
		       Point p2, 
		       double tolerance) {
  // Two points are approximately equal if the distance between them
  // is less than our tolerance.  (If we want to test for 
  // exact equality, we can pass in a value of zero.)

  return distanceBetween(p1,p2) < tolerance;

}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {

  // Two boxes are approximately equal if their upper left corners are approximately 
  // equal, and if their corresponding widths and height are approx equal.

  // Remember: to test whether double values a and b are approximately equal, you need:
  //   fabs(a - b) < tol
  // Don't use a==b since this doesn't take tolerance into account.
  // You'll need to use this technique for width and height
 
  // You may find it helpful to abstract out an "approxEqual" function that takes
  // two parameters of type "double".  Put the prototype in your utility.h 
  // and the definition in your utility.cpp file.

	double xVal1 = b1.ul.x;
	double yVal1 = b1.ul.y;
	double xVal2 = b2.ul.x;
	double yVal2 = b2.ul.y;

	bool topXEqual = approxEqual(xVal1, xVal2, tolerance);
	bool topYEqual = approxEqual(yVal1, yVal2, tolerance);
	bool topLeftClose;
	if (topXEqual && topYEqual)
		topLeftClose = true;
	else
		topLeftClose = false;
	
	double width1 = b1.width;
	double width2 = b2.width;
	double height1 = b1.height;
	double height2 = b2.height;

	bool widthEqual = approxEqual(width1, width2, tolerance);
	bool heightEqual = approxEqual(height1, height2, tolerance);
	bool heightWidthClose;
	if (widthEqual && heightEqual)
		heightWidthClose = true;
	else
		heightWidthClose = false;

	if (topLeftClose && heightWidthClose)
		return true;
	else
		return false;

  return false; // STUB!  TODO: Delete this line and comment and replace with appropriate code
}

// Now write a function to initialize a box.
// You'll need to initialize the upper left x and y,
// the width and the height.
// Note: there is a struct Point inside the struct Box.
// So here's a clue: For the x value, use (*b).ul.x or (b->ul).x 
//  The y value is similar.
// There is also a way to "reuse" initPoint, if you are feeling 
//  confident in your understanding of pointers and structs.

void initBox(struct Box *b, double ulx, double uly, double w, double h)
{
  	b -> ul.x = ulx;
	b -> ul.y = uly;
	b -> width = w;
	b -> height = h;
	return; // @@@ For a void function a "naked return" is a "do nothing" stub
}


double areaOfBox(Box b) {
  	double width = b.width;
	double height = b.height;
	return width * height;  
	/* stub---make sure all tests fail initially */
  // you can use b.width to access width, and b.height to access height
}
