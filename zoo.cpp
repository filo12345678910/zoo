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
Fish::Fish(int weight, string name, bool is_saltwater, int fins): Animal(weight, name){this->is_saltwater = is_saltwater; this->fins = fins;}
Mammal::Mammal(int weight, string name, string color_of_fur): Animal(weight, name){this->color_of_fur = color_of_fur;}
Bird::Bird(int weight, string name, int wings): Animal(weight, name){this->wings = wings;}
Reptile::Reptile(int weight, string name, string color_of_scales): Animal(weight, name){this->color_of_scales = color_of_scales;}

Salamander::Salamander(int weight, string name, string color_of_skin, int tail_length, string color_of_dots): Amphibiant(weight, name, color_of_skin){this->tail_length = tail_length; this->color_of_dots = color_of_dots;}
Frog::Frog(int weight, string name, string color_of_skin, bool poisonous): Amphibiant(weight, name, color_of_skin){this->poisonous = poisonous;}
Shark::Shark(int weight, string name, bool is_saltwater, int fins, int teeth): Fish(weight, name, is_saltwater, fins){this->teeth = teeth;}
Whale::Whale(int weight, string name, bool is_saltwater, int fins, int siz): Fish(weight, name, is_saltwater, fins){this->siz = siz;}
Cat::Cat(int weight, std::string name, std::string color_of_fur, int number_of_whiskers): Mammal(weight, name, color_of_fur){this->number_of_whiskers = number_of_whiskers;}
Monkey::Monkey(int weight, std::string name, std::string color_of_fur, int length_of_arms, int length_of_jump): Mammal(weight, name, color_of_fur){this->length_of_arms = length_of_arms; this->length_of_jump = length_of_jump;}
Toucan::Toucan(int weight, string name, int wings, int beek): Bird(weight, name, wings){this->beek = beek;}
Ostrich::Ostrich(int weight, string name, int wings, int speed): Bird(weight, name, wings){this->speed = speed;}
Snake::Snake(int weight, std::string name, std::string color_of_scales, bool venomous, int length): Reptile(weight, name, color_of_scales){this->venomous = venomous; this->length = length;}
Turtle::Turtle(int weight, std::string name, std::string color_of_scales, std::string pattern): Reptile(weight, name, color_of_scales){this->pattern = pattern;}

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
void Fish::toString()
{
    Animal::toString();
    cout << "is_it_saltwater: " << is_saltwater << endl;
    cout << "number_of_fins: " << fins << endl;
}
void Mammal::toString()
{
    Animal::toString();
    cout << "color_of_fur: " << color_of_fur << endl;
}
void Bird::toString()
{
    Animal::toString();
    cout << "length_of_wings: " << wings << endl;
}
void Reptile::toString()
{
    Animal::toString();
    cout << "color_of_scales: " << color_of_scales << endl;
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
void Shark::toString()
{
    cout << "Shark statistics:" << endl;
    Fish::toString();
    cout << "how_many_teeth " << teeth << endl;
}
void Whale::toString()
{
    cout << "Whale statistics:" << endl;
    Fish::toString();
    cout << "how_big:" << siz << endl;
}
void Cat::toString()
{
    cout << "Cat statistics:" << endl;
    Mammal::toString();
    cout << "number_of_whiskers:" << number_of_whiskers << endl;
}
void Monkey::toString()
{
    cout << "Monkey statistics:" << endl;
    Mammal::toString();
    cout << "length_of_arms:" << length_of_arms << endl;
    cout << "length_of_jump:" << length_of_jump << endl;
}
void Toucan::toString()
{
    cout << "Toucan statistics:" << endl;
    Bird::toString();
    cout << "size_of_beek:" << beek << endl;
}
void Ostrich::toString()
{
    cout << "Ostrich statistics:" << endl;
    Bird::toString();
    cout << "speed:" << speed << endl;
}
void Snake::toString()
{
    cout << "Snake statistics:" << endl;
    Reptile::toString();
    cout << "is_it_venomous:" << venomous << endl;
    cout << "length:" << length << endl;
}
void Turtle::toString()
{
    cout << "Turtle statistics:" << endl;
    Reptile::toString();
    cout << "what_pattern_is_shell:" << pattern << endl;
}

Animal * Breeder::Create(int a)
{
    string color[30] = {"White", "Yellow", "Blue", "Red", "Green", "Black", "Brown", "Silver", "Purple", "Orange", "Grey", "Cyan", "Lime"};
    string pattern[4] = {"Stripes", "Circles", "Waves", "Curvy"};
    string name[30] = {"Adams", "Baker", "Clark", "Davis", "Evans", "Frank", "Ghosh", "Hills", "Irwin", "Jones", "Klein", "Lopez", "Mason", "Nalty", "Ochoa", "Patel", "Quinn", "Reily", "Smith", "Trott", "Usman", "Valdo", "White", "Xiang", "Yakub", "Zafar"};
    switch (a)
    {
        case 1: return new Salamander(rand()%100 + 1, name[rand()%26], color[rand()%13], rand()%20, color[rand()%13]); break;
        case 2: return new Frog(rand()%100 + 1, name[rand()%26], color[rand()%13], rand()%2); break;
        case 3: return new Shark(rand()%100 + 1, name[rand()%26], rand()%2, rand()%7+1, rand()%31+1); break;
        case 4: return new Whale(rand()%100 + 1, name[rand()%26], rand()%2, rand()%7+1, rand()%130+1); break;
        case 5: return new Cat(rand()%100 + 1, name[rand()%26], color[rand()%13], (rand()%4+1)*2); break;
        case 6: return new Monkey(rand()%100 + 1, name[rand()%26], color[rand()%13], rand()%100+1, rand()%50+1); break;
        case 7: return new Toucan(rand()%100 + 1, name[rand()%26], rand()%150+1, rand()%80+1); break;
        case 8: return new Ostrich(rand()%100 + 1, name[rand()%26], rand()%150+1, rand()%150+40); break;
        case 9: return new Snake(rand()%100 + 1, name[rand()%26], color[rand()%13], rand()%2, rand()%200+40); break;
        case 10: return new Turtle(rand()%100 + 1, name[rand()%26], color[rand()%13], pattern[rand()%4]); break;
    }
}
Animal * Breeder::Breed(Animal* a, Animal* b)
{
    if(rand()%2 == 0)
    {
        swap(a, b);
    }
    Animal*c = a;
    c->name = a->name.substr(rand()%2, a->name.size()/2) + char(int('a') + rand()%26) + b->name.substr(b->name.size()/2, b->name.size()-1);
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
    int abara;
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
            case 2:cout << "Animals removed!" << endl;p.RemoveAll();break;
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
                p+=b.Create(rand()%10+1);
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
