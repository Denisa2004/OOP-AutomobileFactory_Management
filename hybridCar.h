#ifndef HYBRID_CAR_H
#define HYBRID_CAR_H

#include "car.h"

class HybridCar : public Car
{
private:
    double batteryCapacity;
    double engineCapacity;
    double range;
public:
    HybridCar(const std::string& model, int year, double price, double batteryCapacity, double engineCapacity, double range);

    virtual ~HybridCar() = default;

    virtual double calculateInsuranceCost() override;
    virtual int evaluateEfficiency() override;

    double getBatteryCapacity() const;
    double getEngineCapacity() const;
    double getRange() const;

    HybridCar& operator=(const HybridCar& other);

    friend std::ostream& operator<<(std::ostream& os, const HybridCar& car);
};

#endif // HYBRID_CAR_H

