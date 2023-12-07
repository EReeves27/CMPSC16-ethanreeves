#include "tddFuncs.h"
#include <iostream>

using std::cout;
using std::endl;

std::string listToString(Node *head){
  string s = "";
  while(head){
    s += to_string(head->data) + " ";
    head = head->next;
  }
  return s;
}

void assertEquals(std::string expected, 
		  std::string actual, 
		  std::string message) {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertEquals(Node* expected, 
		  Node* actual, 
		  std::string message) {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertEquals(Node **expected, 
      int size, 
		  Node *actual, 
		  std::string message) {
  bool pass = true;
  int i = 0;
  while(actual){
    if(i == size || actual != expected[i]){
      pass = false;
      break;
    }
    actual = actual->next;
    i++;
  }
  if (pass && i == size) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl 
  << "     Expected: " << expected[i] << " Actual: " << actual << endl
	<< "     Node " << i << " is linked improperly" << endl;
  }
}

void assertNotNull(Node* actual, 
		   std::string message) {
  if (actual == 0) {
    cout << "   FAILED: " << message << endl
	 << "     Pointer should not be NULL" << endl;
  } else {
    cout << "PASSED: " << message << endl;
  }
}

void assertEquals(int expected, 
		  int actual, 
		  std::string message) {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertTrue(bool expression,
		  std::string message) {
  if (expression) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl 
	 << "     Expected true, but was false " << endl;
  }
}

void startTestGroup(std::string name){
  cout << "--------------" << name << "--------------" << endl;
}