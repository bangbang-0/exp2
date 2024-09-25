#include "../../include/car_parts/AGXKit.h"

AGXKit::AGXKit() {
    this->model = "";
    this->AI = 0;
    this->CUDA = 0;
    this->tensorCore = 0;
    this->memory = 0;
    this->storage = 0;
}

AGXKit::AGXKit(string model, int AI, int CUDA, int tensorCore, int memory, int storage) {
    this->model = model;
    this->AI = AI;
    this->CUDA = CUDA;
    this->tensorCore = tensorCore;
    this->memory = memory;
    this->storage = storage;
}

AGXKit::~AGXKit() = default;

void AGXKit::setmodel(string model) {
    this->model = model;
}

string AGXKit::getmodel() {
    return this->model;
}

void AGXKit::setAI(int AI) {
    this->AI = AI;
}

int AGXKit::getAI() {
    return this->AI;
}

void AGXKit::setCUDA(int CUDA) {
    this->CUDA = CUDA;
}

int AGXKit::getCUDA() {
    return this->CUDA;
}

void AGXKit::settensorCore(int tensorCore) {
    this->tensorCore = tensorCore;
}

int AGXKit::gettensorCore() {
    return this->tensorCore;
}

void AGXKit::setmemory(int memory) {
    this->memory = memory;
}

int AGXKit::getmemory() {
    return this->memory;
}

void AGXKit::setstorage(int storage) {
    this->storage = storage;
}

int AGXKit::getstorage() {
    return this->storage;
}

void AGXKit::print() {
    cout << "型号：" << this->model << endl;
    cout << "AI：" << this->AI << " TOPS" << endl;
    cout << "CUDA核心：" << this->CUDA << endl;
    cout << "Tensor CORE：" << this->tensorCore << endl;
    cout << "显存：" << this->memory << "G" << endl;
    cout << "存储：" << this->storage << "G" << endl;
}

ostream &operator<<(ostream &out, const AGXKit &agxKit) {
    out << "型号：" << agxKit.model << endl;
    out << "AI：" << agxKit.AI << " TOPS" << endl;
    out << "CUDA核心：" << agxKit.CUDA << endl;
    out << "Tensor CORE：" << agxKit.tensorCore << endl;
    out << "显存：" << agxKit.memory << "G" << endl;
    out << "存储：" << agxKit.storage << "G" << endl;
    return out;
}

istream &operator>>(istream &in, AGXKit &agxKit) {
    in >> agxKit.model >> agxKit.AI >> agxKit.CUDA >> agxKit.tensorCore >> agxKit.memory >> agxKit.storage;
    return in;
}

void AGXKit::save() {
    json j = this->toJson();
    ofstream out("AGXKit" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json AGXKit::toJson() {
    json j;
    j["model"] = this->model;
    j["AI"] = this->AI;
    j["CUDA"] = this->CUDA;
    j["tensorCore"] = this->tensorCore;
    j["memory"] = this->memory;
    j["storage"] = this->storage;
    return j;
}

void AGXKit::fromJson(json j) {
    this->model = j["model"];
    this->AI = j["AI"];
    this->CUDA = j["CUDA"];
    this->tensorCore = j["tensorCore"];
    this->memory = j["memory"];
    this->storage = j["storage"];
}