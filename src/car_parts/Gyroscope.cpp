#include "../../include/car_parts/Gyroscope.h"

Gyroscope::Gyroscope() {
    this->model = "";
    this->manufacturer = "";
}

Gyroscope::Gyroscope(string model, string manufacturer) {
    this->model = model;
    this->manufacturer = manufacturer;
}

Gyroscope::~Gyroscope() = default;

void Gyroscope::setmodel(string model) {
    this->model = model;
}

string Gyroscope::getmodel() {
    return this->model;
}

void Gyroscope::setmanufacturer(string manufacturer) {
    this->manufacturer = manufacturer;
}

string Gyroscope::getmanufacturer() {
    return this->manufacturer;
}

void Gyroscope::print() {
    cout << "型号：" << this->model << endl;
    cout << "厂家：" << this->manufacturer << endl;
}

ostream &operator<<(ostream &out, const Gyroscope &nineAxisGyroscope) {
    out << "型号：" << nineAxisGyroscope.model << endl;
    out << "厂家：" << nineAxisGyroscope.manufacturer << endl;
    return out;
}

istream &operator>>(istream &in, Gyroscope &nineAxisGyroscope) {
    in >> nineAxisGyroscope.model >> nineAxisGyroscope.manufacturer;
    return in;
}

void Gyroscope::save() {
    json j = this->toJson();
    ofstream out("Gyroscope" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json Gyroscope::toJson() {
    json j;
    j["model"] = this->model;
    j["manufacturer"] = this->manufacturer;
    return j;
}

void Gyroscope::fromJson(json j) {
    this->model = j["model"];
    this->manufacturer = j["manufacturer"];
}