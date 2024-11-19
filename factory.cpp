#include "Factory.h"

Factory::Factory(const std::string& name, int numberOfEmployees)
    : name(name), numberOfEmployees(numberOfEmployees) {}


Factory& Factory::operator=(const Factory& other)
{
    if (this != &other)
    {
        name = other.name;
        numberOfEmployees = other.numberOfEmployees;
        petrolCars = other.petrolCars;
        electricCars = other.electricCars;
        hybridCars = other.hybridCars;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& out, const Factory& factory)
{
    out << "Fabrica: " << factory.name << ",  Nr angajati: " << factory.numberOfEmployees << "\n";
    out << "Petrol Cars: " << factory.petrolCars.size() << "\n";
    out << "Electric Cars: " << factory.electricCars.size() << "\n";
    out << "Hybrid Cars: " << factory.hybridCars.size() << "\n";
    return out;
}

void Factory::vanzareMasina()
{
    int choice;
    std::cout << "Ce tip de masina vrei sa cumperi?\n";
    std::cout << "1. Electric\n";
    std::cout << "2. Petrol\n";
    std::cout << "3. Hybrid\n";
    std::cout << "Optiune: ";
    std::cin >> choice;

    std::vector<std::shared_ptr<Car>>* selectedVector = nullptr;
    if (choice == 1)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&electricCars);
    }
    else if (choice == 2)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&petrolCars);
    }
    else if (choice == 3)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&hybridCars);
    }
    else
    {
        std::cout << "Alegere invalidă.\n";
        return;
    }

    if (selectedVector->empty())
    {
        std::cout << "Nu sunt masini disponibile de acest tip.\n";
        return;
    }

    std::cout << "\nMasini disponibile:\n";
    for (size_t i = 0; i < selectedVector->size(); ++i)
    {
        std::cout << " - " << selectedVector->at(i)->getModel() << "\n";
    }

    std::cout << "\nScrie numele masinii pentru a cere detalii:\n";
    std::string carName;
    std::cin.ignore();
    std::getline(std::cin, carName);

    std::shared_ptr<Car> selectedCar = nullptr;

    for (const auto& car : *selectedVector)
    {
        if (car->getModel() == carName)
        {
            selectedCar = car;
            break;
        }
    }

    if (!selectedCar)
    {
        std::cout << "Masina nu a fost gasita.\n";
        return;
    }
    else
    {
        std::cout << "Detalii masina:\n";
        if (choice == 1)
        {
            std::shared_ptr<ElectricCar> electricCar = std::dynamic_pointer_cast<ElectricCar>(selectedCar);
            std::cout << *electricCar <<"\n";
        }
        else if (choice == 2)
        {
            std::shared_ptr<PetrolCar> petrolCar = std::dynamic_pointer_cast<PetrolCar>(selectedCar);
            std::cout << *petrolCar <<"\n";
        }
        else
        {
            std::shared_ptr<HybridCar> hybridCar = std::dynamic_pointer_cast<HybridCar>(selectedCar);
            std::cout << *hybridCar <<"\n";
        }
    }

    std::cout << "Vrei sa o cumperi? (Y/N): ";
    std::string buyResponse;
    std::cin >> buyResponse;

    if (buyResponse == "Y" || buyResponse == "y")
        std::cout << "Felicitari! Ai cumparat masina.\n \n";
    else
        std::cout << "Ai decis sa nu cumperi masina.\n \n";
}

void Factory::afisareCostAsigurare()
{
    int choice;
    std::cout << "Pentru ce tip de masina vrei sa vizualizezi costul asigurarii?\n";
    std::cout << "1. Electric\n";
    std::cout << "2. Petrol\n";
    std::cout << "3. Hybrid\n";
    std::cout << "Optiune: ";
    std::cin >> choice;

    std::vector<std::shared_ptr<Car>>* selectedVector = nullptr;
    if (choice == 1)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&electricCars);
    }
    else if (choice == 2)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&petrolCars);
    }
    else if (choice == 3)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&hybridCars);
    }
    else
    {
        std::cout << "Alegere invalidă.\n";
        return;
    }

    if (selectedVector->empty())
    {
        std::cout << "Nu sunt masini disponibile de acest tip.\n";
        return;
    }

    std::cout << "\nMasini disponibile:\n";
    for (size_t i = 0; i < selectedVector->size(); ++i)
    {
        std::cout << " - " << selectedVector->at(i)->getModel() << "\n";
    }

    std::cout << "\nSelecteaza masina:\n";
    std::string carName;
    std::cin.ignore();
    std::getline(std::cin, carName);

    std::shared_ptr<Car> selectedCar = nullptr;

    for (const auto& car : *selectedVector)
    {
        if (car->getModel() == carName)
        {
            selectedCar = car;
            break;
        }
    }

    if (!selectedCar)
    {
        std::cout << "Masina nu a fost gasita.\n";
        return;
    }
    else
    {
        std::cout << "Detalii masina:\n";
        if (choice == 1)
        {
            std::shared_ptr<ElectricCar> electricCar = std::dynamic_pointer_cast<ElectricCar>(selectedCar);
            std::cout << *electricCar <<"\n";

            double insuranceCost = electricCar->calculateInsuranceCost();
            std::cout << "Costul asigurarii este: " << insuranceCost << " Euro / An\n" << std::endl;

        }
        else if (choice == 2)
        {
            std::shared_ptr<PetrolCar> petrolCar = std::dynamic_pointer_cast<PetrolCar>(selectedCar);
            std::cout << *petrolCar <<"\n";
            double insuranceCost = petrolCar->calculateInsuranceCost();
            std::cout << "Costul asigurarii este: " << insuranceCost << " Euro / An\n" << std::endl;
        }
        else
        {
            std::shared_ptr<HybridCar> hybridCar = std::dynamic_pointer_cast<HybridCar>(selectedCar);
            std::cout << *hybridCar <<"\n";
            double insuranceCost = hybridCar->calculateInsuranceCost();
            std::cout << "Costul asigurarii este: " << insuranceCost << " Euro / An\n" << std::endl;
        }
    }

}

void Factory::afisareEficienta()
{
    int choice;
    std::cout << "Pentru ce tip de masina vrei sa vizualizezi eficienta?\n";
    std::cout << "1. Electric\n";
    std::cout << "2. Petrol\n";
    std::cout << "3. Hybrid\n";
    std::cout << "Optiune: ";
    std::cin >> choice;

    std::vector<std::shared_ptr<Car>>* selectedVector = nullptr;
    if (choice == 1)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&electricCars);
    }
    else if (choice == 2)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&petrolCars);
    }
    else if (choice == 3)
    {
        selectedVector = reinterpret_cast<std::vector<std::shared_ptr<Car>>*>(&hybridCars);
    }
    else
    {
        std::cout << "Alegere invalidă.\n";
        return;
    }

    if (selectedVector->empty())
    {
        std::cout << "Nu sunt masini disponibile de acest tip.\n";
        return;
    }

    std::cout << "\nMasini disponibile:\n";
    for (size_t i = 0; i < selectedVector->size(); ++i)
    {
        std::cout << " - " << selectedVector->at(i)->getModel() << "\n";
    }

    std::cout << "\nSelecteaza masina:\n";
    std::string carName;
    std::cin.ignore();
    std::getline(std::cin, carName);

    std::shared_ptr<Car> selectedCar = nullptr;

    for (const auto& car : *selectedVector)
    {
        if (car->getModel() == carName)
        {
            selectedCar = car;
            break;
        }
    }

    if (!selectedCar)
    {
        std::cout << "Masina nu a fost gasita.\n";
        return;
    }
    else
    {
        std::cout << "Detalii masina:\n";
        if (choice == 1)
        {
            std::shared_ptr<ElectricCar> electricCar = std::dynamic_pointer_cast<ElectricCar>(selectedCar);
            std::cout << *electricCar <<"\n";
            std::cout << "Eficienta masinii pe o scara de la 1 la 5 (unde 5 este maxim) este: " << electricCar->evaluateEfficiency() << std::endl << std::endl;
        }
        else if (choice == 2)
        {
            std::shared_ptr<PetrolCar> petrolCar = std::dynamic_pointer_cast<PetrolCar>(selectedCar);
            std::cout << *petrolCar <<"\n";
            std::cout << "Eficienta masinii pe o scara de la 1 la 5 (unde 5 este maxim) este: " << petrolCar->evaluateEfficiency() << std::endl << std::endl;
        }
        else
        {
            std::shared_ptr<HybridCar> hybridCar = std::dynamic_pointer_cast<HybridCar>(selectedCar);
            std::cout << *hybridCar <<"\n";
            std::cout << "Eficienta masinii pe o scara de la 1 la 5 (unde 5 este maxim) este: " << hybridCar->evaluateEfficiency() << std::endl << std::endl;
        }
    }

}


std::string Factory::getName() const
{
    return name;
}

int Factory::getNumberOfEmployees() const
{
    return numberOfEmployees;
}

void Factory::addPetrolCar(const std::shared_ptr<PetrolCar>& car)
{
    petrolCars.push_back(car);
}

void Factory::addElectricCar(const std::shared_ptr<ElectricCar>& car)
{
    electricCars.push_back(car);
}

void Factory::addHybridCar(const std::shared_ptr<HybridCar>& car)
{
    hybridCars.push_back(car);
}

