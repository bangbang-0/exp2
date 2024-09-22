//
// Created by 29789 on 24-9-17.
//

#ifndef TIRE_H
#define TIRE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp" // 确保你已安装此库

using namespace std;
using json = nlohmann::json;

class Tire {
private:
    string model;
    int size;

public:
    Tire();
    Tire(string model, int size);
    ~Tire();

    void setmodel(string model);
    string getmodel();
    void setsize(int size);
    int getsize();

    void print();
    friend ostream &operator<<(ostream &out, const Tire &tire);
    friend istream &operator>>(istream &in, Tire &tire);

    void save(ofstream &out);
    json toJson();
    void fromJson(json j);
};

#endif // TIRE_H