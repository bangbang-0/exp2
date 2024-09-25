//
// Created by 29789 on 24-9-17.
//

#ifndef MULTILINELIDAR_H
#define MULTILINELIDAR_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Lidar {
private:
    string model;
    int channel;
    int testRange;
    int powerConsumption;

public:
    Lidar();
    Lidar(string model, int channel, int testRange, int powerConsumption);
    ~Lidar();

    void setmodel(string model);
    string getmodel();
    void setchannel(int channel);
    int getchannel();
    void settestRange(int testRange);
    int gettestRange();
    void setpowerConsumption(int powerConsumption);
    int getpowerConsumption();

    void print();
    friend ostream &operator<<(ostream &out, const Lidar &multiLineLidar);
    friend istream &operator>>(istream &in, Lidar &multiLineLidar);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // MULTILINELIDAR_H