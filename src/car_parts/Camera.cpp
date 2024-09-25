#include "../../include/car_parts/Camera.h"

Camera::Camera() {
    this->model = "";
    this->camera = "";
    this->RGBFrameResolution = "";
    this->RGBFrameRate = 0;
    this->FOV = 0;
    this->depthFrameRate = 0;
}

Camera::Camera(string model, string camera, string RGBFrameResolution, int RGBFrameRate, int FOV,
               int depthFrameRate) {
    this->model = model;
    this->camera = camera;
    this->RGBFrameResolution = RGBFrameResolution;
    this->RGBFrameRate = RGBFrameRate;
    this->FOV = FOV;
    this->depthFrameRate = depthFrameRate;
}

Camera::~Camera() = default;

void Camera::setmodel(string model) {
    this->model = model;
}

string Camera::getmodel() {
    return this->model;
}

void Camera::setcamera(string camera) {
    this->camera = camera;
}

string Camera::getcamera() {
    return this->camera;
}

void Camera::setRGBFrameResolution(string RGBFrameResolution) {
    this->RGBFrameResolution = RGBFrameResolution;
}

string Camera::getRGBFrameResolution() {
    return this->RGBFrameResolution;
}

void Camera::setRGBFrameRate(int RGBFrameRate) {
    this->RGBFrameRate = RGBFrameRate;
}

int Camera::getRGBFrameRate() {
    return this->RGBFrameRate;
}

void Camera::setFOV(int FOV) {
    this->FOV = FOV;
}

int Camera::getFOV() {
    return this->FOV;
}

void Camera::setdepthFrameRate(int depthFrameRate) {
    this->depthFrameRate = depthFrameRate;
}

int Camera::getdepthFrameRate() {
    return this->depthFrameRate;
}

void Camera::print() {
    cout << "型号：" << this->model << endl;
    cout << "摄像头：" << this->camera << endl;
    cout << "RGB帧分辨率：" << this->RGBFrameResolution << endl;
    cout << "RGB帧率：" << this->RGBFrameRate << endl;
    cout << "FOV：" << this->FOV << endl;
    cout << "深度帧率：" << this->depthFrameRate << endl;
}

ostream &operator<<(ostream &out, const Camera &binocularCamera) {
    out << "型号：" << binocularCamera.model << endl;
    out << "摄像头：" << binocularCamera.camera << endl;
    out << "RGB帧分辨率：" << binocularCamera.RGBFrameResolution << endl;
    out << "RGB帧率：" << binocularCamera.RGBFrameRate << endl;
    out << "FOV：" << binocularCamera.FOV << endl;
    out << "深度帧率：" << binocularCamera.depthFrameRate << endl;
    return out;
}

istream &operator>>(istream &in, Camera &binocularCamera) {
    in >> binocularCamera.model >> binocularCamera.camera >> binocularCamera.RGBFrameResolution
       >> binocularCamera.RGBFrameRate >> binocularCamera.FOV >> binocularCamera.depthFrameRate;
    return in;
}

void Camera::save() {
    json j = this->toJson();
    ofstream out("Camera" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json Camera::toJson() {
    json j;
    j["model"] = this->model;
    j["camera"] = this->camera;
    j["RGBFrameResolution"] = this->RGBFrameResolution;
    j["RGBFrameRate"] = this->RGBFrameRate;
    j["FOV"] = this->FOV;
    j["depthFrameRate"] = this->depthFrameRate;
    return j;
}

void Camera::fromJson(json j) {
    this->model = j["model"];
    this->camera = j["camera"];
    this->RGBFrameResolution = j["RGBFrameResolution"];
    this->RGBFrameRate = j["RGBFrameRate"];
    this->FOV = j["FOV"];
    this->depthFrameRate = j["depthFrameRate"];
}