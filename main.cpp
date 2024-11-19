#include <iostream>

#include "Factory.h"
#include "carFactory.h"
#include "carFleet.h"
#include "utility.h"
#include "efficiency.h"
#include "configurationManager.h"

using namespace std;

int main()
{
    // Utilizarea șablonului Singleton pentru ConfigurationManager
    ConfigurationManager* configManager = ConfigurationManager::getInstance();
    std::cout << "Configurarea initiala: " << configManager->getConfigData() << std::endl;
    configManager->setConfigData("Configurare noua");
    std::cout << "Configurarea actualizata: " << configManager->getConfigData() << std::endl;

    // Crearea unei instanțe a unei fabrici de mașini
    Factory factory("FabricaAuto", 100);

    // Utilizarea șablonului Factory pentru a crea instanțe de mașini
    auto petrolCar1 = std::dynamic_pointer_cast<PetrolCar>(CarFactory::createCar(PETROL, "BMW X5", 2023, 60000, 3.0));
    auto petrolCar2 = std::dynamic_pointer_cast<PetrolCar>(CarFactory::createCar(PETROL, "Audi A6", 2022, 55000, 2.5));
    auto electricCar1 = std::dynamic_pointer_cast<ElectricCar>(CarFactory::createCar(ELECTRIC, "Tesla Model S", 2024, 80000, 100, 400));
    auto electricCar2 = std::dynamic_pointer_cast<ElectricCar>(CarFactory::createCar(ELECTRIC, "Nissan Leaf", 2023, 35000, 60, 250));
    auto hybridCar1 = std::dynamic_pointer_cast<HybridCar>(CarFactory::createCar(HYBRID, "Toyota Prius", 2024, 45000, 50, 1.8, 600));
    auto hybridCar2 = std::dynamic_pointer_cast<HybridCar>(CarFactory::createCar(HYBRID, "Lexus NX", 2023, 60000, 40, 2.0, 500));
    auto petrolCar3 = std::dynamic_pointer_cast<PetrolCar>(CarFactory::createCar(PETROL, "Mercedes-Benz C-Class", 2024, 60000, 2.0));
    auto petrolCar4 = std::dynamic_pointer_cast<PetrolCar>(CarFactory::createCar(PETROL, "Porsche 911", 2023, 150000, 4.0));
    auto petrolCar5 = std::dynamic_pointer_cast<PetrolCar>(CarFactory::createCar(PETROL, "Ford Mustang", 2023, 45000, 5.0));

    auto electricCar3 = std::dynamic_pointer_cast<ElectricCar>(CarFactory::createCar(ELECTRIC, "Chevrolet Bolt", 2024, 40000, 80, 300));
    auto electricCar4 = std::dynamic_pointer_cast<ElectricCar>(CarFactory::createCar(ELECTRIC, "Jaguar I-PACE", 2023, 75000, 90, 350));
    auto electricCar5 = std::dynamic_pointer_cast<ElectricCar>(CarFactory::createCar(ELECTRIC, "Audi e-tron", 2024, 85000, 95, 380));

    auto hybridCar3 = std::dynamic_pointer_cast<HybridCar>(CarFactory::createCar(HYBRID, "Honda Accord Hybrid", 2024, 38000, 45, 2.0, 550));
    auto hybridCar4 = std::dynamic_pointer_cast<HybridCar>(CarFactory::createCar(HYBRID, "Kia Niro Hybrid", 2023, 32000, 40, 1.6, 500));
    auto hybridCar5 = std::dynamic_pointer_cast<HybridCar>(CarFactory::createCar(HYBRID, "Hyundai Ioniq Hybrid", 2024, 36000, 42, 1.5, 520));



    factory.addPetrolCar(petrolCar1);
    factory.addPetrolCar(petrolCar2);
    factory.addElectricCar(electricCar1);
    factory.addElectricCar(electricCar2);
    factory.addHybridCar(hybridCar1);

    factory.addPetrolCar(petrolCar3);
    factory.addPetrolCar(petrolCar4);
    factory.addPetrolCar(petrolCar5);
    factory.addElectricCar(electricCar3);
    factory.addElectricCar(electricCar4);
    factory.addElectricCar(electricCar5);
    factory.addHybridCar(hybridCar3);
    factory.addHybridCar(hybridCar4);
    factory.addHybridCar(hybridCar5);
    factory.addHybridCar(hybridCar2);

    //Utilizarea clasei Template
    CarFleet<PetrolCar> petrolCarFleet;
    petrolCarFleet.addCar(petrolCar1);
    petrolCarFleet.addCar(petrolCar2);
    petrolCarFleet.addCar(petrolCar3);
    petrolCarFleet.addCar(petrolCar4);
    petrolCarFleet.addCar(petrolCar5);

    CarFleet<ElectricCar> electricCarFleet;
    electricCarFleet.addCar(electricCar1);
    electricCarFleet.addCar(electricCar2);
    electricCarFleet.addCar(electricCar3);
    electricCarFleet.addCar(electricCar4);
    electricCarFleet.addCar(electricCar5);

    CarFleet<HybridCar> hybridCarFleet;
    hybridCarFleet.addCar(hybridCar1);
    hybridCarFleet.addCar(hybridCar2);
    hybridCarFleet.addCar(hybridCar3);
    hybridCarFleet.addCar(hybridCar4);
    hybridCarFleet.addCar(hybridCar5);


    cout<<endl;
    std::cout << "Bine ai venit la " << factory.getName() << std::endl;
    std::cout << "Numarul de angajati: " << factory.getNumberOfEmployees() << std::endl;
    std::cout << "Total masini produse: " << Car::getNumberOfCarsProduced() << std::endl;
    cout<<endl;

    // Utilizarea funcției template calculateTotalValue pentru a calcula valoarea totală a flotelor de mașini
    std::cout << "Valoarea totala a flotei de masini pe benzina: " << calculateTotalValue(petrolCarFleet) << std::endl;
    std::cout << "Valoarea totala a flotei de masini electrice: " << calculateTotalValue(electricCarFleet) << std::endl;
    std::cout << "Valoarea totala a flotei de masini hibride: " << calculateTotalValue(hybridCarFleet) << std::endl;

    int optiune;
    char iesire;

    do
    {
        iesire='Y';
        cout << "\n---------------- BINE ATI VENIT LA AUTOTREASURE ----------------\n";
        cout << "1. Cumpara o masina\n";
        cout << "2. Verifica pretul de asigurare pentru o masina\n";
        cout << "3. Verifica eficienta unei masini\n";
        cout << "4. Vezi numarul de masini disponibile\n";
        cout << "5. Vezi numarul de statii de incarcare pentru masinile electrice\n";
        cout << "6. Vezi pretul actual (in medie) pentru combustibil\n";
        cout << "7. Iesire\n\n";
        cout << "Introduceti optiunea dvs.: ";
        cin >> optiune;

        switch(optiune)
        {
        case 1:
        {
            factory.vanzareMasina();
            break;
        }

        case 2:
        {
            factory.afisareCostAsigurare();
            break;
        }
        case 3:
        {
            factory.afisareEficienta();
            break;
        }
        case 4:
        {
            cout << Car::getNumberOfCarsProduced() << " masini disponibile in fabrica" << endl;
            break;
        }
        case 5:
        {
            cout << ElectricCar::getChargingStations() << " statii in apropiere de dvs" << endl;
            break;
        }
        case 6:
        {
            cout << PetrolCar::getAverageFuelPrice() << " lei / L" << endl;
            break;
        }
        case 7:
            cout << "Ai iesit din Meniu.\n";
            iesire = 'N';
            break;
        default:
            cout << "Optiune invalida. Va rugam sa alegeti o optiune valida.\n";
            break;
        }
        std::cout << "Doresti sa continui? (Y/N): ";
        std::cin >> iesire;


#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

    }
    while (iesire=='Y');

    std::cout << "La revedere!" << std::endl;


    return 0;
}
