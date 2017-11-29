#include<iostream>
using namespace std;

int main()
{   
  
   int arm , engine , battery , numble , pedestal = 2 , pathlength = 10 ;                         //定义一个数组 0~9 而只用1~9  其他1000-729的数 默认为零， 
   double velocity_1 , velocity_2 ,  mass_1 , mass_2 , time_1 , time_2 , time[10][10][10] ={0};  //这样数组下标就不用从0开始， 数组下标即是arm ,engine, battery. 
   for(arm = 1 ; arm <= 9 ; arm++ )
    {
		if(20%(arm * 2) == 0)
		 numble = 20 / (arm * 2);
		 else numble = 20 / (arm * 2) + 1;
		for(engine = 1 ; engine <= 9 ; engine++ ) 
			for( battery = 1 ; battery <= 9 ; battery++)
			{ 
			  cout<<"arm="<<arm<<"  "<<"engine="<<engine<<"  "<<"battery="<<battery<<"  ";
			  mass_1 = pedestal + arm + engine + 0.5*battery  ;                                                       // 机器人去拿货的路上的质量 
			  mass_2 = pedestal + arm + engine + 0.5*battery  + 2*arm ;                                               //  机器人回来的路上的总质量
			  velocity_1 = 3*engine - 0.5*mass_1;                                                                    // 机器人去拿货的路上的速度 
			  velocity_2 = 3*engine - 0.5*mass_2;                                                                   //机器人在回来的路上的速度
			if(velocity_1>0&&velocity_2>0){
			  	 time_1 = numble * (pathlength/velocity_1 + 2) ;                                                   //机器人在去拿货路上和拿货的时间 
			  	 time_2 = numble * (pathlength/velocity_2);                                                       // 机器人回来的路上的时间 
			  	 if(3 * battery >= time_1+time_2){
			  		time[arm][engine][battery] = time_1 + time_2;
			  		 if(time[arm][engine][battery]>0){
			  		 	cout<<"time="<<time[arm][engine][battery]<<endl;
					   }
			  			
					  
			  		
			  	}
			  	else
			    	cout<<"\n";
			    }
			else 
				 cout<<"\n";
		
			
		    }
     }
  //接下来用打擂法进行比较 选出最小值 
    int  a , b , c;
     for(arm = 1 ; arm <= 9 ; arm++ ) 
       	for(engine = 1 ; engine <= 9 ; engine++ )
       		for( battery = 1 ; battery <= 9 ; battery++)
       			 if(time[arm][engine][battery]>0)
					{                                                                                //此过程为选取出一个大于0的time用于后面的比较 
       			 	  a = arm ; b = engine  ; c =  battery  ;
       			 	  
					}
					
     for(arm = 1 ; arm <= 9 ; arm++ ) 
       	for(engine = 1 ; engine <= 9 ; engine++ )
       		for( battery = 1 ; battery <= 9 ; battery++)                                             
			   if(time[arm][engine][battery]>0&&time[a][b][c]>time[arm][engine][battery])
			   {                                                                                     //此过程为循环筛选出最小值 
			   	  	a = arm ; b = engine  ; c = battery  ;		   	  	 
					  
			   }  			 
			   
      cout<<"Best robot："<<"arm="<<a<<"  "<<"engine="<<b<<"  "<<"battery="<<c<<"  "<<"finished at time="<<time[a][b][c]<<endl; 
     system("pause");
    return 0;
 } 
