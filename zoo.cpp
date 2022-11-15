#include<iostream>
#include <typeinfo>
#include <vector>
#include <string>

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
Animal * Breeder::Breed(Animal* a, Animal* b)
{
    cout << "BREEDING:" << endl;
    a->toString();
    b->toString();
    Animal*c = this->Create(1);
    c->name = a->name.substr(0, a->name.size()/2) + b->name.substr(b->name.size()/2, b->name.size()-1);
    cout << c->name << endl;
    c->weight = (a->weight + b->weight + rand()%10 - 5)/2;
    return c;
}
int main()
{
    srand (time(NULL));
    Zoo<Animal*> p;
    Breeder b;

    int num;
    int an;
    float pBreed;
    float pExtinct;
    while(1)
    {
        bool rr = false;
        bool bb = false;
        cout << "-----------" << endl;
        cout << "Welcome to the zoo! What do you want to do?" << endl;
        cout << "Press 1 to run breed method, filling zoo with 100 animals" << endl;
        cout << "Press 2 to clear the zoo" << endl;
        cout << "Press 3 to add animals to zoo" << endl;
        cout << "Press 4 to show zoo" << endl;
        cout << "-----------" << endl;

        cin >> num;

        switch (num)
        {
            case 1:bb = true;break;
            case 2:p.RemoveAll();break;
            case 3:cout << "How many animals to add?" << endl; cin >> an; rr = true;break;
            case 4:p.Show();break;
            default:cout << "Please enter correct number!" << endl;break;
        }
        if (rr == true)
        {
            while ((an <= 0) or (an > 1000))
            {
                cout << "Invalid ammount" << endl;
                cin >> an;
            }
            for(int i = 0; i < an; i++)
            {
                p+=b.Create(rand()%2+1);
            }
        }
        if (bb == true)
        {
            if (p.Animals.size() < 2)
            {
                cout << "Need at least 2 animals in the zoo" << endl;
            }
            else
            {
                cout << "Enter probability for crossover" << endl;
                cin >> pBreed;
                while ((pBreed <= 0) or (pBreed > 1))
                {
                    cout << "Invalid probability" << endl;
                    cin >> pBreed;
                }
                cout << "Enter probability for Extinction" << endl;
                cin >> pExtinct;
                while ((pExtinct <= 0) or (pExtinct > 1))
                {
                    cout << "Invalid probability" << endl;
                    cin >> pExtinct;
                }
                while(p.Animals.size() < 100)
                {
                    int j = -1;
                    int g = p.Animals.size();
                    for (int i = 0; i < g; i++);
                    {
                        if (p.Animals.size() < 2)
                        {
                            cout << "All animals died!" << endl;
                            p.RemoveAll();
                            break;
                        }
                        j++;
                        if(rand()%100 <= pBreed*100)
                        {
                            p+=b.Breed(p.Animals[j], p.Animals[rand()%p.Animals.size()]);
                        }
                        if(rand()%100 <= pExtinct*100)
                        {
                            p-=j;
                        }
                        p.Show();
                    }
                }
            }
        }
    }
}
