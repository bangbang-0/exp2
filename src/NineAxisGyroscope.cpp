#include "../include/NineAxisGyroscope.h"

NineAxisGyroscope::NineAxisGyroscope() {
    this->model = "";
    this->manufacturer = "";
}

NineAxisGyroscope::NineAxisGyroscope(string model, string manufacturer) {
    this->model = model;
    this->manufacturer = manufacturer;
}

NineAxisGyroscope::~NineAxisGyroscope() = default;

void NineAxisGyroscope::setmodel(string model) {
    this->model = model;
}

string NineAxisGyroscope::getmodel() {
    return this->model;
}

void NineAxisGyroscope::setmanufacturer(string manufacturer) {
    this->manufacturer = manufacturer;
}

string NineAxisGyroscope::getmanufacturer() {
    return this->manufacturer;
}

void NineAxisGyroscope::print() {
    cout << "型号：" << this->model << endl;
    cout << "厂家：" << this->manufacturer << endl;
}

ostream &operator<<(ostream &out, const NineAxisGyroscope &nineAxisGyroscope) {
    out << "型号：" << nineAxisGyroscope.model << endl;
    out << "厂家：" << nineAxisGyroscope.manufacturer << endl;
    return out;
}

istream &operator>>(istream &in, NineAxisGyroscope &nineAxisGyroscope) {
    in >> nineAxisGyroscope.model >> nineAxisGyroscope.manufacturer;
    return in;
}

void NineAxisGyroscope::save() {
    json j = this->toJson();
    ofstream out("NineAxisGyroscope" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json NineAxisGyroscope::toJson() {
    json j;
    j["model"] = this->model;
    j["manufacturer"] = this->manufacturer;
    return j;
}

void NineAxisGyroscope::fromJson(json j) {
    this->model = j["model"];
    this->manufacturer = j["manufacturer"];
}