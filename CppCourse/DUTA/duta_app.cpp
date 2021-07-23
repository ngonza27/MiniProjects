#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

void get_question();
void set_question();
void coin_toss();
void get_random_player(vector<string>, int);
void get_participants(vector<string> &, int);

vector<string> participants;

int main(){
    int number_of_players;
    string temp;
    string aux;
    cout << "How many people are playing?" << endl;
    getline(cin,temp);

    number_of_players = stoi(temp);
    
    get_participants(participants, number_of_players);

    while (true) {
        get_random_player(participants, number_of_players);
        cout << "Press ENTER to get a question" << endl;
        getline(cin,aux);
        get_question();
        cout << "Press ENTER to toss a coin" << endl;
        getline(cin,aux);
        coin_toss();
        cout << "Press Y to add a new question or N to continue" << endl;
        getline(cin,aux);
        if(aux == "Y" || aux == "y"){
            set_question();
        }
    }    
}


void set_question(){
    ofstream myFile;
    string text;

    myFile.open("questions.txt", ios::app);

    if(myFile.fail()){
        cout << "File couldn't be opened" << endl;
        exit(1);
    }
    getline(cin, text);
    text = text + "\n";
    myFile << text;
    myFile.close();
}

void coin_toss(){
    int flip;
    flip = rand() % 2 + 1;
    flip == 1 ? cout << "Heads" << endl : cout << "Tails" << endl;
}


void get_question(){
    string line;
    vector<string> lines;
    ifstream myFile;

    srand(time(0));
    
    myFile.open("questions.txt", ios::in);

    if(myFile.fail()){
        cout << "File couldn't be opened" << endl;
        exit(1);
    }

    int total_lines = 0;

    while(getline(myFile, line)){
        total_lines++;
        lines.push_back(line);
    }
    
    int random_line = rand() % total_lines;
    cout << lines[random_line] << endl;
}


void get_random_player(vector<string> participants, int number_of_players){
    srand(time(0));
    int number = rand() % number_of_players;
    cout <<  participants[number] << " is your turn to give a shot: " << endl;
}


void get_participants(vector<string> &participants, int number_of_players){
    while(number_of_players > 0){
        cout << "Add player name: " << endl;
        string name;
        getline(cin, name);
        participants.push_back(name);
        number_of_players--;
    }
}