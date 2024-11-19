#ifndef EFFICIENCY_CALCULATOR_H
#define EFFICIENCY_CALCULATOR_H

#include "ElectricCar.h"
#include "PetrolCar.h"
#include "HybridCar.h"

template <typename T>
int calculateEfficiency(T& car)
{
    return car.evaluateEfficiency();
}

// Specializare pentru ElectricCar
template <>
int calculateEfficiency<ElectricCar>(ElectricCar& car)
{
    return car.getRange() / car.getBatteryCapacity() * 100;
}

#endif
