#include "../include/MultiLineLidar.h"

MultiLineLidar::MultiLineLidar() {
    this->model = "";
    this->channel = 0;
    this->testRange = 0;
    this->powerConsumption = 0;
}

MultiLineLidar::MultiLineLidar(string model, int channel, int testRange, int powerConsumption) {
    this->model = model;
    this->channel = channel;
    this->testRange = testRange;
    this->powerConsumption = powerConsumption;
}

MultiLineLidar::~MultiLineLidar() = default;

void MultiLineLidar::setmodel(string model) {
    this->model = model;
}

string MultiLineLidar::getmodel() {
    return this->model;
}

void MultiLineLidar::setchannel(int channel) {
    this->channel = channel;
}

int MultiLineLidar::getchannel() {
    return this->channel;
}

void MultiLineLidar::settestRange(int testRange) {
    this->testRange = testRange;
}

int MultiLineLidar::gettestRange() {
    return this->testRange;
}

void MultiLineLidar::setpowerConsumption(int powerConsumption) {
    this->powerConsumption = powerConsumption;
}

int MultiLineLidar::getpowerConsumption() {
    return this->powerConsumption;
}

void MultiLineLidar::print() {
    cout << "型号：" << this->model << endl;
    cout << "通道数：" << this->channel << endl;
    cout << "测试范围：" << this->testRange << "m" << endl;
    cout << "功耗：" << this->powerConsumption << "W" << endl;
}

ostream &operator<<(ostream &out, const MultiLineLidar &multiLineLidar) {
    out << "型号：" << multiLineLidar.model << endl;
    out << "通道数：" << multiLineLidar.channel << endl;
    out << "测试范围：" << multiLineLidar.testRange << "m" << endl;
    out << "功耗：" << multiLineLidar.powerConsumption << "W" << endl;
    return out;
}

istream &operator>>(istream &in, MultiLineLidar &multiLineLidar) {
    in >> multiLineLidar.model >> multiLineLidar.channel >> multiLineLidar.testRange
       >> multiLineLidar.powerConsumption;
    return in;
}

void MultiLineLidar::save() {
    json j = this->toJson();
    ofstream out("MultiLineLidar" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json MultiLineLidar::toJson() {
    json j;
    j["model"] = this->model;
    j["channel"] = this->channel;
    j["testRange"] = this->testRange;
    j["powerConsumption"] = this->powerConsumption;
    return j;
}

void MultiLineLidar::fromJson(json j) {
    this->model = j["model"];
    this->channel = j["channel"];
    this->testRange = j["testRange"];
    this->powerConsumption = j["powerConsumption"];
}