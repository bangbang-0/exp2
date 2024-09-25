//
// Created by 29789 on 24-9-17.
//

#ifndef SONGLINGCAR_H
#define SONGLINGCAR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../nlohmann/json.hpp"
#include "car_parts/BasePlate.h"
#include "car_parts/AGXKit.h"
#include "car_parts/Camera.h"
#include "car_parts/Lidar.h"
#include "car_parts/Gyroscope.h"
#include "car_parts/LCD.h"
#include "car_parts/Battery.h"

using namespace std;
using json = nlohmann::json;

class Car {
public:
    string id;
    BasePlate basePlate;
    vector<AGXKit> agxKit;
    vector<Camera> binocularCamera;
    vector<Lidar> multiLineLidar;
    vector<Gyroscope> nineAxisGyroscope;
    vector<LCD> lcd;
    vector<Battery> batteryModule;

    Car();
    Car(string id, BasePlate basePlate, vector<AGXKit> agxKit, vector<Camera> binocularCamera,
        vector<Lidar> multiLineLidar, vector<Gyroscope> nineAxisGyroscope, vector<LCD> lcd,
        vector<Battery> batteryModule);
    ~Car();

    void setid(string id);
    string getid();
    void setBasePlateid(string id);
    string getBasePlateid();
    void setBasePlate(BasePlate basePlate);
    BasePlate getBasePlate();
    void setagxKit(vector<AGXKit> agxKit);
    vector<AGXKit> getagxKit();
    void setbinocularCamera(vector<Camera> binocularCamera);
    vector<Camera> getbinocularCamera();
    void setmultiLineLidar(vector<Lidar> multiLineLidar);
    vector<Lidar> getmultiLineLidar();
    void setnineAxisGyroscope(vector<Gyroscope> nineAxisGyroscope);
    vector<Gyroscope> getnineAxisGyroscope();
    void setlcd(vector<LCD> lcd);
    vector<LCD> getlcd();
    void setbatteryModule(vector<Battery> batteryModule);
    vector<Battery> getbatteryModule();

    void print();
    friend ostream &operator<<(ostream &out, const Car &songLingCar);
    friend istream &operator>>(istream &in, Car &songLingCar);
    void save();
    json toJson();
    void fromJson(json j);
};

#endif // SONGLINGCAR_H