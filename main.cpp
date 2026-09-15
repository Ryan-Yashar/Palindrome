#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char* stripNonAlphanumeric(char *readin) {
  //make another array in heap to store the punctuation-free string. create a pointer to index it
  char *readout = new char[81];
  int readoutptr = 0;
  //run through readin to remove all the punctuation
  for (int i = 0; readin[i] != '\0'; i++) {
    //ugly-looking but just checks if the char is in either the A-Z, a-z, or 0-9 ranges in ascii. makes char lowercase if it is in the uppercase range.
    if ((readin[i] > 47 && readin[i] < 58) || (readin[i] > 64 && readin[i] < 91) || (readin[i] > 96 && readin[i] < 123)) {
      if (readin[i] > 64 && readin[i] < 91) {
	readout[readoutptr] = readin[i]+32;
      } else {
	readout[readoutptr] = readin[i];
      }
      readoutptr += 1;
    }
  }
  //puts a null char at the end of the string, and returns the output
  readout[readoutptr] = '\0';
  return readout;
}

bool palindromeChecker(char *readin) {
  //sets up 2 pointers, 1 at the beginning of readin and 1 at the end
  int startptr = 0;
  int endptr = strlen(readin)-1;
  //init first pointer, checks at each iteration if the two pointers have met or the value at p1 is different from the value at p2
  for (startptr = 0; startptr < endptr && readin[startptr] == readin[endptr]; startptr++, endptr--) {}
  //checks if the pointers met
  if (startptr >= endptr) {
    return true;
  } else {
    return false;
  }
}

int main() {
  //create new array in heap, with pointer pointing to it
  char *readin = new char[81];
  char *readinptr = readin;
  //get 80 characters plus a null char and put in readin
  cin.get(readin, 81);
  //remove non-alphanumeric chars
  readin = stripNonAlphanumeric(readin);
  //delete the old list, saving 81 bytes of memory. not really necessary :P
  delete[] readinptr;
  //checks if the string is a palindrome, then reads out the result.
  bool is_palindrome = palindromeChecker(readin);
  if (is_palindrome) {
    cout << "Is a palindrome.";
  } else {
    cout << "Not a palindrome.";
  }
  return 0;
}
