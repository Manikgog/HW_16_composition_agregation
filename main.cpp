/*!
Наследование - Композиция, Агрегация
Задание на композицию
Для реализованных семейств классов Растений и Плодов создать классы - контейнеры:
Локация:
при создании создаёт внутри себя от 30 до 100 различных объёктов
наследников растений хранящихся в одной коллекции;
позволяет пользователю узнавать скольно ростений есть на локации
позволяет пользователю перебрать все растения для сбора с них плодов
Рюкзак:
позволяет хранить в себе любых наследников класса Плоды
позволяет пользователю перебрать своё содержимое
при необходимости должен быть механизм изъятия любого плода из рюкзака
В функции мэйн продемонстрируйте возможность сбора пользователем всех плодов со всех
деревьев с локации и последующую работу с рюкзаком в виде сообщения об общем
количестве плодов и их суммарном весе. Показать что если выкинуть из рюкзака все плоды
какого либо типа результат предыдущего алгоритма изменяется.
``` задание сдаётся в виде архива проекта либо ссылки на репозиторий
*/
#include <iostream>
#include "AppleTree.hpp"
#include "PeachTree.hpp"
#include "CherryTree.hpp"
#include "Garden.hpp"
#include "Backpack.hpp"


int main() {
    Garden garden;

    garden.PrintGarden();
    std::cout << "In the garden " << garden.Size() << " trees, and " << garden.AmountOfHarvest() << " harvests.\n";
    Backpack backpack;
    for (size_t i = 0; i < garden.Size(); i++)
    {
        while (garden[i]->GetFruitCount() > 0)
        {
            backpack.Push_back(*(garden[i]->harvestFruit())); //> добавление объекта класса Harvest в объект класса Backpack (рюкзак)
        }
    }
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    
    Harvest apple(*(backpack.GetFruit("Apple").release())); //> извлечение яблока из рюкзака
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    Harvest peach(*(backpack.GetFruit("Peach Prince").release())); //> извледение персика из рюкзака
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";
    Harvest cherry(*(backpack.GetFruit("Cherry").release()));       //> извелечение черешни из рюкзака
    std::cout << "In the backpack " << backpack.Size() << " harvests." << " Total weight - " << backpack.GetWeight() << " kg.\n";


    return 0;
}


