#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "car.h"

class ElectricCar : public Car
{
private:
    double batteryCapacity;
    double range;
    static int numberOfChargingStations;

public:
    ElectricCar(const std::string& model, int year, double price, double batteryCapacity, double range);

    virtual ~ElectricCar() = default;

    virtual double calculateInsuranceCost() override;
    virtual int evaluateEfficiency() override;

    ElectricCar& operator=(const ElectricCar& other);

    double getBatteryCapacity() const;
    double getRange() const;

    static void setChargingStations(int stations);
    static int getChargingStations();

    friend std::ostream& operator<<(std::ostream& os, const ElectricCar& car);
};

#endif // ELECTRIC_CAR_H

