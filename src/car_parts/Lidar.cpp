#include "../../include/car_parts/Lidar.h"

Lidar::Lidar() {
    this->model = "";
    this->channel = 0;
    this->testRange = 0;
    this->powerConsumption = 0;
}

Lidar::Lidar(string model, int channel, int testRange, int powerConsumption) {
    this->model = model;
    this->channel = channel;
    this->testRange = testRange;
    this->powerConsumption = powerConsumption;
}

Lidar::~Lidar() = default;

void Lidar::setmodel(string model) {
    this->model = model;
}

string Lidar::getmodel() {
    return this->model;
}

void Lidar::setchannel(int channel) {
    this->channel = channel;
}

int Lidar::getchannel() {
    return this->channel;
}

void Lidar::settestRange(int testRange) {
    this->testRange = testRange;
}

int Lidar::gettestRange() {
    return this->testRange;
}

void Lidar::setpowerConsumption(int powerConsumption) {
    this->powerConsumption = powerConsumption;
}

int Lidar::getpowerConsumption() {
    return this->powerConsumption;
}

void Lidar::print() {
    cout << "型号：" << this->model << endl;
    cout << "通道数：" << this->channel << endl;
    cout << "测试范围：" << this->testRange << "m" << endl;
    cout << "功耗：" << this->powerConsumption << "W" << endl;
}

ostream &operator<<(ostream &out, const Lidar &multiLineLidar) {
    out << "型号：" << multiLineLidar.model << endl;
    out << "通道数：" << multiLineLidar.channel << endl;
    out << "测试范围：" << multiLineLidar.testRange << "m" << endl;
    out << "功耗：" << multiLineLidar.powerConsumption << "W" << endl;
    return out;
}

istream &operator>>(istream &in, Lidar &multiLineLidar) {
    in >> multiLineLidar.model >> multiLineLidar.channel >> multiLineLidar.testRange
       >> multiLineLidar.powerConsumption;
    return in;
}

void Lidar::save() {
    json j = this->toJson();
    ofstream out("Lidar" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json Lidar::toJson() {
    json j;
    j["model"] = this->model;
    j["channel"] = this->channel;
    j["testRange"] = this->testRange;
    j["powerConsumption"] = this->powerConsumption;
    return j;
}

void Lidar::fromJson(json j) {
    this->model = j["model"];
    this->channel = j["channel"];
    this->testRange = j["testRange"];
    this->powerConsumption = j["powerConsumption"];
}