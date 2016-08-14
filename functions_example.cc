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

#include <iostream>  // Header to print to stdout.

// Declaration of a function.
// This function adds two numbers. The name of the function is Add.
// The function returns an integer and receives two integers.
// The signature has the followin structure then:
// <ReturnType> <FunctionName>(Type1 argument1, ..., TypeN argumentN)
int Add(const int number_1, const int number_2);

// Example of a function that does not return a result.
// Note here that the return type is void and that the list of arguments
// is empty.
void Greet();

// We can define the function directly as well.
int Subtract(const int number_1, const int number_2) {
  return number_1 - number_2;
}

int main(int argc, char** argv) {
  // To invoke a function we write the following code.
  const int result = Add(4, 3);
  std::cout << "Addition Result: " << result << std::endl;
  // Invoke a function.
  Greet();
  // Invoke another function.
  std::cout << "Subtract Result: " << Subtract(4, 3) << std::endl;
  return 0;
}

// Function definitions.
int Add(const int number_1, const int number_2) {
  return number_1 + number_2;
}

void Greet() {
  std::cout << "Hello!" << std::endl;
}
