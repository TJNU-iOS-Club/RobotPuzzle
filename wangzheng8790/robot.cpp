#include <iostream>

using namespace std;

void printTest(int, int, int, double);

int main() {
    const int BaseMass = 2;                 //底座质量
    const int ArmMass = 1;                  //机械臂质量
    const int EngineMass = 1;               //发动机质量
    const double BatteryMass = 0.5;         //电池质量
    
    const int ArmPower = 2;                 //机械臂一次拿取货物质量
    const int BatteryPower = 3;             //电池电量分钟数
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
            for (int Battery = 1; Battery < 10; Battery++) {
                //总动力值
                double Power = Engine * EnginePower;
                //空载总质量
                double Mass1 = BaseMass + ArmMass * Arm + EngineMass * Engine + BatteryMass * Battery;
                //满载总质量
                double Mass2 = Mass1;
                //去速度
                double Velocity1 = Power - 0.5 * Mass1;
                //回速度
                double Velocity2 = 0;
                //趟数
                int toCarryCount = SumGoods / (ArmPower * Arm) + 1;
                //去时间
                double time1 = toCarryCount * (Distance / Velocity1);
                //回时间
                double time2 = 0;
                //剩余货物数
                int residurGoods = 20;
                
                for(int j = 0; j < toCarryCount; j++){
                    if(residurGoods > ArmPower * Arm){
                        Mass2 += ArmPower * Arm;
                    }else{
                        Mass2 += residurGoods;
                    }
                    Velocity2 = Power - 0.5 * Mass2;
                    time2 += Distance / Velocity2;
                    
                    residurGoods -= Arm * ArmPower;
                }
                
                
                if (time1 + time2 < Battery * BatteryPower && Velocity2 > 0) {
                    time[i] = toCarryCount * PutUpGoodsTime + time1 + time2;
                } else {
                    time[i] = 1000000;
                }
                printTest(Arm, Engine, Battery, time[i]);
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
                    cout << endl << "The best robot: " << j;
                    if(j > 1){
                        cout << " arms, ";
                    }else{
                        cout << " arm , ";
                    }
                    cout << k;
                    if (k > 1) {
                        cout << " engines, ";
                    }else{
                        cout << " engine , ";
                    }
                    cout << l;
                    if (l > 1) {
                        cout << " Batterys, ";
                    }else{
                        cout << " Battery , ";
                    }
                    goto gun;
                }
                m++;
            }
        }
    }
gun:
    cout << "finished at time:" << min << endl;

    
    return 0;
}

//Testing robot: 4 arm, 4 engine, 4 battery, finished at time:xx
void printTest(int Arm, int Engine, int Battery, double timeing){
    cout << "Testing robot: " << Arm;
    if(Arm > 1){
        cout << " arms, ";
    }else{
        cout << " arm , ";
    }
    cout << Engine;
    if (Engine > 1) {
        cout << " engines, ";
    }else{
        cout << " engine , ";
    }
    cout << Battery;
    if (Battery > 1) {
        cout << " Batterys, ";
    }else{
        cout << " Battery , ";
    }
    if(timeing == 1000000){
        cout << "this robot can't finish the job." << endl;
    }else{
        cout << "finished at time:" << timeing << endl;
    }
    
}
