#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"




int main() {

  struct Box b1,b2;

  

  //ul=(3.4,-5),w=5,h=7
  //ul=(3.2,4.2),w=5.2,h=6.2
  initBox(&b1,3.4,-5,5,7);  
  assertEquals("ul=(3.4,-5),w=5,h=7", boxToString(b1), "boxToString(b1)");

  initBox(&b2,3.14159,6.2831853071, 10.14159, 20.2831853071);
  assertEquals("ul=(3.14,6.28),w=10.14,h=20.28", boxToString(b2), "boxToString(b2)");
  assertEquals("ul=(3,6),w=10,h=20", boxToString(b2,1), "boxToString(b2,1)");
  assertEquals("ul=(3.142,6.283),w=10.142,h=20.283", boxToString(b2,4), "boxToString(b2,4)");
  assertEquals("ul=(3.1416,6.2832),w=10.1416,h=20.2832", boxToString(b2,5), "boxToString(b2,5)");

		   
  return 0;
}
