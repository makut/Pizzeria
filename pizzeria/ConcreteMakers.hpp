# pragma once
# include "Makers.hpp"

class HawaiiPizzaMaker : public PizzaMaker
{
public:
    void nameProduct()
    {
        name_ = "HawaiiPizza";
    }

    void addSauce()
    {
        sauce_ = tomato;
    }

    void addBase()
    {
        base_ = ham;
    }

    void addTopping()
    {
        top_ = ananas;
    }

    void addCheese()
    {
        cheese_ = mozzarella;
    }
};

class ChickenSandwichMaker : public SandwichMaker
{
public:
    void nameProduct()
    {
        name_ = "ChickenSandwich";
    }

    void addSauce()
    {
        sauce_ = cheesy;
    }

    void addBase()
    {
        base_ = chicken;
    }

    void addTopping()
    {
        top_ = olive;
    }

    void addBread()
    {
        bread_ = white;
    }
};