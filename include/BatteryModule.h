//
// Created by 29789 on 24-9-17.
//

#ifndef BATTERYMODULE_H
#define BATTERYMODULE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class BatteryModule {
private:
    string parameter;
    string externalPowerSupply;
    int chargingTime;

public:
    BatteryModule();
    BatteryModule(string parameter, string externalPowerSupply, int chargingTime);
    ~BatteryModule();

    void setparameter(string parameter);
    string getparameter();
    void setexternalPowerSupply(string externalPowerSupply);
    string getexternalPowerSupply();
    void setchargingTime(int chargingTime);
    int getchargingTime();

    void print();

    friend ostream &operator<<(ostream &out, const BatteryModule &batteryModule);
    friend istream &operator>>(istream &in, BatteryModule &batteryModule);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // BATTERYMODULE_H