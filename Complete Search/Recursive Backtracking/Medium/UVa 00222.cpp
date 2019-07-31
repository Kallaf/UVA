#include<iostream>
#include<math.h>
#define round(val) roundf(val * 100) / 100
#define currCost minCost(tankCapacity,currentStation,currentStation,currentStation+1)+2.0+round(prices[currentStation]/100*(tankCapacity-tankGasoline))
#define preCost minCost(previousTankGasoline,currentStation,lastStation,currentStation+1)
using namespace std;

double ODDistance,tankCapacity,milesPerGallon;
int n,dataset=1;
double distances[60]={0},prices[60];

double minCost(double previousTankGasoline,int previousStation,int lastStation,int currentStation)
{
	if(currentStation == n+1)return 0;
	double tankGasoline = previousTankGasoline - (distances[currentStation]   - distances[lastStation]) / milesPerGallon;
	double nextGasoline = previousTankGasoline - (distances[currentStation+1] - distances[lastStation]) / milesPerGallon;
	double cost;
	if(nextGasoline <= 0)
		cost = currCost;
	else if(tankGasoline <= tankCapacity/2.0)
		cost = min(currCost,preCost);
	else
		cost = preCost;
	return cost;
}

int main() {
    while(1)
    {
    	scanf("%lf",&ODDistance);
    	if(int(ODDistance) == -1)break;
    	scanf("%lf%lf%lf%d",&tankCapacity,&milesPerGallon,&prices[0],&n);
    	for(int i=1;i<=n;i++)scanf("%lf%lf",&distances[i],&prices[i]);
		distances[n+1] = ODDistance;
		printf("Data Set #%d\nminimum cost = $%.2lf\n",dataset++,minCost(tankCapacity,0,0,1)+round(prices[0]));
    }
    return 0;
}
