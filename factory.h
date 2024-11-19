#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Car.h"
#include "PetrolCar.h"
#include "ElectricCar.h"
#include "HybridCar.h"


class Factory
{
private:
    std::string name;
    int numberOfEmployees;

    std::vector<std::shared_ptr<PetrolCar>> petrolCars;
    std::vector<std::shared_ptr<ElectricCar>> electricCars;
    std::vector<std::shared_ptr<HybridCar>> hybridCars;

public:

    Factory(const std::string& name, int numberOfEmployees);

    Factory& operator=(const Factory& other);

    friend std::ostream& operator<<(std::ostream& out, const Factory& factory);

    void vanzareMasina();
    void afisareCostAsigurare();
    void afisareEficienta();

    std::string getName() const;
    int getNumberOfEmployees() const;

    void addPetrolCar(const std::shared_ptr<PetrolCar>& car);
    void addElectricCar(const std::shared_ptr<ElectricCar>& car);
    void addHybridCar(const std::shared_ptr<HybridCar>& car);
};

#endif

