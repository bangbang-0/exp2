//
// Created by 29789 on 24-9-17.
//

#ifndef BINOCULARCAMERA_H
#define BINOCULARCAMERA_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Camera {
private:
    string model;
    string camera;
    string RGBFrameResolution;
    int RGBFrameRate;
    int FOV;
    int depthFrameRate;

public:
    Camera();
    Camera(string model, string camera, string RGBFrameResolution, int RGBFrameRate, int FOV,
           int depthFrameRate);
    ~Camera();

    void setmodel(string model);
    string getmodel();
    void setcamera(string camera);
    string getcamera();
    void setRGBFrameResolution(string RGBFrameResolution);
    string getRGBFrameResolution();
    void setRGBFrameRate(int RGBFrameRate);
    int getRGBFrameRate();
    void setFOV(int FOV);
    int getFOV();
    void setdepthFrameRate(int depthFrameRate);
    int getdepthFrameRate();

    void print();
    friend ostream &operator<<(ostream &out, const Camera &binocularCamera);
    friend istream &operator>>(istream &in, Camera &binocularCamera);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // BINOCULARCAMERA_H