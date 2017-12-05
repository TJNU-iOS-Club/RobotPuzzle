#include <iostream>
using namespace std;



// s=10;
// m=arm*1+engine*1+bat*0.5+2;///Users/jiayusong/Documents/robort/main.cpp
//M=arm*(1+2)+engine*1+bat*0.5+2;
//getm=arm*2;
// p=3*engine;
//vm=p-0.5*m;
//vM=p-0.5*M;
// t=bat*3

int main()
{
    int arm,engine,bat;//机械臂个数，发动机个数，电池个数，
    float t,t1,min,getm,Getm;//供电时间，第一次拿货物需要的时间，运输总时间，每次最多可拿的物重/第一次拿到的物重,共计已经拿到的货物；
    float M,m,vm,vM,s,p,tm;//分别：机器人加上货物总重量,机器人的重量，不装货物时的运输速度，装了货物的运输速度，运输总路程，动力总值,最优时间
    int ar,en,ba;//题目最优解对应的三个器件的数量
    tm=27;
    s=10;
    for( arm=1; arm<=9; arm++)
    {
        for( engine=1; engine<=9; engine++)
        {
            for( bat=1; bat<=9; bat++)
            {
                getm=2*arm;
                p=engine*3;
                t=bat*3;
                Getm=getm;//第一次的来回所获得的货重
                M=arm*(1+2)+engine*1+bat*0.5+2;
                vM=p-0.5*M;
                m=arm*1+engine*1+bat*0.5+2;
                vm=p-0.5*m;
                
                if(vM>0)//始终能运动时  分两种情况
                {
                    t1=2+s/vm+s/ vM;//第一次的来回所用时间
                    min=t1;
                
                    for(;Getm<=20;)//计算完成任务总时间
                    {
                        min=t1+min;
                        Getm=getm+Getm;//第一次的来回所获得的货重加入总时间，累加
                        
                    }
                    if(vM>0 && min<=t) //1，不会发生供电不足的情况
                    {
                        cout << "Testing robot:" ;
                        cout << arm << ' ' << "arm,";
                        cout << engine << ' ' << "engine,";
                        cout << bat << ' ' << "battery," ;
                        cout << "finished at time :" << min << endl;
                    }
                    else //否则输出无法完成任务
                    {
                        cout << "Testing robot:" << ' ';
                        cout << arm << ' ' << "arm,";
                        cout << engine << ' ' << "engine,";
                        cout << bat << ' ' << "battery,";
                        cout << ' ' << "can't finish" << endl;
                    }
                    
                    if(min<=tm && min<=t)
                    {
                        tm=min;
                        ar=arm;
                        en=engine;
                        ba=bat;
                    }
                }
                else //否则输出无法完成任务
                {
                    cout << "Testing robot:" << ' ';
                    cout << arm << ' ' << "arm,";
                    cout << engine << ' ' << "engine,";
                    cout << bat << ' ' << "battery,";
                    cout << ' ' << "can't finish" << endl;
                }
            }
        }
    }
    
    
    cout << "Best Testing robot:" ;
    cout << ar << ' ' << "arm,";
    cout << en << ' ' << "engine,";
    cout << ba << ' ' << "battery," ;
    cout << "finished at time :" << tm << endl;
    return 0;
}
