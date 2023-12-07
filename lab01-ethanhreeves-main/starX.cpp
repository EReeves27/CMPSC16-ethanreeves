// starX.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starX(int width);
void runTests(void);

string starX(int width)
{
  string result = "";
  int midPoint = width / 2;
  int leftStartPt = 0;
  int rightStartPt = width - 1;
  
  if (width < 3 || width % 2 != 1)
      return result;

  for (int i = 0; i <= midPoint; ++i) { //creating x going down to midpoint
    for (int y = 0; y < width; ++y) { //across the X
      if (y == leftStartPt || y == rightStartPt)
        result += "*";
      else
        result += " ";
    }
    ++leftStartPt;
    --rightStartPt;
    result += "\n";
  }

  leftStartPt -= 2;
  rightStartPt += 2;
  
  for (int i = midPoint + 1; i < width; ++i) { //creating x going down from midpoint
    for (int y = 0; y < width; ++y) { //across the X
      if (y == leftStartPt || y == rightStartPt)
        result += "*";
      else
        result += " ";
    }
    --leftStartPt;
    ++rightStartPt;
    result += "\n";
  }

  return result;
  
}

// Test-Driven Development;
// check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starX3Expected =
      "* *\n"
      " * \n"
      "* *\n";

  assertEquals(starX3Expected, starX(3), "starX(3)");

  string starX5Expected =
      "*   *\n"
      " * * \n"
      "  *  \n"
      " * * \n"
      "*   *\n";

  assertEquals(starX5Expected, starX(5), "starX(5)");

  assertEquals("", starX(0), "starX(0)");
  assertEquals("", starX(2), "starX(2)");
  assertEquals("", starX(4), "starX(4)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

// Main function

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " width" << endl;
    exit(1);
  }

  int width = stoi(argv[1]);
  if (width == -1)
  {
    runTests();
    exit(0);
  }

  cout << starX(width);
  return 0;
}


/* Test code
 string result = "";
  int midPoint = width / 2;
  int leftStartPt = 0;
  int rightStartPt = width;
  
  if (width < 3 || width % 2 != 1)
      return result;

  for (int i = 0; i < width; ++i) { //i represents row number
    
    if (i == midPoint) { //middle of X
      for (int y = 0; y < width; ++y) {
        if (y == midPoint)
            result += "*";
        else
            result += " ";
      }
    }
    result += "\n";
  }
*/
