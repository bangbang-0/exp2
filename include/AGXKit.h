//
// Created by 29789 on 24-9-17.
//

#ifndef AGXKIT_H
#define AGXKIT_H

#include <iostream>
#include <fstream>
#include <string>
#include "../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class AGXKit {
private:
    string model;
    int AI;
    int CUDA;
    int tensorCore;
    int memory;
    int storage;

public:
    AGXKit();
    AGXKit(string model, int AI, int CUDA, int tensorCore, int memory, int storage);
    ~AGXKit();

    void setmodel(string model);
    string getmodel();
    void setAI(int AI);
    int getAI();
    void setCUDA(int CUDA);
    int getCUDA();
    void settensorCore(int tensorCore);
    int gettensorCore();
    void setmemory(int memory);
    int getmemory();
    void setstorage(int storage);
    int getstorage();

    void print();
    friend ostream &operator<<(ostream &out, const AGXKit &agxKit);
    friend istream &operator>>(istream &in, AGXKit &agxKit);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // AGXKIT_H