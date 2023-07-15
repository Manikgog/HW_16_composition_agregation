#ifndef _CHERRY_HPP_
#define _CHERRY_HPP_

#include "Harvest.hpp"

class Cherry : public Harvest {
public:
    Cherry(const std::string& name = "Cherry", const std::string& color = "Red", const std::string& size = "Small", double weight = 0.03)
        : Harvest("Cherry", color, size, weight) {}
};



#endif 
