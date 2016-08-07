// Copyright (C) 2016 West Virginia University.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//
//     * Neither the name of West Virginia University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Please contact the author of this library if you have any questions.
// Author: Victor Fragoso (victor.fragoso@mail.wvu.edu)

// This binary shows tips on how to use basic and common operations of a
// std::unordered_set using C++11 features efficiently.
//
// Notes:
//
// 1. The set mimics the mathematical set. That is, it only stores unique
// elements.
// 2. Memory is also handled dynamically for us.
// 3. Main difference between set and unordered set. The latter uses hashes
// to localize quickly elements. The hashes help quickly determine if an element
// is in a set very efficiently. The unordered set is only available since
// C++11.
// 4. The interface of a set and an unordered set is almost identical.
// 5. For non-native objects in C++ (e.g., user-defined classes), the
// unordered_set requires a hasher object. Creating a hasher for user-defined
// data types is out of the scope of this lab.

#include <iostream>  // Header for printing to stdout.
#include <unordered_set>  // Header for using std::unordered_set.

int main(int argc, char** argv) {
  // Declaration of a unordered_set is very similar to a vector.
  std::unordered_set<int> my_integers_set;
  // Let's insert elements into the set from an array.
  int integers[] = {2, 1, 3, 2, 3, 1};
  // A neat trick to get the size of arrays.
  const int kArraySize = sizeof(integers) / sizeof(integers[0]);
  for (int i = 0; i < kArraySize; ++i) {
    my_integers_set.insert(integers[i]);
  }
  // Let's print out the contents of set.
  std::cout << "Elements of set\n";
  for (int element : my_integers_set) {
    std::cout << element << std::endl;
  }
  std::cout << "Set size: " << my_integers_set.size() << std::endl;
  // Sets are useful to search elements. However, it requires knowledge of
  // iterators. See iteratorsexample.cc to see more examples about iterators.
  // Say we want to see if the number 5 is in the set.
  // The set returns an iterator different than std::set::end() when the element
  // is present in the set, and returns std::set::end() otherwise.
  // Let's search for an element not in the set.
  std::unordered_set<int>::iterator iterator = my_integers_set.find(5);
  if (iterator == my_integers_set.end()) {
    std::cout << "Element not found in set" << std::endl;
  } else {
    std::cout << "Element found in set" << std::endl;
  }
  // Let's search for an element in the set.
  iterator = my_integers_set.find(1);
  if (iterator == my_integers_set.end()) {
    std::cout << "Element not found in set" << std::endl;
  } else {
    std::cout << "Element found in set" << std::endl;
  }
  // Note that the elements are sorted. This is because the set exploits
  // the ordering property to organize the elements and remove duplicates.
  // To erase elements we need to understand what iterators are, see
  // iterators_example.cc for explanation and illustration of iterators.
  // To erase one element from the set, we need to obtain an iterator first to
  // that element and pass the iterator as the element to erase.
  my_integers_set.erase(iterator);
  // Let's verify that it erased the element, in this case will erase 1 since
  // iterator is "pointing" to it.
  iterator = my_integers_set.find(1);
  if (iterator == my_integers_set.end()) {
    std::cout << "Element not found in set" << std::endl;
  } else {
    std::cout << "Element found in set" << std::endl;
  }
  // Let's print out the contents of set.
  std::cout << "Elements of set\n";
  for (int element : my_integers_set) {
    std::cout << element << std::endl;
  }
  std::cout << "Set size: " << my_integers_set.size() << std::endl;
  return 0;
}
