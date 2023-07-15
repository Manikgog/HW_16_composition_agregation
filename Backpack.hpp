#ifndef _BACK_PACK_HPP_
#define _BACK_PACK_HPP_

#include <vector>
#include <memory>

#include "Harvest.hpp"

class Backpack
{
private:
	std::vector<std::unique_ptr<Harvest>> backpack_;

public:
	Backpack(){}

	void Push_back(const Harvest& harvest)
	{
		backpack_.push_back(std::make_unique<Harvest>(harvest));
	}

	size_t Size()
	{
		return backpack_.size();
	}

	std::unique_ptr<Harvest> GetFruit(const std::string& fruit)
	{
		if (this->Size() == 0)
		{
			std::cout << "Backpack is empty.\n";
			return std::make_unique<Harvest>();
		}
		for (size_t i = 0; i < this->Size(); i++)
		{
			if (backpack_.at(i)->getName() == fruit)
			{
				Harvest* apple = backpack_.at(i).release();
				backpack_.erase(backpack_.begin() + i);
				return std::make_unique<Harvest>(*apple);
			}
		}
		std::cout << "There are no " << fruit << " in the backpack.\n";
		return std::make_unique<Harvest>();
	}

	double GetWeight()
	{
		double weight = 0;
		for (const auto& el : backpack_)
		{
			weight += el.get()->getWeight();
		}
		return weight;
	}

};


#endif // !_BACK_PACK_HPP_
