#include<iostream>
#define base 1
using namespace std;
int main()
{
    int arm, eng ,bat;                                                  //机械臂 电池 发动机的个数
    float mas, Mass, power, v1, v, s;                                   //机器人总重量 加上货物的质量   动力 机器人速度   加上货物速度  距离
    float t1, t, M1, M ;                                                //分段时间 总时间    拿走的货物质量     拿走的质量
    int mini;                                                           //供电时间
    float a, e, b ,n;                                                   //存储最佳
    s = 10;                                                             //距离
    n = 81;                                                             //取一个供电时间最大值为参数
    for(arm = 1;arm <= 9;arm ++)
    {
        for(eng = 1; eng <= 9; eng++)
        {
            for(bat = 1; bat <= 9; bat++)
            {
                mas = base*2 + arm*1 + eng*0.5 + bat*1;                 //机器人本身的质量
                Mass = base*2 + arm*3 + eng*0.5 + bat*1;                //机器人本身加上货物的质量
                M1 = arm*2;                                             //每次拿货物的质量
                M = M1;                                                 //第一次拿货物的质量
                power = bat*3;                                          //动力
                mini = eng*3;                                           //能供电的最长时间
                v1 = power - 0.5*mas;                                   //前往拿货物的速度
                v = power - 0.5*Mass;                                   //拿货物回去的速度
                if(v > 0)                                               //当速度大于零时才可以运行
                {
                  t1 = s/v + s/v1 + 2;                                  //往返一次的时间
                  t = t1;                                               //第一次往返的时间
                  for(; M < 20;)                                        //当总质量不小于20时，停止计算
                  {
                      t = t + t1;                                       //总共花费的时间
                      M = M + M1;                                       //运送货物的总质量
                  }
                  if(t <= mini)                                         //花费时间必须小于能供电的最长时间
                    {
                    cout<<"Testing robot:"<<' ';
                    cout<<arm<<' '<<"arm,";
                    cout<<eng<<' '<<"engine,";
                    cout<<bat<<' '<<"battery,"<<' ';
                    cout<<"finished at time :"<<t<<endl;
                    }
                    else
                    {
                       cout<<"Testing robot:"<<' ';
                       cout<<arm<<' '<<"arm,";
                       cout<<eng<<' '<<"engine,";
                       cout<<bat<<' '<<"battery,";
                       cout<<' '<<"can't finish"<<endl;                //输出日志
                    }
                  if(t < n&&t <= mini)                                 //存储最小时间以及里面的参数
                  {
                      n = t;
                      a = arm;
                      e = eng;
                      b = bat;
                  }
                }
                else
                {
                       cout<<"Testing robot:"<<' ';
                       cout<<arm<<' '<<"arm,";
                       cout<<eng<<' '<<"engine,";
                       cout<<bat<<' '<<"battery,";
                       cout<<' '<<"can't finish"<<endl;                //当速度小于零时的日志输出
                 }
           }
        }
    }
    cout<<"Best robot:"<<a<<' '<<"arm,";                               //输出最佳
    cout<<e<<' '<<"engine,";
    cout<<b<<' '<<"battery,";
    cout<<"finished at time :"<<n<<endl;
    return 0;
}
