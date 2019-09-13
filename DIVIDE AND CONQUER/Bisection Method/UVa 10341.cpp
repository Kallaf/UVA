#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
 
double p, q, r, s, t , u;

double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
 
inline double round( double val )
{
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

int main(){
	while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		double a = 0,b=1;
		double fa = f(a),fb = f(b);
		//printf("%.4lf %.4lf\n", f(a),f(b));

		if(min(fa,fb) > 0 || max(fa,fb) < 0)
		{
			printf("No solution\n");
			continue;
		}
		while(a<b)
		{
			double d = (a+b)/2;
			double result = f(d) * (fa > fb?-1:1);
			result = round( result * 100000000.0 ) / 100000000.0;
			if(result < 0)a = d;
			else if(result > 0)b = d;
			else{
				printf("%.4lf\n", d);
				break;
			}
		}
	}
    return 0;
}
