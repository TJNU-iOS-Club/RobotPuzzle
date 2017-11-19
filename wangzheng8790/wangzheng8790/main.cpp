#include <iostream>

using namespace std;

int main() {
    const int BaseMass = 2;                 //底座质量
    const int ArmMass = 1;                  //机械臂质量
    const int EngineMass = 1;               //发动机质量
    const double BattaryMass = 0.5;         //电池质量
    
    const int ArmPower = 2;                 //机械臂一次拿取货物质量
    const int BattaryPower = 3;             //电池电量分钟数
    const int EnginePower = 3;              //发动机动力值
    
    const int PutUpGoodsTime = 2;           //拿取货物时间
    const int Distance = 10;                //距离
    const int SumGoods = 20;                //总货物数
    
    double time[729];
    memset(time, 0, sizeof(time));
    int i = 0;
    double min = 1000000;
    
    for (int Arm = 1; Arm < 10; Arm++) {
        for (int Engine = 1; Engine < 10; Engine++) {
            for (int Battary = 1; Battary < 10; Battary++) {
                //总动力值
                int Power = Engine * EnginePower;
                //空载总质量
                int Mass1 = BaseMass + ArmMass * Arm + EngineMass * Engine + BattaryMass * Battary;
                //满载总质量
                int Mass2 = Mass1 + Arm * ArmPower;
                //去速度
                double Velocity1 = Power - 0.5 * Mass1;
                //回速度
                double Velocity2 = Power - 0.5 * Mass2;
                //趟数
                int toCarryCount = SumGoods / (ArmPower * Arm) + 1;
                //去时间
                double time1 = toCarryCount * (Distance / Velocity1);
                //回时间
                double time2 = toCarryCount * (Distance / Velocity2);
                if (time1 + time2 < Battary * BattaryPower && Velocity2 > 0) {
                    time[i] = toCarryCount * PutUpGoodsTime + time1 + time2;
                } else {
                    time[i] = 1000000;
                }
                i++;
            }
        }
    }
    
    i = 0;
    
    for (int j = 0; j < sizeof(time) / sizeof(double); j++) {
        if (time[j] < min) {
            min = time[j];
            i = j;
        }
    }
    
    int m = 0;
    for(int j = 1; j < 10; j++){
        for (int k = 1; k < 10; k++) {
            for (int l = 1; l < 10; l++) {
                if(m == i){
                    cout << j << "个机械臂," << k << "个发动机," << l << "个电池最快." << endl;
                    goto gun;
                }
                m++;
            }
        }
    }
gun:
    cout << "最快速度是" << min << "分钟." << endl;

    
    return 0;
}

