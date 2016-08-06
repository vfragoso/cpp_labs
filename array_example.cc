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

// This binary shows an example of how to create an array, iterate the array,
// and access elements of the array.

#include <iostream>  // Header for writing to stdout.

int main(int argc, char** argv) {
  // An array declaration has the following structure:
  // <Type> <ArrayName>[<ConstantSize>];
  // Creating an array of integers that can hold at most 10 integers.
  // C++ expects the size of an array always to be known already to the
  // compiler. This means after creating the array, we cannot expand it
  // or compress it.
  const int kArraySize = 10;
  int my_array[kArraySize];

  // Iterating an array and initializing it.
  std::cout << "Array 1:\n";
  for (int i = 0; i < kArraySize; ++i) {
    // Assigning the i-th entry of the arry to i.
    my_array[i] = i;
    // Printing out the value of the i-th entry.
    std::cout << my_array[i] << std::endl;
  }

  // Initalizing array when creating the array.
  // Notes:
  // 1. The values of the array to be stored are enclosed in a initialization
  // list which is enclosed by curly braces ({, }).
  // 2. The size of the array within the squared brackets is empty. This is
  // because the compiler will count the number of elements in the
  // initialization list and will compute the size automatically for us.
  std::cout << "Array 2:\n";
  char my_array_2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  for (int i = 0; i < kArraySize; ++i) {
    std::cout << my_array_2[i] << std::endl;
  }

  return 0;
}
