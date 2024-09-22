//
// Created by 29789 on 24-9-17.
//

#ifndef BASEPLATE_H
#define BASEPLATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../nlohmann/json.hpp"
#include "Tire.h" // 确保包含 Tire 类的头文件

using namespace std;
using json = nlohmann::json;

class BasePlate {
private:
    string id;
    string model;
    int wheelBase;
    int wheelTrack;
    int minGroundClearance;
    int minTurningRadius;
    string driveMode;
    int maxTravel;
    vector<Tire> tire;

public:
    BasePlate();
    BasePlate(string id, string model, int wheelBase, int wheelTrack, int minGroundClearance,
              int minTurningRadius, string driveMode, int maxTravel, vector<Tire> tire);
    ~BasePlate();

    void setID(string id);
    string getid();
    void setmodel(string model);
    string getmodel();
    void setwheelBase(int wheelBase);
    int getwheelBase();
    void setwheelTrack(int wheelTrack);
    int getwheelTrack();
    void setminGroundClearance(int minGroundClearance);
    int getminGroundClearance();
    void setminTurningRadius(int minTurningRadius);
    int getminTurningRadius();
    void setdriveMode(string driveMode);
    string getdriveMode();
    void setmaxTravel(int maxTravel);
    int getmaxTravel();
    void settire(vector<Tire> tire);
    vector<Tire> gettire();

    void print();
    friend ostream &operator<<(ostream &out, const BasePlate &basePlate);
    friend istream &operator>>(istream &in, BasePlate &basePlate);

    void save();
    json toJson();
    void fromJson(json j);

    BasePlate(const char string[11], const char string1[11], int i, int i1, int i2, int i3, const char string2[13],
              int i4, const char string3[10], vector<Tire> vector1);
};

#endif // BASEPLATE_H