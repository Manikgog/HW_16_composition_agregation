#ifndef HARVESR_HPP
#define HARVESR_HPP

#include <string>
#include <iostream>

// Ѕазовый класс ѕлоды
class Harvest {
public:
    Harvest() : name_(""), color_(""), size_(""), weight_(0) {}
    Harvest(const std::string& name, const std::string& color, const std::string& size, double weight)
        : name_(name), color_(color), size_(size), weight_(weight) {}

    virtual ~Harvest() {}

    virtual void printInfo() const {
        std::cout << "Name: " << name_ << std::endl;
        std::cout << "Color: " << color_ << std::endl;
        std::cout << "Size: " << size_ << std::endl;
        std::cout << "Weight: " << weight_ << std::endl;
    }

    std::string getName() const
    {
        return name_;
    };

    std::string getColor() const
    {
        return color_;
    }

    std::string getSize() const
    {
        return size_;
    }

    double getWeight() const
    {
        return weight_;
    }



private:
    std::string name_;
    std::string color_;
    std::string size_;
    double weight_;

};



#endif // !HARVESR_HPP
