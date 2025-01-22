#include<iostream>
#include "VehicleFactory.h"
 
using namespace std;

int main(void)
{
    string VehicleType;
    cin>>VehicleType;

    Vehicle *pVech = VehicleFactory::getVehicle(VehicleType);
    pVech ->createVehicle();

    exit(0);
}