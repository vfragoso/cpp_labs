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

// This binary illustrates the basic use of iterators in C++11.

#include <iostream>  // Header for printing to stdout.
#include <string>
#include <unordered_map>  // Header for std::unordered_map.
#include <utility>
#include <vector>  // Header for using std::vector.

int main(int argc, char** argv) {
  // Let's create a vector and iterate it using iterators.
  // Note that we are initializing the vector from an initialization list.
  std::vector<char> my_chars = {'a', 'b', 'c', 'd', 'e'};
  // Iterators are objects that allow the user to iterate a c++ collection.
  // These collections can be vectors, maps, sets, and others. Iterators
  // behave like points. That is that they can be incremented, decremented, and
  // dereferenced to access the content. This binary will give an example using
  // a vector and an unordered_map.
  // To get an iterator at the beginning of the collection, we call the method
  // begin(). If we desire to get an iterator at the end, we simply call the
  // method end(). The end of a collection does not point to the last entry. It
  // points to the subsequent entry where new data can be stored.
  // Iterators can be compared, for instance, the iterators begin() <= end(), or
  // begin() != end().
  // Note that the iterators require to know the collection and the type it
  // holds.
  std::vector<char>::iterator iterator = my_chars.begin();
  std::vector<char>::iterator ending_iterator = my_chars.end();
  // The for loop will use the iterator that points at the beginning of the
  // vector to access the elements in it.
  std::cout << "Print out the vector:\n";
  for (; iterator != ending_iterator; ++iterator) {
    // To acccess the value of an iterator, we use the dereference operator
    // as if the iterator was a pointer.
    std::cout << *iterator << std::endl;
  }
  // Since iterators act like points, we can change the value of entries.
  // For instance, to change the value of the first entry.
  iterator = my_chars.begin();
  *iterator = 'x';
  // The for loop will use the iterator that points at the beginning of the
  // vector to access the elements in it.
  std::cout << "Print out the vector:\n";
  for (; iterator != ending_iterator; ++iterator) {
    // To acccess the value of an iterator, we use the dereference operator
    // as if the iterator was a pointer.
    std::cout << *iterator << std::endl;
  }

  // Let's create a map and iterate it using iterators.
  std::unordered_map<std::string, int> name_to_id =
      {{"victor", 1}, {"john", 2}};
  // Let's define an iterator for this map. Remember that the iterators must
  // know the structure and the type they point to.
  std::unordered_map<std::string, int>::iterator map_iterator;
  // Let map_iterator point to the begining of the map.
  map_iterator = name_to_id.begin();
  for (; map_iterator != name_to_id.end(); ++map_iterator) {
    // Remember that the internal structure of a map is an std::pair. Recall
    // that std::pair has two members: first and second. Since iterator acts
    // like a pointer we need to use the '->' operator to access the members
    // of the pair. For instance:
    std::cout << "Key=" << map_iterator->first
              << " Value=" << map_iterator->second
              << std::endl;
    // To clarify this, let's make a copy of the pointer pair. To make the copy
    // we declare a pair with the same data type for its members. Then, we
    // dereference the iterator to access the pointed value.
    std::pair<std::string, int> copy_of_pair = *map_iterator;
    std::cout << "Copied Key=" << copy_of_pair.first
              << " Copied Value=" << copy_of_pair.second
              << std::endl;
  }
  return 0;
}
