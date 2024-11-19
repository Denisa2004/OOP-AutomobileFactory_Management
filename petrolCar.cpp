#include "petrolCar.h"

double PetrolCar::averageFuelPrice = 8.9;

PetrolCar::PetrolCar(const std::string& model, int year, double price, double engineCapacity)
    : Car(model, year, price), engineCapacity(engineCapacity) {}

double PetrolCar::getEngineCapacity() const
{
    return engineCapacity;
}

void PetrolCar::setAverageFuelPrice(double price)
{
    averageFuelPrice = price;
}

double PetrolCar::getAverageFuelPrice()
{
    return averageFuelPrice;
}

double PetrolCar::calculateInsuranceCost()
{
    return 0.05 * getPrice() + 0.2 * engineCapacity;
}

int PetrolCar::evaluateEfficiency()
{
    if (getEngineCapacity() <= 1.5)
        return 5;
    else if (getEngineCapacity() <= 2.0)
        return 4;
    else if (getEngineCapacity() <= 2.5)
        return 3;
    else if (getEngineCapacity() <= 3.0)
        return 2;
    else
        return 1;
}

PetrolCar& PetrolCar::operator=(const PetrolCar& other)
{
    if (this != &other)
    {
        Car::operator=(other);
        engineCapacity = other.engineCapacity;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PetrolCar& car)
{
    os << "Model: " << car.getModel() << ", An fabricatie: " << car.getYear() << ", Pret: " << car.getPrice()
    << ", Capacitatea motorului: " << car.engineCapacity << " litri";
    return os;
}

