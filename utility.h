#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <memory>
#include "Car.h"
#include "CarFleet.h"

// Funcție pentru calcularea valorii totale a unei flote de mașini
template <typename T>
double calculateTotalValue(const std::vector<std::shared_ptr<T>>& cars)
{
    double total = 0;
    for (const auto& car : cars)
    {
        total += car->getPrice();
    }
    return total;
}

// Funcție supraincarcată pentru calcularea valorii totale a unei flote de mașini
template <typename T>
double calculateTotalValue(const CarFleet<T>& fleet)
{
    return fleet.getTotalValue();
}

// Specializare pentru ElectricCar
template <>
double calculateTotalValue<ElectricCar>(const std::vector<std::shared_ptr<ElectricCar>>& cars)
{
    double total = 0;
    for (const auto& car : cars)
    {
        total += car->getPrice();
    }
    // Se mareste cu 10%
    return total * 1.1;
}

#endif
