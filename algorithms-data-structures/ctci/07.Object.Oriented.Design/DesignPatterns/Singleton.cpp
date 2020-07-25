/**
 * The singleton design pattern.
 */

#include <iostream>
using namespace std;

class Singleton {
  private:
    static Singleton * instance;
    Singleton();
  public:
    ~Singleton();
    static Singleton * getInstance();
};

Singleton * Singleton::instance = NULL;

Singleton::Singleton() {
  cout << "Singleton Created" << endl;  
}

Singleton::~Singleton() {
  cout << "Singleton Destroyed" << endl;  
}

Singleton * Singleton::getInstance() {
  if(Singleton::instance == NULL) {
    Singleton::instance = new Singleton(); 
  }
  return Singleton::instance;
}

int main() {
  // The first call getInstance will print "Singleton Created"
  Singleton * instance_ptr1 = Singleton::getInstance();
  // The second call to getInstance simply returns the pointer
  Singleton * instance_ptr2 = Singleton::getInstance();

  // Destroy the only Singleton
  delete instance_ptr1;
  return 0;
}
