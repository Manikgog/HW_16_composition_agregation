#ifndef APPLE_TREE_HPP
#define APPLE_TREE_HPP

#include <iostream>
#include <string>
#include <random>
#include <memory>
#include "Plants.hpp"
#include "Apple.hpp"

// Пример конкретной реализации класса Растения - "Яблоня"
class AppleTree : public Plants {
private:
    int fruitCount_; // Количество плодов на яблоне

public:
    AppleTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Fruit count: " << fruitCount_ << std::endl;
    }

    double GetRandom()
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        int randomNum = gen() % 11 + 20;
        return randomNum / 100.0;
    }

    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Apple", "Red", "Medium", GetRandom()); // Возвращение объекта Apple через фабричный метод
    }

    int GetFruitCount() override
    {
        return fruitCount_;
    }
};

#endif // !1

