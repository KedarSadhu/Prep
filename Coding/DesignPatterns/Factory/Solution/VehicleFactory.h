#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include<iostream>
#include "Car.h"
#include "Bike.h"

using namespace std;

class VehicleFactory
{
    public:
    static Vehicle *getVehicle(string &type);
};

#endif