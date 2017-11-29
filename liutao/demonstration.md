## Mathematical formula 
#    证明如下
设机械手臂为x,发动机为y,电池为z，质量为 m1,m2, 速度为 v1, v2 时间为：t1,t2,t,次数为n ,N为正整数。

其中 m1,m2,v1,v2,t1,t2,n>0



```math


9>=x>=1   

9>=y>=1

9>=z>=1

m1=2+x+y+0.5z

m2=2+x+y+0.5z+2x

v1=3y-0.5m1

v2=3y-0.5m2

n=\frac{10}{x} (x\in2N or x=1)

n=\left\lceil\frac2x5\right\rceil+1  (x\notin 2N and x\neq1)

t1=(\frac{10}{v1}+2)n

t2=\frac{10}{v2}

t=t1+t2

t=\left(\frac{10}{2.5y-0.25z-0.5x}+\frac{10}{2.5y-0.25z-1.5x}+2\right)\frac{10}{x}  (x\in2N or x=1)

or 

t=\left(\frac{10}{2.5y-0.25z-0.5x}+\frac{10}{2.5y-0.25z-1.5x}+2\right)(\left\lceil\frac2x5\right\rceil+1) (x\notin 2N and x\neq1)



```

## 上述公式推理跳跃了N步

   但是式子我不会解 可以用函数图像反应，但是我也不会画图
   
   
   综上可以证明结论