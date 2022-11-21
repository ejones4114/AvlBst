//
//  main.cpp
//  AVLBST
//
//  Created by Eric Jones on 11/20/22.
//

#include <iostream>
#include "AvlBst.cpp"

class Cat {
   
   int age;
public:
   
   Cat() { age = 0; }
   
   Cat(int age) {
      this->age = age;
   }
   bool operator==(const Cat &c) {
      return this->age == c.age;
   }
   bool operator<(const Cat &c) {
      return this->age < c.age;
   }
   bool operator>(const Cat &c) {
      return this->age > c.age;
   }
   
   friend std::ostream& operator<<(std::ostream& os, const Cat& obj) {
      return os << obj.age;
   }
   
};

int main(int argc, const char * argv[]) {

   AvlBst<int> tree;
   AvlBst<Cat> catTree;
   for(int i = 0; i < 100000; i++) {
      catTree.insert(Cat(i));
   }
   
   std::cout << "Tree height is " << catTree.getHeight();
   
   return 0;
}
