#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char* stripNonAlphanumeric(char *readin) {
  char *readout = new char[81];
  int readoutptr = 0;
  for (int i = 0; readin[i] != '\0'; i++) {
    if ((readin[i] > 47 && readin[i] < 58) || (readin[i] > 64 && readin[i] < 91) || (readin[i] > 96 && readin[i] < 123)) {
      readout[readoutptr] = readin[i];
      readoutptr += 1;
    }
  }
  readout[readoutptr] = '\0';
  return readout;
}

bool palindromeChecker(char *readin) {
  int endofreadin;
  for (endofreadin=0; readin[endofreadin] != '\0'; endofreadin++) {}
  int endptr = endofreadin-1;
  for (int startptr = 0; startptr < endptr && readin[startptr] == readin[endptr]; startptr++, endptr--) {}
  if ((endofreadin)/2 >= endptr) {
    return true;
  } else {
    return false;
  }
}

int main() {
  char *readin = new char[81];
  char *readinptr = readin;
  cin.get(readin, 81);
  readin = stripNonAlphanumeric(readin);
  delete[] readinptr;
  bool is_palindrome = palindromeChecker(readin);
  if (is_palindrome) {
    cout << "Is a palindrome.";
  } else {
    cout << "Not a palindrome.";
  }
  return 0;
}
