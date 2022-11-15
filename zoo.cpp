#include<iostream>
#include <typeinfo>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "zoo.h"
using namespace zoo;
using namespace std;
Animal::Animal(int weight, string name){this->weight = weight;this->name = name;}
Amphibiant::Amphibiant(int weight, string name, string color_of_skin): Animal(weight, name){this->color_of_skin = color_of_skin;}
Salamander::Salamander(int weight, string name, string color_of_skin, int tail_length, string color_of_dots): Amphibiant(weight, name, color_of_skin){this->tail_length = tail_length; this->color_of_dots = color_of_dots;}
Frog::Frog(int weight, string name, string color_of_skin, bool poisonous): Amphibiant(weight, name, color_of_skin){this->poisonous = poisonous;}

void Animal::toString()
{
    cout << "weight: " << weight << endl;
    cout << "name: " << name << endl;
}
void Amphibiant::toString()
{
    Animal::toString();
    cout << "color_of_skin: " << color_of_skin << endl;
}
void Salamander::toString()
{
    cout << "Salamander statistics:" << endl;
    Amphibiant::toString();
    cout << "tail_length: " << tail_length << endl;
    cout << "color_of_dots: " << color_of_dots << endl;
}
void Frog::toString()
{
    cout << "Frog statistics:" << endl;
    Amphibiant::toString();
    cout << "is_poisonous?: " << poisonous << endl;
}

Animal * Breeder::Create(int a)
{
    string color[30] = {"White", "Yellow", "Blue", "Red", "Green", "Black", "Brown", "Silver", "Purple", "Orange", "Grey", "Cyan", "Lime"};
    string name[30] = {"Adams", "Baker", "Clark", "Davis", "Evans", "Frank", "Ghosh", "Hills", "Irwin", "Jones", "Klein", "Lopez", "Mason", "Nalty", "Ochoa", "Patel", "Quinn", "Reily", "Smith", "Trott", "Usman", "Valdo", "White", "Xiang", "Yakub", "Zafar"};
    switch (a)
    {
        case 1: return new Salamander(rand()%100 + 1, name[rand()%26], color[rand()%13], rand()%20, color[rand()%13]); break;
        case 2: return new Frog(rand()%100 + 1, name[rand()%26], color[rand()%13], rand()%2); break;
    }
}
int main()
{
    srand (time(NULL));
    Zoo<Animal*> p;
    Breeder b;


    p.Add(b.Create(1));
    p.Add(b.Create(2));
    p.Show();
    p.RemoveAll();


    cout << "------------" << endl;
    p.Show();
}
