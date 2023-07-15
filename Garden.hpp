#ifndef _GARDEN_HPP_
#define _GARDEN_HPP_

#include <vector>
#include <memory>
#include <random>

#include "Plants.hpp"
#include "AppleTree.hpp"
#include "PeachTree.hpp"
#include "CherryTree.hpp"

class Garden
{
private:
	std::vector<std::unique_ptr<Plants>> Garden_;

public:
	Garden();

	void PrintGarden();

	size_t Size();
	

	std::vector<std::unique_ptr<Plants>>& GetGarden();
	
	Plants* operator[](size_t index);
	
	size_t AmountOfHarvest();
};


#endif // !_GARDEN_HPP_
