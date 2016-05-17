#include <iostream>
#include <memory>
#include <initializer_list>
#include "Vector.h"
#include "Forward_List.h"

int main(){
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
  }
  v.pop_back();
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
  }
  v.push_back(12);
  v.push_back(23);
  std::cout << v.front() << std::endl;
  std::cout << v.back() << std::endl;
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
  }
  v.assign( 66 );
  for(int i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
  }
  std::cout << "Testing []: " << v[3] << std::endl;
  std::cout << "Testing function at(): " << v.at(1) << std::endl;
  std::cout << "Capacity: " << v.capacity() << std::endl;
  v.reserve(50);
  std::cout << "Atual capacity: " << v.capacity() << std::endl;
}
