#include <iostream>

using namespace std;

struct Person {
    char name[20];
    int age;
}
person1 = { "Nicolas", 21 },
person2 = { "Mik", 3 },
person3
;


struct address {
    char street[20];
    int zipcode;
};

struct employee {
    char name[20];
    struct address employee_addr;       
}
employee1 = { "Tom", {"main2", 1}}
;

int main(){
    cout << employee1.employee_addr.street;
    cin >> person3.name;
    cin >> person3.age;
    fflush(stdin); //vaciar el buffer de entrada
    //fflush(stdout);
    cout << "Name: " << person3.name << endl;
    cout << "Age: " << person3.age << endl;
    

    return 0;
}

