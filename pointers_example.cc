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
#include <vector>  // Header to use std::vector.

// This binary illustrates the use of pointers.
int main(int argc, char** argv) {
  // Let us define a variable and store 4 in it.
  int my_variable = 4;
  // Where is this variable in memory? In other words, how can we get the
  // address of this variable? The answer is with the use of pointers and
  // and the '&' operator.
  int* my_variable_ptr = &my_variable;
  // The '&' operator retrieves the memory address of the variable next to it.
  // The address is stored in the pointer my_variable_ptr. Note that the pointer
  // knows the datatype that the memory address holds/stores. That is why we
  // use int*. The '*' tells the compiler that we are using a pointer.
  // Thus, pointers store addresses and they know the datatype that the memory
  // stores at the known address.
  // This means that we can access the value of that variable via the pointer.
  // To do so, we need to dereference the pointer. To dereference the pointer
  // we use the unary '*' operator. Note that the operator expects a pointer.
  std::cout << "Value accessed via the pointer: " << *my_variable_ptr
            << std::endl;
  // What happens if we assign a different value to our variable? does the
  // pointer will access the change?
  my_variable = 5;
  std::cout << "Value accessed via the pointer: " << *my_variable_ptr
            << std::endl;
  // Can we change the value of the variable using the pointer? The answer is
  // yes! That is why pointers are so powerful! To change the value via the
  // pointer we use the dereference operator again.
  *my_variable_ptr = 7;
  std::cout << "Value accessed via the pointer: " << *my_variable_ptr
            << std::endl;
  // What happens if I forget to dereference the pointer in order to access the
  // value of the memory? Remember, the pointer stores addresses. Thus, if we
  // forget to dereference, then the pointer will use the value as an address.
  my_variable_ptr = 0;  // Setting the address to 0 -- aka null pointer.
  // What happens if we dereference a null pointer? Uncomment the line below to
  // find out!
 
  // std::cout << "Value accessed via the pointer: " << *my_variable_ptr
  //           << std::endl;

  // Why does that happen? We are pointing to address 0. Remember that the OS
  // knows the valid range of memory that we can use. In this case the address
  // at cero is not valid and we do not have access.
  // Can we re-use the same pointer to point to a different variable?
  int my_second_variable = 100;
  my_variable_ptr = &my_second_variable;
  std::cout << "Value accessed via the pointer: " << *my_variable_ptr
            << std::endl;
  // What if I try to point to a variable with different type? Find out by
  // uncommenting the code below.

  // float my_float_variable = 3.0;
  // my_variable_ptr = &my_float_variable;

  // Note: Good compilers will see that my_variable_ptr only points to integer
  // variables and will produce compilation errors.

  // Can a pointer get the address of anything? The answer is yes! We can point
  // to anything that our program has access to; the OS limits the range of
  // memory we can access for security reasons.
  // Let's create a vector.
  std::vector<int> my_vector = {1, 2, 3, 4};
  // Let's create a pointer for our vector.
  std::vector<int>* my_vector_ptr = &my_vector;
  // Note that the '&' was used again to get the address of the vector.
  // Can we access the values of the vector? Of course! But wait, the vector is
  // an object. How do we access its members and its member functions? This can
  // be accessed by using the '->' operator.
  std::cout << "Size of the vector: " << my_vector_ptr->size() << std::endl;
  // What happens if the vector changes, and then access the vector using the
  // pointer?
  my_vector.push_back(5);
  std::cout << "Size of the vector: " << my_vector_ptr->size() << std::endl;
  // As long as the pointer still points to the vector we modified, then we will
  // see the changes.
  // Can we also modifiy the vector via the pointer? Of course! We can do it in
  // two different ways. Remember, we can dereference as in the integer variable
  (*my_vector_ptr).push_back(6);
  // Note that I use (*my_vector_ptr), this tells C++ to dereference first and
  // then call the member function. The dereference essentially acts like a
  // variable. This means that when we dereference *my_vector_ptr, the returned
  // value is essentially as if we were using the variable's name directly.
  // Another way to access the vector is via the '->'.
  my_vector_ptr->push_back(7);
  std::cout << "Size of the vector: " << my_vector_ptr->size() << std::endl;

  // What else can we do with pointers? Another useful case is iterating over
  // arrays! Let's see an example:
  char my_array[] = {'h', 'e', 'l', 'l', 'o'};
  // Let's have a pointer to the array. It turns out that the name of the array
  // in C and C++ is a pointer! The pointer points to the first entry in the
  // array. Thus, we can actually use the array using the array name as a
  // pointer.
  std::cout << "First element in array: " << *my_array << std::endl;
  // This means that if we increment one address to our pointer we should access
  // the second element in the array.
  char* my_array_ptr = my_array;  // Copies pointer to pointer or addresses.
  ++my_array_ptr;  // Increment 1 to the address -> move to next element.
  std::cout << "Second element in array: " << *my_array_ptr << std::endl;
  // Since this is possible, the we can iterate the array by just using the
  // pointer.
  // Let's get the array size; this only works with arrays initialized as above.
  const int array_size = sizeof(my_array) / sizeof(my_array[0]);
  // Let's point to the begining of the array.
  my_array_ptr = my_array;
  for (int i = 0; i < array_size; ++i) {
    std::cout << "Address (hex): " << static_cast<void*>(my_array_ptr)
              << " Value: " << *my_array_ptr
              << std::endl;
    ++my_array_ptr;
  }
  // Pointers are very powerful! But with great power it comes great
  // responsibility. As you can see, if we get the pointer of anything and know
  // the datatype it points to, then we have full control over that variable.
  return 0;
}
