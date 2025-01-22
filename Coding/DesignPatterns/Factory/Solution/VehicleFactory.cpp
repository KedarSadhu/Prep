#include "VehicleFactory.h"

Vehicle * VehicleFactory::getVehicle(string &type)
{
    Vehicle *pVech = nullptr;

    if(type == "Car")
        pVech = new Car();

    else if(type == "Bike")
        pVech = new Bike();

    return pVech;
}