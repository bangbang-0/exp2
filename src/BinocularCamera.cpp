#include "../include/BinocularCamera.h"

BinocularCamera::BinocularCamera() {
    this->model = "";
    this->camera = "";
    this->RGBFrameResolution = "";
    this->RGBFrameRate = 0;
    this->FOV = 0;
    this->depthFrameRate = 0;
}

BinocularCamera::BinocularCamera(string model, string camera, string RGBFrameResolution, int RGBFrameRate, int FOV,
                                 int depthFrameRate) {
    this->model = model;
    this->camera = camera;
    this->RGBFrameResolution = RGBFrameResolution;
    this->RGBFrameRate = RGBFrameRate;
    this->FOV = FOV;
    this->depthFrameRate = depthFrameRate;
}

BinocularCamera::~BinocularCamera() = default;

void BinocularCamera::setmodel(string model) {
    this->model = model;
}

string BinocularCamera::getmodel() {
    return this->model;
}

void BinocularCamera::setcamera(string camera) {
    this->camera = camera;
}

string BinocularCamera::getcamera() {
    return this->camera;
}

void BinocularCamera::setRGBFrameResolution(string RGBFrameResolution) {
    this->RGBFrameResolution = RGBFrameResolution;
}

string BinocularCamera::getRGBFrameResolution() {
    return this->RGBFrameResolution;
}

void BinocularCamera::setRGBFrameRate(int RGBFrameRate) {
    this->RGBFrameRate = RGBFrameRate;
}

int BinocularCamera::getRGBFrameRate() {
    return this->RGBFrameRate;
}

void BinocularCamera::setFOV(int FOV) {
    this->FOV = FOV;
}

int BinocularCamera::getFOV() {
    return this->FOV;
}

void BinocularCamera::setdepthFrameRate(int depthFrameRate) {
    this->depthFrameRate = depthFrameRate;
}

int BinocularCamera::getdepthFrameRate() {
    return this->depthFrameRate;
}

void BinocularCamera::print() {
    cout << "型号：" << this->model << endl;
    cout << "摄像头：" << this->camera << endl;
    cout << "RGB帧分辨率：" << this->RGBFrameResolution << endl;
    cout << "RGB帧率：" << this->RGBFrameRate << endl;
    cout << "FOV：" << this->FOV << endl;
    cout << "深度帧率：" << this->depthFrameRate << endl;
}

ostream &operator<<(ostream &out, const BinocularCamera &binocularCamera) {
    out << "型号：" << binocularCamera.model << endl;
    out << "摄像头：" << binocularCamera.camera << endl;
    out << "RGB帧分辨率：" << binocularCamera.RGBFrameResolution << endl;
    out << "RGB帧率：" << binocularCamera.RGBFrameRate << endl;
    out << "FOV：" << binocularCamera.FOV << endl;
    out << "深度帧率：" << binocularCamera.depthFrameRate << endl;
    return out;
}

istream &operator>>(istream &in, BinocularCamera &binocularCamera) {
    in >> binocularCamera.model >> binocularCamera.camera >> binocularCamera.RGBFrameResolution
       >> binocularCamera.RGBFrameRate >> binocularCamera.FOV >> binocularCamera.depthFrameRate;
    return in;
}

void BinocularCamera::save() {
    json j = this->toJson();
    ofstream out("BinocularCamera" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json BinocularCamera::toJson() {
    json j;
    j["model"] = this->model;
    j["camera"] = this->camera;
    j["RGBFrameResolution"] = this->RGBFrameResolution;
    j["RGBFrameRate"] = this->RGBFrameRate;
    j["FOV"] = this->FOV;
    j["depthFrameRate"] = this->depthFrameRate;
    return j;
}

void BinocularCamera::fromJson(json j) {
    this->model = j["model"];
    this->camera = j["camera"];
    this->RGBFrameResolution = j["RGBFrameResolution"];
    this->RGBFrameRate = j["RGBFrameRate"];
    this->FOV = j["FOV"];
    this->depthFrameRate = j["depthFrameRate"];
}