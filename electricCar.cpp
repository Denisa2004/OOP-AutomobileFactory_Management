#include "electricCar.h"

int ElectricCar::numberOfChargingStations = 150;

ElectricCar::ElectricCar(const std::string& model, int year, double price, double batteryCapacity, double range)
    : Car(model, year, price), batteryCapacity(batteryCapacity), range(range) {}

double ElectricCar::getBatteryCapacity() const
{
    return batteryCapacity;
}

double ElectricCar::getRange() const
{
    return range;
}

void ElectricCar::setChargingStations(int stations)
{
    numberOfChargingStations = stations;
}

int ElectricCar::getChargingStations()
{
    return numberOfChargingStations;
}

double ElectricCar::calculateInsuranceCost()
{
    return 0.03 * getPrice() + 0.1 * batteryCapacity + 0.01 * range;
}

int ElectricCar::evaluateEfficiency()
{
    if (range >= 500)
        return 5;
    else if (range >= 300)
        return 4;
    else if (range >= 200)
        return 3;
    else if (range >= 100)
        return 2;
    else
        return 1;
}

ElectricCar& ElectricCar::operator=(const ElectricCar& other)
{
    if (this != &other)
    {
        Car::operator=(other);
        batteryCapacity = other.batteryCapacity;
        range = other.range;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ElectricCar& car)
{
    os << "Model: " << car.getModel() << ", An fabricatie: " << car.getYear() << ", Pret: " << car.getPrice()
       << ", Capacitatea motorului: " << car.batteryCapacity << " kWh, Autonomie: " << car.range << " km";
    return os;
}

