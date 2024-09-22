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
#include "BasePlate.h"
#include "AGXKit.h"
#include "BinocularCamera.h"
#include "MultiLineLidar.h"
#include "NineAxisGyroscope.h"
#include "LCD.h"
#include "BatteryModule.h"

using namespace std;
using json = nlohmann::json;

class SongLingCar {
public:
    string id;
    BasePlate basePlate;
    vector<AGXKit> agxKit;
    vector<BinocularCamera> binocularCamera;
    vector<MultiLineLidar> multiLineLidar;
    vector<NineAxisGyroscope> nineAxisGyroscope;
    vector<LCD> lcd;
    vector<BatteryModule> batteryModule;

    SongLingCar();
    SongLingCar(string id, BasePlate basePlate, vector<AGXKit> agxKit, vector<BinocularCamera> binocularCamera,
                vector<MultiLineLidar> multiLineLidar, vector<NineAxisGyroscope> nineAxisGyroscope, vector<LCD> lcd,
                vector<BatteryModule> batteryModule);
    ~SongLingCar();

    void setid(string id);
    string getid();
    void setBasePlateid(string id);
    string getBasePlateid();
    void setBasePlate(BasePlate basePlate);
    BasePlate getBasePlate();
    void setagxKit(vector<AGXKit> agxKit);
    vector<AGXKit> getagxKit();
    void setbinocularCamera(vector<BinocularCamera> binocularCamera);
    vector<BinocularCamera> getbinocularCamera();
    void setmultiLineLidar(vector<MultiLineLidar> multiLineLidar);
    vector<MultiLineLidar> getmultiLineLidar();
    void setnineAxisGyroscope(vector<NineAxisGyroscope> nineAxisGyroscope);
    vector<NineAxisGyroscope> getnineAxisGyroscope();
    void setlcd(vector<LCD> lcd);
    vector<LCD> getlcd();
    void setbatteryModule(vector<BatteryModule> batteryModule);
    vector<BatteryModule> getbatteryModule();

    void print();
    friend ostream &operator<<(ostream &out, const SongLingCar &songLingCar);
    friend istream &operator>>(istream &in, SongLingCar &songLingCar);
    void save();
    json toJson();
    void fromJson(json j);
};

#endif // SONGLINGCAR_H