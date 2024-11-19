#include "car.h"

int Car::numberOfCarsProduced = 0;

Car::Car() : model(""), year(0), price(0.0) {}

Car::Car(const std::string& model, int year, double price)
    : model(model), year(year), price(price)
{
    numberOfCarsProduced++;
}

std::string Car::getModel() const
{
    return model;
}

int Car::getYear() const
{
    return year;
}

double Car::getPrice() const
{
    return price;
}

int Car::getNumberOfCarsProduced()
{
    return numberOfCarsProduced;
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        model = other.model;
        year = other.year;
        price = other.price;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "Model: " << car.model << ", An fabricatie: " << car.year << ", Pret: " << car.price;
    return os;
}

