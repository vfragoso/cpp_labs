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

#include <iostream>  // Header to print out strings to stdout.

// This binary illustrates the basic use of templates in C++.
// Templates are useful to write code independent of the data types involved.
// For instance, suppose we want to create a function that adds up two
// numbers. The operation to add two numbers is simply a + b, regardless of the
// type of a or b -- they can be integers or floating point values. Templates
// allows the user to define a simple function independent of the types involved
// in the operation. Templates expect the user to call the types using some sort
// of temporary name. For instance, we can define a temporary type
// (e.g., NumberType) so that the compiler knows that the type is not defined
// yet but once the function is called, the user will specify a specific data
// type.
namespace {
template <typename SomeType>
SomeType AddNumbers(const SomeType a, const SomeType b) {
  return a + b;
}

}  // namespace

int main(int argc, char** argv) {
  // Let's use the AddNumbers function with integers.
  // We define two integer variables that are set to const, this means that the
  // compiler knows that once defined they cannot change. In other words, the
  // 'const' prefix tells the compiler that their values cannot changed. If the
  // compiler will complain if the user tries to change the value of the
  // variables after being defined, 
  const int integer_number_1 = 5;
  const int integer_number_2 = 10;
  const int integer_result = AddNumbers<int>(integer_number_1,
                                             integer_number_2);

  std::cout << "Addition result (integers): " << integer_result << std::endl;
  
  // ** Example about attempting to change the value of the variables.
  // Uncomment the following line to generate the compiler error.
  // integer_number_1 = 15;
  // ** End of example about attempting to change the value of the variables.

  // Let's add up two floating point values.
  const float floating_number_1 = 6.0f;
  const float floating_number_2 = 1.0f;
  const float floating_result = AddNumbers<float>(floating_number_1,
                                                  floating_number_2);

  std::cout << "Addition result (float): " << integer_result << std::endl;

  // Can we use templates in classes? Of course! In fact, when we use
  // std::vector<SomeType> or std::map<KeyType, ValueType> we are using
  // templates. Can you imagine if C++ would not have templates? We would
  // have to create a vector for ints, floats, strings, and any other
  // data type that we can imagine.

  // What happens with the code below? Do you think it will compile? Note
  // that we are omiting the template type.
  const float result2 = AddNumbers(floating_number_1, floating_number_2);
  // In this case the compiler sees that the two arguments are two floats,
  // thus SomeType = float and thus is able to deduce the right type of the
  // result.
  return 0;
}
