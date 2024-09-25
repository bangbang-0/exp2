//
// Created by 29789 on 24-9-17.
//
#ifndef NINEAXISGYROSCOPE_H
#define NINEAXISGYROSCOPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Gyroscope {
private:
    string model;
    string manufacturer;

public:
    Gyroscope();
    Gyroscope(string model, string manufacturer);
    ~Gyroscope();

    void setmodel(string model);
    string getmodel();
    void setmanufacturer(string manufacturer);
    string getmanufacturer();

    void print();
    friend ostream &operator<<(ostream &out, const Gyroscope &nineAxisGyroscope);
    friend istream &operator>>(istream &in, Gyroscope &nineAxisGyroscope);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // NINEAXISGYROSCOPE_H