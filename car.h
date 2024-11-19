#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car
{
private:
    std::string model;
    int year;
    double price;

public:

    Car();
    Car(const std::string& model, int year, double price);

    virtual ~Car() = default;

    virtual double calculateInsuranceCost() = 0;
    virtual int evaluateEfficiency() = 0;

    std::string getModel() const;
    int getYear() const;
    double getPrice() const;

    static int numberOfCarsProduced;
    static int getNumberOfCarsProduced();

    Car& operator=(const Car& other);

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};

#endif // CAR_H
