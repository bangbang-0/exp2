//
// Created by 29789 on 24-9-17.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp"
#include <ctime>

using namespace std;
using json = nlohmann::json;

class Student {
private:
    string id;
    string name;

public:
    Student();
    Student(string id, string name);
    ~Student();

    void setid(string id);
    string getid();
    void setname(string name);
    string getname();

    void print();
    friend ostream &operator<<(ostream &out, const Student &student);
    friend istream &operator>>(istream &in, Student &student);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // STUDENT_H