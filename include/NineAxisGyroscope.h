//
// Created by 29789 on 24-9-17.
//
#ifndef NINEAXISGYROSCOPE_H
#define NINEAXISGYROSCOPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class NineAxisGyroscope {
private:
    string model;
    string manufacturer;

public:
    NineAxisGyroscope();
    NineAxisGyroscope(string model, string manufacturer);
    ~NineAxisGyroscope();

    void setmodel(string model);
    string getmodel();
    void setmanufacturer(string manufacturer);
    string getmanufacturer();

    void print();
    friend ostream &operator<<(ostream &out, const NineAxisGyroscope &nineAxisGyroscope);
    friend istream &operator>>(istream &in, NineAxisGyroscope &nineAxisGyroscope);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // NINEAXISGYROSCOPE_H