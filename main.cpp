#include <iostream>
#include <fstream>
#include <vector>

#include "include/Student.h"
#include "include/car_parts/BasePlate.h"
#include "include/car_parts/AGXKit.h"
#include "include/car_parts/Camera.h"
#include "include/car_parts/Lidar.h"
#include "include/car_parts/Gyroscope.h"
#include "include/Car.h"
#include "include/relational.h"

using namespace std;
using namespace nlohmann;


int main() {
    int choice;
    cout << "1.初始化学生信息和松灵小车信息" << endl;
    cout << "2.读取学生信息和松灵小车信息" << endl;
    cout << "3.单独print 操作" << endl;
    cout << "4.单独save 操作" << endl;
    cout << "0.退出" << endl;
    cout << "请选择：";
    cin >> choice;
    while (choice < 0 || choice > 4) {
        cout << "输入错误，请重新输入：";
        cin >> choice;
    }
    while (choice) {

        if (choice == 1) { //造零件
            Tire tire("公路轮、麦克纳姆轮", 175);
            vector<Tire> tires;
            for (int i = 0; i < 4; i++) {
                tires.push_back(tire);
            }
            BasePlate basePlate("dp12345678", "SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10, tires);
            AGXKit agxKit("AGX Xavier", 32, 512, 64, 32, 32);
            Camera binocularCamera("RealSense D435i", "D430", "1920 1080", 30, 8758, 90);
            Lidar multiLineLidar("RS-Helios-16p", 16, 100, 8);
            Gyroscope nineAxisGyroscope("CH110", "NXP");
            LCD lcd("11.6", "super");
            Battery batteryModule("24V/15Ah", "24V", 2);

            //造零件集合
            vector<AGXKit> agxKits;
            agxKits.push_back(agxKit);
            vector<Camera> binocularCameras;
            binocularCameras.push_back(binocularCamera);
            vector<Lidar> multiLineLidars;
            multiLineLidars.push_back(multiLineLidar);
            vector<Gyroscope> nineAxisGyroscopes;
            nineAxisGyroscopes.push_back(nineAxisGyroscope);
            vector<LCD> lcds;
            lcds.push_back(lcd);
            vector<Battery> batteryModules;
            batteryModules.push_back(batteryModule);

            //造10台松灵小车
            vector<Car> songLingCars;
            for (int i = 1; i <= 10; i++) {
                string id = "cqusn" + to_string(i).insert(0, 16 - to_string(i).length(), '0');
                basePlate.setID("dp" + to_string(i).insert(0, 8 - to_string(i).length(), '0'));
                Car songLingCar(id, basePlate, agxKits, binocularCameras, multiLineLidars, nineAxisGyroscopes,
                                lcds,
                                batteryModules);
                songLingCars.push_back(songLingCar);
            }
            vector<Student> students;
            for (int i = 1; i <= 10; ++i) {
                string id = "E202" + to_string(i).insert(0, 4 - to_string(i).length(), '0');
                string name = "学生" + to_string(i);
                students.emplace_back(id, name);
            }

            //关联学生和松灵小车
            vector<relational> relationals;
            for (int i = 0; i < 10; i++) {
                relational relational(&students[i], &songLingCars[i]);
                relationals.push_back(relational);
            }

            //保存为json
            json j;
            for (auto x: relationals) {
                j.push_back(x.toJson());
            }
            ofstream out("out.json");
            out << j;
            out.close();
            cout<<"初始化成功"<<endl;
        }
        if (choice == 2) {
            //in
            try {
                ifstream in("out.json");
                json j;
                in >> j;
                vector<relational> relationals;
                for (auto x: j) {
                    relational relational(new Student(), new Car());
                    relational.fromJson(x);
                    relationals.push_back(relational);
                }
                //一次显示1辆小车信息，按n键显示下一辆小车信息，按p显示上一辆小车信息。请注意：显示第1台显示按p无效，显示第10台小车，按n无效。
                int index = 0;
                char c;
                relationals[index].show();
                cout << "按n键显示下一辆小车信息，按p显示上一辆小车信息" << endl;
                cin >> c;
                while (c == 'n' || c == 'p') {
                    if (c == 'n') {
                        if (index == 9) {
                            cout << "已经是最后一辆小车了" << endl;
                        }
                        if (index < 9) {
                            index++;
                            relationals[index].show();
                        }
                    } else if (c == 'p') {
                        if (index == 0) {
                            cout << "已经是第一辆小车了" << endl;
                        }
                        if (index > 0) {
                            index--;
                            relationals[index].show();
                        }
                    }
                    cin >> c;
                }
            }
            catch (exception &e) {
                cout << "文件读取错误,未初始化" << endl;
                cout << e.what() << endl;
                exit(1);
            }
        }
        if (choice == 3) {
            Car songLingCar("cqusn0000000000000",
                            BasePlate("dp00000000", "SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10,
                                              vector<Tire>(4, Tire("公路轮、麦克纳姆轮", 175))),
                            vector<AGXKit>(1, AGXKit("AGX Xavier", 32, 512, 64, 32, 32)),
                            vector<Camera>(1,
                                                   Camera("RealSense D435i", "D430", "1920 1080", 30,
                                                          8758, 90)),
                            vector<Lidar>(1, Lidar("RS-Helios-16p", 16, 100, 8)),
                            vector<Gyroscope>(1, Gyroscope("CH110", "NXP")),
                            vector<LCD>(1, LCD("11.6", "super")),
                            vector<Battery>(1, Battery("24V/15Ah", "24V", 2)));
            cout << "1.print 小车信息" << endl;
            cout << "2.print 底盘信息" << endl;
            cout << "3.print AGX套件信息" << endl;
            cout << "4.print 双目摄像头信息" << endl;
            cout << "5.print 9轴陀螺仪信息" << endl;
            cout << "6.print 多线激光雷达信息" << endl;
            cout << "7.print 液晶显示屏信息" << endl;
            cout << "8.print 电池模块信息" << endl;
            cout << "0.退出" << endl;
            cout << "请选择：";
            int choice3;
            cin >> choice3;
            while (choice3 < 0 || choice3 > 8) {
                cout << "输入错误，请重新输入：";
                cin >> choice3;
            }
            while (choice3) {
                if (choice3 == 1) {
                    songLingCar.print();
                }
                if (choice3 == 2) {
                    songLingCar.basePlate.print();
                }
                if (choice3 == 3) {
                    for (auto x: songLingCar.agxKit) {
                        x.print();
                    }
                }
                if (choice3 == 4) {
                    for (auto x: songLingCar.binocularCamera) {
                        x.print();
                    }
                }
                if (choice3 == 5) {
                    for (auto x: songLingCar.nineAxisGyroscope) {
                        x.print();
                    }
                }
                if (choice3 == 6) {
                    for (auto x: songLingCar.multiLineLidar) {
                        x.print();
                    }
                }
                if (choice3 == 7) {
                    for (auto x: songLingCar.lcd) {
                        x.print();
                    }
                }
                if (choice3 == 8) {
                    for (auto x: songLingCar.batteryModule) {
                        x.print();
                    }
                }

                cout << "按回车键继续" << endl;
                cin.get();
                cin.get();
                cout << "1.print 小车信息" << endl;
                cout << "2.print 底盘信息" << endl;
                cout << "3.print AGX套件信息" << endl;
                cout << "4.print 双目摄像头信息" << endl;
                cout << "5.print 9轴陀螺仪信息" << endl;
                cout << "6.print 多线激光雷达信息" << endl;
                cout << "7.print 液晶显示屏信息" << endl;
                cout << "8.print 电池模块信息" << endl;
                cout << "0.退出" << endl;
                cout << "请选择：";
                cin >> choice3;
                if (choice3 == 0) {
                    break;
                }
            }
        }
        if (choice == 4) {
            Car songLingCar("cqusn0000000000000",
                            BasePlate("dp00000000", "SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10,
                                              vector<Tire>(4, Tire("公路轮、麦克纳姆轮", 175))),
                            vector<AGXKit>(1, AGXKit("AGX Xavier", 32, 512, 64, 32, 32)),
                            vector<Camera>(1,
                                                   Camera("RealSense D435i", "D430", "1920 1080", 30,
                                                          8758, 90)),
                            vector<Lidar>(1, Lidar("RS-Helios-16p", 16, 100, 8)),
                            vector<Gyroscope>(1, Gyroscope("CH110", "NXP")),
                            vector<LCD>(1, LCD("11.6", "super")),
                            vector<Battery>(1, Battery("24V/15Ah", "24V", 2)));
            cout << "1.save 小车信息" << endl;
            cout << "2.save 底盘信息" << endl;
            cout << "3.save AGX套件信息" << endl;
            cout << "4.save 双目摄像头信息" << endl;
            cout << "5.save 9轴陀螺仪信息" << endl;
            cout << "6.save 多线激光雷达信息" << endl;
            cout << "7.save 液晶显示屏信息" << endl;
            cout << "8.save 电池模块信息" << endl;
            cout << "0.退出" << endl;
            cout << "请选择：";
            int choice4;
            cin >> choice4;
            while (choice4 < 0 || choice4 > 8) {
                cout << "输入错误，请重新输入：";
                cin >> choice4;
            }
            while (choice4) {
                if (choice4 == 1) {
                    songLingCar.save();
                }
                if (choice4 == 2) {
                    songLingCar.basePlate.save();
                }
                if (choice4 == 3) {
                    for (auto x: songLingCar.agxKit) {
                        x.save();
                    }
                }
                if (choice4 == 4) {
                    for (auto x: songLingCar.binocularCamera) {
                        x.save();
                    }
                }
                if (choice4 == 5) {
                    for (auto x: songLingCar.nineAxisGyroscope) {
                        x.save();
                    }
                }
                if (choice4 == 6) {
                    for (auto x: songLingCar.multiLineLidar) {
                        x.save();
                    }
                }
                if (choice4 == 7) {
                    for (auto x: songLingCar.lcd) {
                        x.save();
                    }
                }
                if (choice4 == 8) {
                    for (auto x: songLingCar.batteryModule) {
                        x.save();
                    }
                }
                cout << "按回车键继续" << endl;
                cin.get();
                cin.get();
                cout << "1.save 小车信息" << endl;
                cout << "2.save 底盘信息" << endl;
                cout << "3.save AGX套件信息" << endl;
                cout << "4.save 双目摄像头信息" << endl;
                cout << "5.save 9轴陀螺仪信息" << endl;
                cout << "6.save 多线激光雷达信息" << endl;
                cout << "7.save 液晶显示屏信息" << endl;
                cout << "8.save 电池模块信息" << endl;
                cout << "0.退出" << endl;
                cout << "请选择：";
                cin >> choice4;
                if (choice4 == 0) {
                    break;
                }
            }
        }
        cout << "1.初始化学生信息和松灵小车信息" << endl;
        cout << "2.读取学生信息和松灵小车信息" << endl;
        cout << "3.单独print 操作" << endl;
        cout << "4.单独save 操作" << endl;
        cout << "0.退出" << endl;
        cout << "请选择：";
        cin >> choice;
    }
}