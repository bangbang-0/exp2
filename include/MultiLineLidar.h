//
// Created by 29789 on 24-9-17.
//

#ifndef MULTILINELIDAR_H
#define MULTILINELIDAR_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class MultiLineLidar {
private:
    string model;
    int channel;
    int testRange;
    int powerConsumption;

public:
    MultiLineLidar();
    MultiLineLidar(string model, int channel, int testRange, int powerConsumption);
    ~MultiLineLidar();

    void setmodel(string model);
    string getmodel();
    void setchannel(int channel);
    int getchannel();
    void settestRange(int testRange);
    int gettestRange();
    void setpowerConsumption(int powerConsumption);
    int getpowerConsumption();

    void print();
    friend ostream &operator<<(ostream &out, const MultiLineLidar &multiLineLidar);
    friend istream &operator>>(istream &in, MultiLineLidar &multiLineLidar);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // MULTILINELIDAR_H