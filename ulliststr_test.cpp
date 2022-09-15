/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;

/*
	Object must have operator== and cout functionality
*/
template <typename Object>
void ULListStr::test(int& tests, int& passed, std::string testname, Object output, Object expected)
{
	tests++;
	cout << "TEST: " << testname << endl;
	if (output == expected) passed++;
	cout << boolalpha << "Expected: " << expected << " / Actual: " << output << "\n\n";
}

int main(int argc, char* argv[])
{
  int tests = 0;
  int passed = 0;
  cout << "\n";

  ULListStr data;

  data.push_front("Hello");

  data.test(tests, passed, "push_front Test 1 (empty list)", data.get(0), (string) "Hello");

  data.pop_back();
  data.push_back("Hello");

  data.test(tests, passed, "push_back Test 1 (empty list)", data.get(0), (string) "Hello");

  data.push_back("World");

  data.test(tests, passed, "push_back Test 2 (unfilled Item)", data.get(1), (string) "World");

  data.pop_back();
  data.push_back("csci104");

  data.test(tests, passed, "pop_back Test 1", data.get(1), (string) "csci104");

  for (int i = 0; i < 3; i++) {data.pop_back();}

  data.test(tests, passed, "pop_back Test 2 (on empty)", data.empty(), true); // nothing bad happens

  data.push_back("The");
  data.push_back("quick");
  data.push_back("brown");
  data.push_back("fox");
  data.push_back("jumps");
  data.push_back("over");
  data.push_back("the");
  data.push_back("lazy");
  data.push_back("dog");
  data.push_back("."); // last of item 0
  data.push_back("Hello"); // first of item 1

  data.test(tests, passed, "push_back Test 3 (full Item)", data.get(10), (string) "Hello");

  data.pop_back();

  data.test(tests, passed, "pop_back Test 3 (Item with 1 val)", data.size(), (size_t) 1);

  data.push_front("!");

  data.test(tests, passed, "push_front Test 2 (full Item)", data.get(0), (string) "!");
  data.test(tests, passed, "push_front Test 2 size (full Item)", data.size(), (size_t) 2);

  data.push_front("Wow");

  data.test(tests, passed, "push_front Test 3 (normal)", data.get(0), (string) "Wow");

  data.pop_front();

  data.test(tests, passed, "pop_front Test 1", data.get(0), (string) "!");

  data.pop_front();

  data.test(tests, passed, "pop_front Test 2 (Item with 1 val)", data.get(0), (string) "The");
  data.test(tests, passed, "pop_front Test 2 size (Item with 1 val)", data.size(), (size_t) 1);

  data.test(tests, passed, "back() test", data.back(), (string) ".");
  data.test(tests, passed, "front() test", data.front(), (string) "The");

  data.test(tests, passed, "final size test", data.size(), (size_t) 1);
  // final state is:
  // The quick brown fox jumped over the lazy dog .
  // in one item
  
  // TOTAL TESTS PASSED
	cout << "\nTOTAL TESTS PASSED: " << passed << " of " << tests << "\n\n";

  return 0;
}
