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

#include <iostream>  // Header to print out to stdout.
#include <vector>  // Header to use std::vector.

// This binary illustrate the allocation of heap memory (or dynamic memory
// allocation).
int main(int argc, char** argv) {
  // To allocate memory dynamically, we need to use the 'new' operator.
  // Can we allocate memory to store objects? Yes! Imagine we need a vector
  // allocated in the heap.
  std::vector<int>* my_vector = new std::vector<int>;
  // New allocates enough memory to host the vector in the heap. We can access
  // the object via the pointer. For instance, let's initialize the vector.
  for (int i = 0; i < 100; ++i) {
    my_vector->push_back(i);
    std::cout << "Last inserted number: " << my_vector->back() << std::endl;
  }
  // To release the memory, we need to use the delete operator.
  delete my_vector;
  my_vector = nullptr;  // The same as my_vector = 0;

  // Say for instance we want to allocate 100 memory cells for storing
  // integers. In other words, we would like to get an array of size 100
  // but allocated dynamically.
  // To do so, we need to invoke the 'new' operator.
  int* my_array = new int[100];
  // At this point, the new operator alloctated a continuous buffer to
  // store 100 integers. The operator returns a pointer to the beginning
  // of the buffer and we can use it as an array.
  // For example, initialize the array to zero.
  for (int i = 0; i < 100; ++i) {
    my_array[i] = 0;
  }
  // Printing out the initialized array.
  for (int i = 0; i < 100; ++i) {
    std::cout << "Array cell: " << i << " :: value = "
              << my_array[i] << std::endl;
  }
  // Once we are done with the buffer, we need to release the memory. It is
  // a good practice to release it when it is not needed. Otherwise, we will
  // have memory leaks: wasting memory and this will eat the memory of the
  // computer causing issues.
  // To relese the memory we use the delete operator. We need to help the delete
  // operator by telling him that we are going to erase an array by using '[]'.
  delete [] my_array;  // Releases the memory pointed by my_array.
  // It is a good practice to nullify the pointer. This is because we erase
  // the record of the memory address we were using -- this is for security
  // issues that we won't discuss here.
  my_array = nullptr;  // The same as my_array = 0;
  return 0;
}
