#include "strFuncs.h"
#include <cctype>
#include <string>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    int stringSize = s1.length(); //gets length of string

    if (stringSize == 0)
        return true;
    else if (stringSize == 1)
        return true;
    char firstLetter = tolower(s1[0]); //takes first letter to lowercase
    char lastLetter = tolower(s1[stringSize - 1]); //takes last letter to lower case
    if (firstLetter == lastLetter) //compares first and last
    {
        return isPalindrome(s1.substr(1, stringSize - 2)); //if true, pass substring without first and last letters recursively
    }
    else
    {
        return false; //if it ever fails, return false
    }
}
