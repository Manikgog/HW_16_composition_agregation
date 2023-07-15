#ifndef _CHERRY_TREE_HPP_
#define _CHERRY_TREE_HPP_

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include "Plants.hpp"
#include "Cherry.hpp"

class CherryTree : public Plants {
private:
    int fruitCount_; // Количество плодов на вишнёвого дереве

public:
    CherryTree(const std::string& color, const std::string& size, const std::string& name, int fruitCount)
        : Plants(color, size, name), fruitCount_(fruitCount) {}

    void printInfo() const override {
        Plants::printInfo();
        std::cout << "Fruit count: " << fruitCount_ << std::endl;
    }

    double GetRandom()
    {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen(rd());  // to seed mersenne twister.
        int randomNum = gen() % 21 + 10;
        return randomNum / 1000.0;
    }


    std::unique_ptr<Harvest> harvestFruit() override {
        --fruitCount_;
        return std::make_unique<Harvest>("Cherry", "Red", "Large", GetRandom()); // Возвращение объекта Cherry через фабричный метод
    }

    int GetFruitCount() override
    {
        return fruitCount_;
    }

};

#endif

