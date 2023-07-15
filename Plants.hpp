#ifndef PLANTS_HPP
#define PLANTS_HPP

#include <string>
#include <iostream>
#include "Harvest.hpp"

// Базовый класс Растения
class Plants {
public:
    Plants(const std::string& name, const std::string& size, const std::string& color)
        : color_(name), size_(size), name_(color) {}

    virtual ~Plants() {}

    virtual void printInfo() const {
        std::cout << "Name: " << name_ << std::endl;
        std::cout << "Color: " << color_ << std::endl;
        std::cout << "Size: " << size_ << std::endl;
    }

    virtual std::unique_ptr<Harvest> harvestFruit() = 0; // Возвращение объекта плода через фабричный метод

    virtual int GetFruitCount() = 0;

    std::string GetName()
    {
        return name_;
    }

    std::string GetSize()
    {
        return size_;
    }

    std::string GetColor()
    {
        return color_;
    }



private:
    std::string name_;
    std::string size_;
    std::string color_;



};



#endif 
