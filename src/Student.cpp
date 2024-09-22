
#include "../include/Student.h"

Student::Student() : id(""), name("") {}

Student::Student(string id, string name) : id(id), name(name) {}

Student::~Student() = default;

void Student::setid(string id) {
    this->id = id;
}

string Student::getid() {
    return this->id;
}

void Student::setname(string name) {
    this->name = name;
}

string Student::getname() {
    return this->name;
}

void Student::print() {
    cout << "学号：" << this->id << endl;
    cout << "姓名：" << this->name << endl;
}

ostream &operator<<(ostream &out, const Student &student) {
    out << "学号：" << student.id << endl;
    out << "姓名：" << student.name << endl;
    return out;
}

istream &operator>>(istream &in, Student &student) {
    in >> student.id >> student.name;
    return in;
}

void Student::save() {
    json j = this->toJson();
    ofstream out("Student" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json Student::toJson() {
    json j;
    j["id"] = this->id;
    j["name"] = this->name;
    return j;
}

void Student::fromJson(json j) {
    this->id = j["id"];
    this->name = j["name"];
}