#ifndef CAR_FLEET_H
#define CAR_FLEET_H

#include <vector>
#include <memory>

template <typename T>
class CarFleet
{
private:
    std::vector<std::shared_ptr<T>> cars;
public:
    void addCar(const std::shared_ptr<T>& car)
    {
        cars.push_back(car);
    }

    void displayFleet() const
    {
        for (const auto& car : cars)
        {
            std::cout << *car << std::endl;
        }
    }

    double getTotalValue() const
    {
        double total = 0;
        for (const auto& car : cars)
        {
            total += car->getPrice();
        }
        return total;
    }
};

#endif
