//
// Created by 29789 on 24-9-17.
//

#ifndef LCD_H
#define LCD_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class LCD {
private:
    string size;
    string model;

public:
    LCD();
    LCD(string size, string model);
    ~LCD();

    void setsize(string size);
    string getsize();
    void setmodel(string model);
    string getmodel();

    void print();

    friend ostream &operator<<(ostream &out, const LCD &lcd);
    friend istream &operator>>(istream &in, LCD &lcd);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // LCD_H