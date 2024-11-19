#include "hybridCar.h"
#include "petrolCar.h"
#include "electricCar.h"

HybridCar::HybridCar(const std::string& model, int year, double price, double batteryCapacity, double engineCapacity, double range)
    : Car(model, year, price), batteryCapacity(batteryCapacity), engineCapacity(engineCapacity), range(range) {}


double HybridCar::getRange() const
{
    return range;
}

double HybridCar::getBatteryCapacity() const
{
    return batteryCapacity;
}

double HybridCar::getEngineCapacity() const
{
    return engineCapacity;
}

double HybridCar::calculateInsuranceCost()
{
    return 0.05 * getPrice() + 0.1 * batteryCapacity + 0.2 * engineCapacity + 0.01 * range;
}

int HybridCar::evaluateEfficiency()
{
    int k1, k2;
    if (range >= 500)
        k1=5;
    else if (range >= 300)
        k1=4;
    else if (range >= 200)
        k1=3;
    else if (range >= 100)
        k1=2;
    else
        k1=1;

    if (getEngineCapacity() <= 1.5)
        k2=5;
    else if (getEngineCapacity() <= 2.0)
        k2=4;
    else if (getEngineCapacity() <= 2.5)
        k2=3;
    else if (getEngineCapacity() <= 3.0)
        k2=2;
    else
        k2=1;

    return int((k1 + k2) / 2);
}


HybridCar& HybridCar::operator=(const HybridCar& other)
{
    if (this != &other)
    {
        Car::operator=(other);
        batteryCapacity = other.batteryCapacity;
        engineCapacity = other.engineCapacity;
        range = other.range;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const HybridCar& car)
{
    os << "Model: " << car.getModel() << ", An fabricatie: " << car.getYear() << ", Pret: " << car.getPrice()
       << ", Capacitatea motorului: " << car.batteryCapacity << " kWh, " << car.engineCapacity << " litri"
       << ", Autonomie: " << car.range << " km";
    return os;
}

