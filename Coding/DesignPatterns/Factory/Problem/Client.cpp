#include<iostream>
#include "Car.h"
#include "Bike.h"

using namespace std;

int main(void)
{
    string VehicleType;
    cin>>VehicleType;

    Vehicle *pVech = nullptr;

    if(VehicleType == "Car")
        pVech = new Car();

    else if(VehicleType == "Bike")
        pVech = new Bike();

    pVech ->createVehicle();
    
    /*Problem :: Ata samja client la Bus or Tempo chalu karaychy tr prt client code change honar tyala ajun ek if else takava lagel*/
    
    exit(0);
}