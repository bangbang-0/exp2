#include "../include/SongLingCar.h"

SongLingCar::SongLingCar() = default;

SongLingCar::SongLingCar(string id, BasePlate basePlate, vector<AGXKit> agxKit, vector<BinocularCamera> binocularCamera,
                         vector<MultiLineLidar> multiLineLidar, vector<NineAxisGyroscope> nineAxisGyroscope, vector<LCD> lcd,
                         vector<BatteryModule> batteryModule) {
    this->id = id;
    this->basePlate = basePlate;
    this->agxKit = agxKit;
    this->binocularCamera = binocularCamera;
    this->multiLineLidar = multiLineLidar;
    this->nineAxisGyroscope = nineAxisGyroscope;
    this->lcd = lcd;
    this->batteryModule = batteryModule;
}

SongLingCar::~SongLingCar() = default;

void SongLingCar::setid(string id) {
    this->id = id;
}

string SongLingCar::getid() {
    return this->id;
}

void SongLingCar::setBasePlateid(string id) {
    this->basePlate.setID(id);
}

void SongLingCar::setBasePlate(BasePlate basePlate) {
    this->basePlate = basePlate;
}

BasePlate SongLingCar::getBasePlate() {
    return this->basePlate;
}

void SongLingCar::setagxKit(vector<AGXKit> agxKit) {
    this->agxKit = agxKit;
}

vector<AGXKit> SongLingCar::getagxKit() {
    return this->agxKit;
}

void SongLingCar::setbinocularCamera(vector<BinocularCamera> binocularCamera) {
    this->binocularCamera = binocularCamera;
}

vector<BinocularCamera> SongLingCar::getbinocularCamera() {
    return this->binocularCamera;
}

void SongLingCar::setmultiLineLidar(vector<MultiLineLidar> multiLineLidar) {
    this->multiLineLidar = multiLineLidar;
}

vector<MultiLineLidar> SongLingCar::getmultiLineLidar() {
    return this->multiLineLidar;
}

void SongLingCar::setnineAxisGyroscope(vector<NineAxisGyroscope> nineAxisGyroscope) {
    this->nineAxisGyroscope = nineAxisGyroscope;
}

vector<NineAxisGyroscope> SongLingCar::getnineAxisGyroscope() {
    return this->nineAxisGyroscope;
}

void SongLingCar::setlcd(vector<LCD> lcd) {
    this->lcd = lcd;
}

vector<LCD> SongLingCar::getlcd() {
    return this->lcd;
}

void SongLingCar::setbatteryModule(vector<BatteryModule> batteryModule) {
    this->batteryModule = batteryModule;
}

vector<BatteryModule> SongLingCar::getbatteryModule() {
    return this->batteryModule;
}

void SongLingCar::print() {
    cout << "编号：" << this->id << endl;
    cout << "底盘：" << endl;
    basePlate.print();
    cout << "AGX套件(" << agxKit.size() << "个)：" << endl;
    for (AGXKit x : agxKit) {
        x.print();
    }
    cout << "双目摄像头(" << binocularCamera.size() << "个)：" << endl;
    for (BinocularCamera x : binocularCamera) {
        x.print();
    }
    cout << "多线激光雷达(" << multiLineLidar.size() << "个)：" << endl;
    for (MultiLineLidar x : multiLineLidar) {
        x.print();
    }
    cout << "9轴陀螺仪(" << nineAxisGyroscope.size() << "个)：" << endl;
    for (NineAxisGyroscope x : nineAxisGyroscope) {
        x.print();
    }
    cout << "液晶显示屏(" << lcd.size() << "个)：" << endl;
    for (LCD x : lcd) {
        x.print();
    }
    cout << "电池模块(" << batteryModule.size() << "个)：" << endl;
    for (BatteryModule x : batteryModule) {
        x.print();
    }
}

ostream &operator<<(ostream &out, const SongLingCar &songLingCar) {
    out << "编号：" << songLingCar.id << endl;
    out << "底盘：" << endl;
    out << songLingCar.basePlate;
    out << "AGX套件(" << songLingCar.agxKit.size() << "个)：\n";
    for (const auto &x : songLingCar.agxKit) {
        out << x;
    }
    out << "双目摄像头(" << songLingCar.binocularCamera.size() << "个)：\n";
    for (const auto &x : songLingCar.binocularCamera) {
        out << x;
    }
    out << "多线激光雷达(" << songLingCar.multiLineLidar.size() << "个)：\n";
    for (const auto &x : songLingCar.multiLineLidar) {
        out << x;
    }
    out << "9轴陀螺仪(" << songLingCar.nineAxisGyroscope.size() << "个)：\n";
    for (const auto &x : songLingCar.nineAxisGyroscope) {
        out << x;
    }
    out << "液晶显示屏(" << songLingCar.lcd.size() << "个)：\n";
    for (const auto &x : songLingCar.lcd) {
        out << x;
    }
    out << "电池模块(" << songLingCar.batteryModule.size() << "个)：\n";
    for (const auto &x : songLingCar.batteryModule) {
        out << x;
    }
    return out;
}

istream &operator>>(istream &in, SongLingCar &songLingCar) {
    in >> songLingCar.id >> songLingCar.basePlate;
    int agxKitSize;
    in >> agxKitSize;
    for (int i = 0; i < agxKitSize; i++) {
        AGXKit agxKit;
        in >> agxKit;
        songLingCar.agxKit.push_back(agxKit);
    }
    int binocularCameraSize;
    in >> binocularCameraSize;
    for (int i = 0; i < binocularCameraSize; i++) {
        BinocularCamera binocularCamera;
        in >> binocularCamera;
        songLingCar.binocularCamera.push_back(binocularCamera);
    }
    int multiLineLidarSize;
    in >> multiLineLidarSize;
    for (int i = 0; i < multiLineLidarSize; i++) {
        MultiLineLidar multiLineLidar;
        in >> multiLineLidar;
        songLingCar.multiLineLidar.push_back(multiLineLidar);
    }
    int nineAxisGyroscopeSize;
    in >> nineAxisGyroscopeSize;
    for (int i = 0; i < nineAxisGyroscopeSize; i++) {
        NineAxisGyroscope nineAxisGyroscope;
        in >> nineAxisGyroscope;
        songLingCar.nineAxisGyroscope.push_back(nineAxisGyroscope);
    }
    int lcdSize;
    in >> lcdSize;
    for (int i = 0; i < lcdSize; i++) {
        LCD lcd;
        in >> lcd;
        songLingCar.lcd.push_back(lcd);
    }
    int batteryModuleSize;
    in >> batteryModuleSize;
    for (int i = 0; i < batteryModuleSize; i++) {
        BatteryModule batteryModule;
        in >> batteryModule;
        songLingCar.batteryModule.push_back(batteryModule);
    }
    return in;
}

void SongLingCar::save() {
    json j = this->toJson();
    ofstream out("SongLingCar" + to_string(time(nullptr)) + ".json");
    out << j;
    out.close();
}

json SongLingCar::toJson() {
    json j;
    j["id"] = this->id;
    j["basePlate"] = this->basePlate.toJson();
    json agxKitJson;
    for (AGXKit x : this->agxKit) {
        agxKitJson.push_back(x.toJson());
    }
    j["agxKit"] = agxKitJson;
    json binocularCameraJson;
    for (BinocularCamera x : this->binocularCamera) {
        binocularCameraJson.push_back(x.toJson());
    }
    j["binocularCamera"] = binocularCameraJson;
    json multiLineLidarJson;
    for (MultiLineLidar x : this->multiLineLidar) {
        multiLineLidarJson.push_back(x.toJson());
    }
    j["multiLineLidar"] = multiLineLidarJson;
    json nineAxisGyroscopeJson;
    for (NineAxisGyroscope x : this->nineAxisGyroscope) {
        nineAxisGyroscopeJson.push_back(x.toJson());
    }
    j["nineAxisGyroscope"] = nineAxisGyroscopeJson;
    json lcdJson;
    for (LCD x : this->lcd) {
        lcdJson.push_back(x.toJson());
    }
    j["lcd"] = lcdJson;
    json batteryModuleJson;
    for (BatteryModule x : this->batteryModule) {
        batteryModuleJson.push_back(x.toJson());
    }
    j["batteryModule"] = batteryModuleJson;
    return j;
}

void SongLingCar::fromJson(json j) {
    this->id = j["id"];
    this->basePlate.fromJson(j["basePlate"]);
    for (const auto &x : j["agxKit"]) {
        AGXKit agxKit;
        agxKit.fromJson(x);
        this->agxKit.push_back(agxKit);
    }
    for (const auto &x : j["binocularCamera"]) {
        BinocularCamera binocularCamera;
        binocularCamera.fromJson(x);
        this->binocularCamera.push_back(binocularCamera);
    }
    for (const auto &x : j["multiLineLidar"]) {
        MultiLineLidar multiLineLidar;
        multiLineLidar.fromJson(x);
        this->multiLineLidar.push_back(multiLineLidar);
    }
    for (const auto &x : j["nineAxisGyroscope"]) {
        NineAxisGyroscope nineAxisGyroscope;
        nineAxisGyroscope.fromJson(x);
        this->nineAxisGyroscope.push_back(nineAxisGyroscope);
    }
    for (const auto &x : j["lcd"]) {
        LCD lcd;
        lcd.fromJson(x);
        this->lcd.push_back(lcd);
    }
    for (const auto &x : j["batteryModule"]) {
        BatteryModule batteryModule;
        batteryModule.fromJson(x);
        this->batteryModule.push_back(batteryModule);
    }
}