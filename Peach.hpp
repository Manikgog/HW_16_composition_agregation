#ifndef _PEACH_HPP_
#define _PEACH_HPP_

#include "Harvest.hpp"

class Peach : public Harvest {
public:
    Peach(const std::string& name = "Peach", const std::string& color = "Red", const std::string& size = "Small", double weight = 0.1)
        : Harvest(name, color, size, weight) {}
};



#endif // !_PEACH_HPP_

