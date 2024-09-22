#include "../include/BatteryModule.h"

BatteryModule::BatteryModule() {
    this->parameter = "";
    this->externalPowerSupply = "";
    this->chargingTime = 0;
}

BatteryModule::BatteryModule(string parameter, string externalPowerSupply, int chargingTime) {
    this->parameter = parameter;
    this->externalPowerSupply = externalPowerSupply;
    this->chargingTime = chargingTime;
}

BatteryModule::~BatteryModule() = default;

void BatteryModule::setparameter(string parameter) {
    this->parameter = parameter;
}

string BatteryModule::getparameter() {
    return this->parameter;
}

void BatteryModule::setexternalPowerSupply(string externalPowerSupply) {
    this->externalPowerSupply = externalPowerSupply;
}

string BatteryModule::getexternalPowerSupply() {
    return this->externalPowerSupply;
}

void BatteryModule::setchargingTime(int chargingTime) {
    this->chargingTime = chargingTime;
}

int BatteryModule::getchargingTime() {
    return this->chargingTime;
}

void BatteryModule::print() {
    cout << "参数：" << this->parameter << endl;
    cout << "对外供电：" << this->externalPowerSupply << endl;
    cout << "充电时长：" << this->chargingTime << "H" << endl;
}

ostream &operator<<(ostream &out, const BatteryModule &batteryModule) {
    out << "参数：" << batteryModule.parameter << endl;
    out << "对外供电：" << batteryModule.externalPowerSupply << endl;
    out << "充电时长：" << batteryModule.chargingTime << "H" << endl;
    return out;
}

istream &operator>>(istream &in, BatteryModule &batteryModule) {
    in >> batteryModule.parameter >> batteryModule.externalPowerSupply >> batteryModule.chargingTime;
    return in;
}

void BatteryModule::save() {
    json j = this->toJson();
    ofstream out("BatteryModule" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();

}

json BatteryModule::toJson() {
    json j;
    j["parameter"] = this->parameter;
    j["externalPowerSupply"] = this->externalPowerSupply;
    j["chargingTime"] = this->chargingTime;
    return j;
}

void BatteryModule::fromJson(json j) {
    this->parameter = j["parameter"];
    this->externalPowerSupply = j["externalPowerSupply"];
    this->chargingTime = j["chargingTime"];
}