#include "strFuncs.h"
#include "tddFuncs.h"
using namespace std;

int main() {
    //Tests the isPalindrome function
	startTestGroup("CHECK_IF_A_STRING_IS_A_PALINDROME");
	
	//Standard test cases - if you'd like to add more, just initialize more strings and use assertEquals
	string p1 = "leonseesnoel";
	string p2 = "RaCecAr";
	string p3 = "fail";
	string p4 = "Hanmah";
	string p5 = "abcdba";
	
	//Tests your output against expected result
	assertTrue(isPalindrome(p1), "isPalindrome(p1)");
	assertTrue(isPalindrome(p2), "isPalindrome(p2)");
    	assertTrue(!isPalindrome(p3), "isPalindrome(p3)");
	assertTrue(!isPalindrome(p4), "isPalindrome(p4)");
	assertTrue(!isPalindrome(p5), "isPalindrome(p5)");

}
