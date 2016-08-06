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
// std::vector using C++11 features efficiently.
//
// Notes:
//
// 1. std::vector requires the inclusion of vector header.
// 2. Think of the std::vector as a dynamic array. Internally, the class takes
// control of the memory required to store elements.
// 3. The std::vector keeps a contiguous memory array. This means that elements
// are stacked up in memory. Unlike other structures (e.g., lists) which contain
// pointers to blocks of memory storing each of the entries.
// 4. Prefer vector to lists because the vector keeps everything using a
// contiguous chunk of memory. Modern CPUs work more efficiently if the data is
// stored in a contiguous array. Clearly, this will lead to fast computations.
// 5. Always allocate memory for the vector, even if you exceed what is needed.
// This allows the computer to be more efficient since the goal is to minimize
// the number of times a std::vector reallocates memory.

#include <iostream>  // Header for printing to stdout.
#include <vector>  // Header for using std::vector.

int main(int argc, char** argv) {
  const int kNumElements = 10;
  // Constructs a vector with 10 integers.
  // This means, that the vector allocated memory for 10 integers (first
  // argument of constructor) and sets the elements to 0 (second argument).
  const int kInitialValue = 0;
  std::vector<int> my_vector(kNumElements, kInitialValue);

  // 1. Accessing a vector.
  // Print out the elements of the vector to the console using the regular
  // for-loop. Note that the increment uses the ++ unary operator as a prefix
  // increment. This avoids temporay variables that the compiler automatically
  // generates.
  for (int i = 0; i < my_vector.size(); ++i) {
    std::cout << my_vector[i] << std::endl;
  }
  // Print out the elements of the vector to the console using the range-based
  // for-loop. This syntax is only available since C++11.
  std::cout << "Print vector 1:\n";
  for (const int i : my_vector) {
    std::cout << i << std::endl;
  }

  // 2. Allocating memory for and inserting elements into a vector.
  std::vector<int> my_vector2;  // Empty vector.
  my_vector2.reserve(kNumElements);  // Reserves memory to fit kNumelements.
  for (int i = 0; i < kNumElements; ++i) {
    // Insert elements at the end of the vector.
    my_vector2.push_back(i);
  }
  // Print out the elements of the vector to the console using a plain for-loop.
  // Note we are using the [] to access the i-th element of the vector, as in
  // a plain array.
  std::cout << "Print vector 2:\n";
  for (int i = 0; i <  my_vector2.size(); ++i) {
    std::cout << my_vector2[i] << std::endl;
  }
  // Try to avoid the following scenario.
  std::cout << "Size before: " << my_vector2.size() << std::endl;
  my_vector2.push_back(1000);
  my_vector2.push_back(1001);
  std::cout << "Size after insertion: " << my_vector2.size() << std::endl;
  // Why? What happens is that my_vector2 only allocated memory to store
  // kNumElements However, since we inserted two new elements '1000' and '1001'
  // the vector does the following operations:
  // a) my_vector2 first allocates a new block of memory to fit more data. This
  // reallocation occurs automatically and allocates a bit more of what we need
  // to avoid reallocating memory every time we insert new elements.
  // b) After reallocation, the vector copies the past elements we inserted into
  // the new buffer. Then it inserts the new elements.
  // This operation becomes expensive if insertion of new elements occurs often.
  // The expensive operation is allocation of new buffers and the copying of the
  // elements. This might not be much of a problem using plain old data types
  // (e.g., int, float, char, double). When the vector stores objects, the cost
  // of copying objects might be expensive making the program slow.

  // 3. Resizing a vector.
  my_vector2.resize(2 * kNumElements);
  // This operation will execute the steps (a) and (b).

  // 4. Creating a vector with a different type. Note that the type goes inside
  // the angle brackets (<, >). This is because the class vector is a template
  // class; see advanced c++ examples for tempaltes. The idea is to reuse code
  // of the std::vector for any type. Otherwise, we would have to have a vector
  // for every possible type.
  std::vector<char> my_char_vector;
  // Reserve memory for kInitialValue2 elemements. Note that memory is not
  // initialized with any value and thus the memor might have random values.
  const int kInitialValue2 = 10;
  my_char_vector.reserve(kInitialValue2);
  char letters[] = {'a', 'b', 'c', 'd', 'e'};
  const int kLettersArraySize = 5;
  for (int i = 0; i < kLettersArraySize; ++i) {
    my_char_vector.push_back(letters[i]);
  }
  // Print out the elements of the vector to the console using a plain for-loop.
  // Note we are using the [] to access the i-th element of the vector, as in
  // a plain array. What is the size of the vector? Is it 5 or 10?
  std::cout << "Print vector 2:\n";
  for (int i = 0; i <  my_char_vector.size(); ++i) {
    std::cout << my_char_vector[i] << std::endl;
  }
  // Just to clarify, reserving memory does not mean that the size of the vector
  // is the same amount of elements we reserved memory for. Reserve only
  // allocates memory to hold the number of elements we requested.
  // Print out the capacity (the maximum number of elements it can hold without
  // reallocating more memory) of the vector.
  std::cout << "Size of vector: " << my_char_vector.size()
            << " capacity: " << my_char_vector.capacity() << std::endl;
  // Re-assigning values using square brackets or the method at().
  my_char_vector[0] = 'z';
  my_char_vector.at(2) = 'q';
  std::cout << "Print vector 2:\n";
  for (int i = 0; i <  my_char_vector.size(); ++i) {
    std::cout << my_char_vector[i] << std::endl;
  }
  return 0;
}
