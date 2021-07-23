#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Person {
    private:
        int age;
        string name;
    protected:
        string surname;
    public:
        Person(int, string); //Constructor
        Person(string, string); //Constructor
        ~Person(); //Destructor
        void read();
        void run();
        void getName();
        void setName(string);
        // virtual void sleep(); Polimorphism method
};

/* 
 - Class inheritance, inheriting public "stuff" from Person class
 - protected attributes or methods can be accessed by inheriting classes
class Student : public Person{

};


void Student : sleep(){
    Person::sleep();
    ...
}
*/


Person::~Person(){ }

Person::Person(int _age, string _name){
    age = _age;
    name = _name;
}

Person::Person(string _name, string _surname){
    name = _name;
    surname = _surname;
}

void Person::getName(){
    cout << name << endl;
}

void Person::setName(string _name) {
    name = _name;
}

void Person::read(){
    cout << name << " is reading a book" << endl;
}

void Person::run(){
    cout << name << " with age " << age << " is running" << endl;
}

int main(){
    Person p1 = Person(45, "John");
    Person p2(20, "Hannah");
    Person p3("Luke", "i'm your father");

    //p1.read();
    //p2.run();
    p3.getName();
    //p1.getName();
    p3.setName("John Doe");
    p3.getName();


    p3.~Person(); //deleting object manually
    
    return 0;
}