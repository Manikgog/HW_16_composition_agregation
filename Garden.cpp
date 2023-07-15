#include "Garden.hpp"

/*!
\brief конструктор от 30 до 100 объектов Plants и заполняющий ими вектор std::vector<std::unique_ptr<Plants>> Garden_;
Количество деревьев по видам заполняется случайным образом.
Количество фруктов на каждом дереве заполняется тоже случайно.
*/
Garden::Garden()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.

	int AllTress = gen() % 71 + 30;;
	int numberOfAppleTrees = gen() % 30 + 10;
	int numberOfPeachTrees = gen() % 30 + 10;
	int numberOfCherryTrees = AllTress - numberOfAppleTrees - numberOfPeachTrees;

	int fruitCount = 0;
	while (numberOfAppleTrees-- > 0)
	{
		fruitCount = gen() % 11 + 5;
		Garden_.push_back(std::make_unique<AppleTree>("Green", "Large", "Apple Tree", fruitCount));
	}

	while (numberOfPeachTrees-- > 0)
	{
		fruitCount = gen() % 16 + 10;
		Garden_.push_back(std::make_unique<PeachTree>("Green", "Medium", "Peach Tree", fruitCount));
	}

	while (numberOfCherryTrees-- > 0)
	{
		fruitCount = gen() % 51 + 10;
		Garden_.push_back(std::make_unique<CherryTree>("Dark green", "Medium", "Cherry Tree", fruitCount));
	}
}

void Garden::PrintGarden()
{
	for (const auto& el : Garden_)
	{
		el.get()->printInfo();
		std::cout << std::endl;
	}
}

/*!
\brief метод возвращающий количество элементов в векторе std::vector<std::unique_ptr<Plants>> Garden_.
Возвращает количество деревьев в саду.
\param[out] size_t количество деревьев
*/
size_t Garden::Size()
{
	return Garden_.size();
}

/*
\brief метод возвращающий ссылку на вектор умных указателей на  объекты Plants 
*/
std::vector<std::unique_ptr<Plants>>& Garden::GetGarden()
{
	return Garden_;
}

/*!
\brief метод возвращает указатель на объект класса Plants
\param[in] index индекс объекта класса Plants в векторе std::vector<std::unique_ptr<Plants>> Garden_;
\param[out] Plants* указатель на объект Plants
*/
Plants* Garden::operator[](size_t index)
{
	return Garden_.at(index).get();
}

/*!
\brief метод возвращает количество плодов в саду
*/
size_t Garden::AmountOfHarvest()
{
	size_t amount = 0;
	for (const auto& el : Garden_)
	{
		amount += el.get()->GetFruitCount();
	}
	return amount;
}