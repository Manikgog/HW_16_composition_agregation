#ifndef APPLE_HPP
#define APPLE_HPP

#include <string>

#include "Harvest.hpp"

// Пример конкретной реализации класса Плоды - "Яблоко"
class Apple : public Harvest {
public:
    Apple(const std::string& name = "Apple", const std::string& color = "Red", const std::string& size = "Small", double weight = 0.1)
        : Harvest(name, color, size, weight) {}
};

#endif
