#include "../../include/car_parts/LCD.h"

LCD::LCD() {
    this->size = "";
    this->model = "";
}

LCD::LCD(string size, string model) {
    this->size = size;
    this->model = model;
}

LCD::~LCD() = default;

void LCD::setsize(string size) {
    this->size = size;
}

string LCD::getsize() {
    return this->size;
}

void LCD::setmodel(string model) {
    this->model = model;
}

string LCD::getmodel() {
    return this->model;
}

void LCD::print() {
    cout << "尺寸：" << this->size << endl;
    cout << "型号：" << this->model << endl;
}

ostream &operator<<(ostream &out, const LCD &lcd) {
    out << "尺寸：" << lcd.size << endl;
    out << "型号：" << lcd.model << endl;
    return out;
}

istream &operator>>(istream &in, LCD &lcd) {
    in >> lcd.size >> lcd.model;
    return in;
}

void LCD::save() {
    json j = this->toJson();
    ofstream out("LCD" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json LCD::toJson() {
    json j;
    j["size"] = this->size;
    j["model"] = this->model;
    return j;
}

void LCD::fromJson(json j) {
    this->size = j["size"];
    this->model = j["model"];
}