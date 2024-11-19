#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

#include <memory>
#include "Car.h"
#include "ElectricCar.h"
#include "PetrolCar.h"
#include "HybridCar.h"

enum CarType
{
    ELECTRIC,
    PETROL,
    HYBRID
};

class CarFactory
{
public:
    static std::shared_ptr<Car> createCar(CarType type, const std::string& model, int year, double price, double spec1, double spec2 = 0, double spec3 = 0)
    {
        switch (type)
        {
        case ELECTRIC:
            return std::make_shared<ElectricCar>(model, year, price, spec1, spec2);
        case PETROL:
            return std::make_shared<PetrolCar>(model, year, price, spec1);
        case HYBRID:
            return std::make_shared<HybridCar>(model, year, price, spec1, spec2, spec3);
        default:
            return nullptr;
        }
    }
};

#endif
