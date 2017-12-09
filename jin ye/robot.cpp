#include <iostream>
using namespace std;

int main()

{
    double t=500;
	for(int x=1;x<=9;x++)
		for(int y=1;y<=9;y++)
			for(int z=1;z<=9;z++)
			{
			
				double v1=3*z-0.5*(2+x+z+0.5*y);
				
				double v2=3*z-0.5*(2+x+z+0.5*y+2*x);
					
				if(v2<=0) 
				  cout<<"Testing robot:"<<x<<"arm,"<<y<<"battery,"<<z<<"engine,is too fat to move.";
				  
			    else
				{
			
			      double T;
				  if(20%(2*x)==0)
			        T=(10/x)*(10/v1)+(10/x)*(10/v2)+2*(10/x);
			        
				  else
			        T=(int)(10/x)*(10/v1)+(int)(10/x)*(10/v2)+10/v1+10/(3*z-0.5*(2+x+z+0.5*y+20%(2*x)))+(int)(10/x)*2+2;
			        
				  if(T>3*y)
				    cout<<"Testing robot:"<<x<<"arm,"<<y<<"battery,"<<z<<"engine,has not enough power to go";
				    
				  else
				  {
			
				    cout<<"Testing robot:"<<x<<"arm,"<<y<<"battery,"<<z<<"engine,finished at time:"<<T;
			        if(T<=t)
				      t=T	;
			      }
                 } 
				cout<<endl;
			}

	
cout<<endl<<"So the best robot finished it in "<<t<<"minutes!";
		
	
	return 0;
 } 
