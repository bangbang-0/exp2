//
// Created by 29789 on 24-9-17.
//

#ifndef RELATIONAL_H
#define RELATIONAL_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp"
#include "Student.h"
#include "SongLingCar.h"

using namespace std;
using json = nlohmann::json;

class relational {
public:
    Student *student;
    SongLingCar *songLingCar;

    relational(Student *student, SongLingCar *songLingCar);
    void show();

    friend ostream &operator<<(ostream &out, const relational &relational);
    friend istream &operator>>(istream &in, relational &relational);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // RELATIONAL_H