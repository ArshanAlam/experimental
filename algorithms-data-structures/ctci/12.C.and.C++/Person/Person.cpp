/**
 * A C++ Language tutorial from CTCI.6e
 */

#include <iostream>
using namespace std;

// This is hard coded at compile time
# define LIST_NUM_SIZE 3 // defines a macro

class Person {
  // All members are private by default
  const int id;
  int * listNum;
  int cloneNum;

  public:
    /**
     * Constructor that takes two arguments, the person's ID and their name
     */
    Person(int personId, int * nums = NULL) : id(personId), listNum(NULL), cloneNum(0) {
      cout << "Created Person with ID = " << this->getId() << endl;
    }

    /**
     * The destructor (takes NO arguments) and is called on delete or automatically.
     *
     * Destructor is virtual for person because we want subclass destructors to be called
     */
    virtual ~Person() {
      cout << "Deleting Person with ID = " << this->getId() << endl;

      // delete the array of allocated memory
      delete [] listNum;
    }
    
    /**
     * Method to return Person's id
     */
    int getId() {
      return this->id;
    }

    /**
     * This ensures that the subclasses aboutMe() implementation is called
     * instead of this one (due to static binding)
     */
    virtual void aboutMe() {
      cout << "I am person " << this->getId() << "!" << endl;
    }

    /**
     * A pure virtual method that depends on the subclass implementation
     *
     * Note: A pure virtual method makes the class abstract and we cannot instantiate it
     */
    virtual bool addCourse(string s) = 0;

    /**
     *  Sum the given list of numbers
     *
     *  Notice the default parameter in the parameter list
     *
     *  Default parameters occur on the right side of the list and specify
     *  the default values of those parameters (when the user does not provide them)
     */
    int sumListNumbers(int * nums, bool isAdd = true, int length = LIST_NUM_SIZE) {
      int result = 0;
      
      if (this->listNum != NULL) delete[] this->listNum;
      this->listNum = new int[length];

      for (int i = 0; i < length; i++) {
        this->listNum[i] = nums[i];
        if (isAdd) result += this->listNum[i];
        else result -= this->listNum[i];
      }
      
      cout << "Sum from Person " << this->getId() << " " << result << endl;
      return result;
    }

    /**
     * Set the clone number
     */
    void setCloneNum(int n) {
      this->cloneNum = n;
    }

    /**
     * Get the clone number
     */
     int getCloneNum() {
      cout << "Person " << this->getId() << " has clone num " << this->cloneNum << endl;
      return this->cloneNum;
     }
};

/**
 * Class Student inherits from Person
 */
class Student : public Person {
  public:
    Student(int studentId) : Person(studentId) {
      cout << "Created Student with ID = " << this->getId() << endl;
    }

    ~Student() {
      cout << "Deleting Student with ID = " << this->getId() << endl;
    }

    void aboutMe() {
      cout << "I am student " << this->getId() << "!" << endl;
    }

    bool addCourse(string s) {
      cout << "Student " << this->getId() << " added course " << s << endl;
      return true;
    }

    /**
     * Operator Overloading
     *
     * We could produce offsprings using the '+' (plus) operator.
     *
     * two students create another student
     */
    Student operator+(Student & other) {
      Student s = Student(this->getId() * 2 + other.getId() * 2 + 1);
      return s;
    }
};

/**
 * Class Teacher inherits from Person
 */
class Teacher : public Person {
  public:
    Teacher(int teacherId) : Person(teacherId) {
      cout << "Created Teacher with ID = " << this->getId() << endl;
    }

    ~Teacher() {
      cout << "Deleting Teacher with ID = " << this->getId() << endl;
    }

    void aboutMe() {
      cout << "I am teacher " << this->getId() << "!" << endl;
    }

    bool addCourse(string s) {
      cout << "Teacher " << this->getId() << " is going to teach course " << s << endl;
      return true;
    }
};


/**
 * Template allow use to reuse code in a class for different datatypes.
 *
 * Here is a generic linked list that adds items to the front and pops item from the front.
 */
template <class T>
class List {
  typedef struct ListNode_t {
    T data;
    struct ListNode_t * next;
  } ListNode;
  
  ListNode * head;

  public:
    List() : head(NULL) {}
  
    ~List() {
      ListNode * cur = this->head;
      while (cur != NULL) {
        ListNode * next = cur->next;
        delete cur;
        cur = next;
      }
    }

    void addFront(T data) {
      ListNode * node = new ListNode;
      node->data = data;
      node->next = head;
      head = node;
    }

    T rmFront() {
      if (head == NULL) return NULL;
      ListNode * tmp = head;
      T data = tmp->data;
      head = tmp->next;
      delete tmp;
      return data;
    }
};



int main() {
  int * nums = new int[LIST_NUM_SIZE + 1];
  nums[0] = 2;
  nums[1] = -4;
  nums[2] = 6;
  nums[3] = 8;

  Person * p_1 = new Student(1);
  p_1->aboutMe();
  p_1->addCourse("Calculus 1");
  cout << endl;

  Person * p_2 = new Student(2);
  p_2->aboutMe();
  p_2->addCourse("Calculus 1");
  cout << endl;

  Person * p_3 = new Teacher(3);
  p_3->aboutMe();
  p_3->addCourse("Calculus 1");
  p_3->sumListNumbers(nums);
  p_3->sumListNumbers(nums, false);
  p_3->sumListNumbers(nums, false, 2);
  p_3->sumListNumbers(nums, true, 2);
  p_3->sumListNumbers(nums, false, LIST_NUM_SIZE + 1);
  p_3->sumListNumbers(nums, true, LIST_NUM_SIZE + 1);
  cout << endl;

  
  // The offspring of person p_1 and p_2
  // A new offspring is automatically a student
  // The + operator expects 2 student references not pointers

  Student s_1 = *((Student *) p_1);
  Student s_2 = *((Student *) p_2);

  // References: note - s_1_prime is a reference to s_1
  Student & s_1_prime = s_1;

  // However s_1_clone is a copy of s_1 and not the same object
  Student s_1_clone = s_1;

  cout << endl << "References and Pointers" << endl;
  s_1.getCloneNum();
  s_1_prime.getCloneNum();
  s_1_clone.getCloneNum();

  s_1_prime.setCloneNum(9);
  s_1_clone.setCloneNum(99);

  s_1.getCloneNum();
  s_1_prime.getCloneNum();
  s_1_clone.getCloneNum();
  cout << endl;

  
  // Pointer arithmetics
  cout << "Pointer Arithmetics" << endl;
  Person ** personList = new Person*[2];
  personList[0] = p_1;
  personList[1] = p_2;
  Person ** curPerson = personList;
  (*curPerson)->aboutMe();
  curPerson++;  // skip ahead by sizeof(Person *) in the personList
  (*curPerson)->aboutMe();
  cout << endl;

  Student p_4 = s_1 + s_2;
  p_4.aboutMe();
  p_4.addCourse("Grade 01");
  cout << endl;


  // Template example
  cout << "Templates" << endl;
  List<Person *> L;
  if (L.rmFront() == NULL) cout << "Front of the list is empty" << endl;
  L.addFront(p_1);
  L.addFront(p_2);
  L.addFront(p_3);
  L.rmFront()->aboutMe();
  L.rmFront()->aboutMe();
  L.rmFront()->aboutMe();
  if (L.rmFront() == NULL) cout << "Front of the list is empty" << endl;
  L.addFront(p_3);
  cout << endl;

  // delete all allocated memory
  delete p_1;
  delete p_2;
  delete p_3;
  delete[] nums;
  delete[] personList;
  return 0;
}
