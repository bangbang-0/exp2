#include "../include/BasePlate.h"

BasePlate::BasePlate() {
    this->id = "";
    this->model = "";
    this->wheelBase = 0;
    this->wheelTrack = 0;
    this->minGroundClearance = 0;
    this->minTurningRadius = 0;
    this->driveMode = "";
    this->maxTravel = 0;
}

BasePlate::BasePlate(string id, string model, int wheelBase, int wheelTrack, int minGroundClearance, int minTurningRadius,
                     string driveMode, int maxTravel, vector<Tire> tire) {
    this->id = id;
    this->model = model;
    this->wheelBase = wheelBase;
    this->wheelTrack = wheelTrack;
    this->minGroundClearance = minGroundClearance;
    this->minTurningRadius = minTurningRadius;
    this->driveMode = driveMode;
    this->maxTravel = maxTravel;
    this->tire = tire;
}
BasePlate::~BasePlate() = default;

void BasePlate::setID(string id) {
    this->id = id;
}

string BasePlate::getid() {
    return this->id;
}

void BasePlate::setmodel(string model) {
    this->model = model;
}

string BasePlate::getmodel() {
    return this->model;
}

void BasePlate::setwheelBase(int wheelBase) {
    this->wheelBase = wheelBase;
}

int BasePlate::getwheelBase() {
    return this->wheelBase;
}

void BasePlate::setwheelTrack(int wheelTrack) {
    this->wheelTrack = wheelTrack;
}

int BasePlate::getwheelTrack() {
    return this->wheelTrack;
}

void BasePlate::setminGroundClearance(int minGroundClearance) {
    this->minGroundClearance = minGroundClearance;
}

int BasePlate::getminGroundClearance() {
    return this->minGroundClearance;
}

void BasePlate::setminTurningRadius(int minTurningRadius) {
    this->minTurningRadius = minTurningRadius;
}

int BasePlate::getminTurningRadius() {
    return this->minTurningRadius;
}

void BasePlate::setdriveMode(string driveMode) {
    this->driveMode = driveMode;
}

string BasePlate::getdriveMode() {
    return this->driveMode;
}

void BasePlate::setmaxTravel(int maxTravel) {
    this->maxTravel = maxTravel;
}

int BasePlate::getmaxTravel() {
    return this->maxTravel;
}

void BasePlate::settire(vector<Tire> tire) {
    this->tire = tire;
}

vector<Tire> BasePlate::gettire() {
    return this->tire;
}

void BasePlate::print() {
    cout << "编号：" << this->id << endl;
    cout << "型号：" << this->model << endl;
    cout << "轴距：" << this->wheelBase << "mm" << endl;
    cout << "轮距：" << this->wheelTrack << "mm" << endl;
    cout << "最小离地间隙：" << this->minGroundClearance << "mm" << endl;
    cout << "最小转弯半径：" << this->minTurningRadius << "m" << endl;
    cout << "驱动形式：" << this->driveMode << endl;
    cout << "最大行程：" << this->maxTravel << "KM" << endl;
    cout << "轮胎 (" << tire.size() << "个)" << endl;
    if (!tire.empty()) {
        tire[0].print();
    }
}

ostream &operator<<(ostream &out, const BasePlate &basePlate) {
    out << "编号：" << basePlate.id << endl;
    out << "型号：" << basePlate.model << endl;
    out << "轴距：" << basePlate.wheelBase << "mm" << endl;
    out << "轮距：" << basePlate.wheelTrack << "mm" << endl;
    out << "最小离地间隙：" << basePlate.minGroundClearance << "mm" << endl;
    out << "最小转弯半径：" << basePlate.minTurningRadius << "m" << endl;
    out << "驱动形式：" << basePlate.driveMode << endl;
    out << "最大行程：" << basePlate.maxTravel << "KM" << endl;
    out << "轮胎 (" << basePlate.tire.size() << "个)" << endl;
    if (!basePlate.tire.empty()) {
        out << basePlate.tire[0];
    }
    return out;
}

istream &operator>>(istream &in, BasePlate &basePlate) {
    in >> basePlate.id >> basePlate.model >> basePlate.wheelBase >> basePlate.wheelTrack
       >> basePlate.minGroundClearance >> basePlate.minTurningRadius >> basePlate.driveMode >> basePlate.maxTravel;
    return in;
}

void BasePlate::save() {
    json j = this->toJson();
    ofstream out("BasePlate" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json BasePlate::toJson() {
    json j;
    j["id"] = this->id;
    j["model"] = this->model;
    j["wheelBase"] = this->wheelBase;
    j["wheelTrack"] = this->wheelTrack;
    j["minGroundClearance"] = this->minGroundClearance;
    j["minTurningRadius"] = this->minTurningRadius;
    j["driveMode"] = this->driveMode;
    j["maxTravel"] = this->maxTravel;
    json tireJson;
    for (Tire x : tire) {
        tireJson.push_back(x.toJson());
    }
    j["tire"] = tireJson;
    return j;
}

void BasePlate::fromJson(json j) {
    this->id = j["id"];
    this->model = j["model"];
    this->wheelBase = j["wheelBase"];
    this->wheelTrack = j["wheelTrack"];
    this->minGroundClearance = j["minGroundClearance"];
    this->minTurningRadius = j["minTurningRadius"];
    this->driveMode = j["driveMode"];
    this->maxTravel = j["maxTravel"];
    json tireJson = j["tire"];
    for (const auto &x : tireJson) {
        Tire tire;
        tire.fromJson(x);
        this->tire.push_back(tire);
    }
}

