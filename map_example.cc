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
// std::map using C++11 features efficiently.
//
// Notes:
//
// 1. The map stores pairs of a key and its corresponding value, i.e., a pair
// (key, value).
// 2. Memory is handled dynamically for us.

#include <iostream>  // Header for printing to stdout.
#include <map>  // Header for using std::set.
#include <string>  // Header for using std::string.
#include <utility>  // Header for using std::pair.

int main(int argc, char** argv) {
  // Declaration of a map requires to types, the key and the value.
  std::map<std::string, int> user_name_to_user_id;
  // The idea of this map is to get the user id given the user name. The map can
  // be viewed as a dictionary (e.g., as in Python).
  // Inserting into the map example.
  int user_id = 1;
  user_name_to_user_id["victor"] = user_id;
  user_name_to_user_id["john"] = ++user_id;
  // When inserting an entry, the key value goes inside the square brackets.
  // The value then is assigned using the = operator. When this operation is
  // successful, the map stores an std::pair<int, std::string> instance. This
  // pair has two members, the first member contains the key, and the second
  // contains the value.
  
  // At this stage this map has two elements. This is how we can iterate the
  // map.
  for (std::pair<std::string, int> entry : user_name_to_user_id) {
    std::cout << "Key=" << entry.first
              << " Value=" << entry.second << std::endl;
  }
  // The range for loop iterates over the pairs in the map, makes a copy into
  // entry at every iteration.

  // Finding elements in the map. Say we want to find the a user name in the
  // map. Very similarly to the set, we will use iterators for this. If the
  // returned iterator is equals to std::map::end() then the entry is not in the
  // map, if it is different, then the entry is in the map.
  std::map<std::string, int>::iterator iterator =
      user_name_to_user_id.find("victor");
  if (iterator == user_name_to_user_id.end()) {
    std::cout << "User name not found." << std::endl;
  } else {
    std::cout << "user_name " << iterator->first
              << " found, user_id=" << iterator->second << std::endl;
  }
  // Note that the iterator "points" to a std::pair, which its first member is
  // the key and the second member is the value.
  // Let's search for a non-existing entry.
  iterator = user_name_to_user_id.find("aladin");
  if (iterator == user_name_to_user_id.end()) {
    std::cout << "User name not found." << std::endl;
  } else {
    std::cout << "user_name " << iterator->first
              << " found, user_id=" << iterator->second << std::endl;
  }
  return 0;
}
