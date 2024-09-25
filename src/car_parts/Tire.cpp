//
// Created by 29789 on 24-9-17.
//
#include "../../include/car_parts/Tire.h"

Tire::Tire() : model(""), size(0) {}

Tire::Tire(string model, int size) : model(model), size(size) {}

Tire::~Tire() = default;

void Tire::setmodel(string model) {
    this->model = model;
}

string Tire::getmodel() {
    return this->model;
}

void Tire::setsize(int size) {
    this->size = size;
}

int Tire::getsize() {
    return this->size;
}

void Tire::print() {
    cout << "型号：" << this->model << endl;
    cout << "尺寸：" << this->size << "mm" << endl;
}

ostream &operator<<(ostream &out, const Tire &tire) {
    out << "型号：" << tire.model << endl;
    out << "尺寸：" << tire.size << "mm" << endl;
    return out;
}

istream &operator>>(istream &in, Tire &tire) {
    in >> tire.model >> tire.size;
    return in;
}

void Tire::save(ofstream &out) {
    json j = this->toJson();
    out << j;
}

json Tire::toJson() {
    json j;
    j["model"] = this->model;
    j["size"] = this->size;
    return j;
}

void Tire::fromJson(json j) {
    this->model = j["model"];
    this->size = j["size"];
}