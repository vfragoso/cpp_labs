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

namespace {
// Helper class to illustrate references and passing by value.
class DummyObject {
 public:
  // Instance id.
  static int instance_counter;

  // Default constructor.
  DummyObject() {
    instance_id_ = ++instance_counter;
    std::cout << "Created dummy object with id: " << instance_id_ << std::endl;
    state_variable_ = -1;
  }
  // Copy constructor.
  DummyObject(const DummyObject& object) {
    std::cout << "Copying object" << std::endl;
    instance_id_ = object.instance_id_;
  }
  // Assignment operator.
  // See http://en.cppreference.com/w/cpp/language/copy_assignment
  // for more information about overloading this operator.
  DummyObject& operator=(const DummyObject& rhs_object) {
    std::cout << "Copying object" << std::endl;
    instance_id_ = rhs_object.instance_id_;
    return *this;
  }
  // Destructor.
  virtual ~DummyObject() {}

  int instance_id() const {
    return instance_id_;
  }

  int state_variable() {
    return state_variable_;
  }

  void set_state_variable(int state_variable) {
    state_variable_ = state_variable;
  }

 private:
  // The instance id.
  int instance_id_;
  // Dummy state variable.
  int state_variable_;
};

// Initializing static variable.
int DummyObject::instance_counter = 0;

// Function passing by value. This function will call the copy constructor.
// The copy of the argument will be stored in object.
void SomeFunctionByValue(const DummyObject object) {
  std::cout << "Argument: " << object.instance_id() << std::endl;
}

// Function passing by reference. Note that this function does not call a copy
// constructor. In this case, object_ref will be a reference to the argument
// passed by reference when invoking the function. The only difference is using
// the '&' right next to the DataType. This indicates to the compiler that we
// want to use a reference and avoid a copy.
void SomeFunctionByReference(const DummyObject& object_ref) {
  std::cout << "Argument: " << object_ref.instance_id() << std::endl;
}

}  // namespace

int main(int argc, char** argv) {
  DummyObject my_object;
  // The assignment will copy my_object into assigned_object.
  DummyObject assigned_object = my_object;
  // Referenced object. A reference should be interpreted as an alias.
  // In this case ref_object aliasses my_object, and we can even modify its
  // state.
  DummyObject& ref_object = my_object;
  ref_object.set_state_variable(10);
  std::cout << "State variable: " << my_object.state_variable() << std::endl;
  // One of the best uses of references is to avoid passing by value. Passing by
  // value can be expensive. For example, when passing a large std::vector by
  // value will trigger a copy operation, which can significantly impact in
  // performance. However, if we pass that std::vector by reference, we avoid
  // the copy.
  // For example, consider the case of passing by value of Dummy object.
  SomeFunctionByValue(my_object);
  // Note how the copying constructior was executed.
  // If we want to avoid that copy, we need to pass it by reference.
  SomeFunctionByReference(my_object);
  // Consider always passing by reference all the expensive data types (e.g.,
  // objects). Plain old data types (e.g., int, double) are cheap to copy.
  return 0;
}
