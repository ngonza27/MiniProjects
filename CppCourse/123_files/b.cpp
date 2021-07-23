#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void writeFile();
void readFile();
void write_to_file();

int main(){    
    //writeFile();
    write_to_file();
    readFile();
    return 0;
}

void writeFile(){
    ofstream myFile;

    myFile.open("test.txt", ios::out); //opening file

    if(myFile.fail()){
        cout << "File couldn't be opened" << endl;
        exit(1);
    }

    myFile << "This is a sample text1";
    myFile.close();
}

void readFile(){
    ifstream myFile;
    string text;

    myFile.open("test.txt", ios::in);

    if(myFile.fail()){
        cout << "File couldn't be opened" << endl;
        exit(1);
    }

    while(!myFile.eof()){
        getline(myFile, text);
        cout << text << endl;
    }

    myFile.close();
}

void write_to_file(){
    ofstream myFile;
    string text;

    myFile.open("test.txt", ios::app);
    
    if(myFile.fail()){
        cout << "File couldn't be opened" << endl;
        exit(1);
    }

    getline(cin, text);
    myFile << text;
    myFile.close();
}