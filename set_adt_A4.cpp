/* Group A - No. 4

To create ADT that implement the "set" concept.

a. Add (newElement) - Place a value into the set

b. Remove (element) - Remove the value

c. Contains (element) - Return true if element is in collection

d. Size () - Return number of values in collection, Iterator () - Return an iterator used to loop over collection

e. Intersection of two sets

f. Union of two sets

g. Difference between two sets

h. Subset */

#include <iostream>

class Set
{
  int *arr, size;
  public:
  Set()
  {
    size = 10;
    arr = new int[size];
  }
  Set(int n)
  {
    size = n;
    arr = new int[size];
  }
  void add(int newElement);
  void remove(int element);
  bool contains(int element);
  int size();
  Set inter(Set B);
  Set uni(Set B);
  Set differ(Set B);
}

