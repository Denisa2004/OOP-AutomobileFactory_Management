#ifndef PETROL_CAR_H
#define PETROL_CAR_H

#include "car.h"

class PetrolCar : public Car
{
private:
    double engineCapacity;
    static double averageFuelPrice;

public:
    PetrolCar(const std::string& model, int year, double price, double engineCapacity);

    virtual ~PetrolCar() = default;

    virtual double calculateInsuranceCost() override;
    virtual int evaluateEfficiency() override;

    double getEngineCapacity() const;

    static void setAverageFuelPrice(double price);
    static double getAverageFuelPrice();

    PetrolCar& operator=(const PetrolCar& other);

    friend std::ostream& operator<<(std::ostream& os, const PetrolCar& car);
};

#endif // PETROL_CAR_H
