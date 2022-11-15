#include<iostream>
#include <typeinfo>
#include <vector>
#include "zoo.h"
using namespace zoo;
using namespace std;
Animal::Animal(int age, string gender){this->age = age;this->gender = gender;}
Amphibiant::Amphibiant(int age, string gender, string color_of_skin): Animal(age, gender){this->color_of_skin = color_of_skin;}
Salamander::Salamander(int age, string gender, string color_of_skin, int tail_length, string color_of_dots): Amphibiant(age, gender, color_of_skin){this->tail_length = tail_length; this->color_of_dots = color_of_dots;}
Frog::Frog(int age, string gender, string color_of_skin, bool poisonous): Amphibiant(age, gender, color_of_skin){this->poisonous = poisonous;}

void Animal::toString()
{
    cout << "age: " << age << endl;
    cout << "gender: " << gender << endl;
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

/*void Breeder::Create()
{

}*/
int main()
{
    Salamander* cat1 = new Salamander(13, "male", "black", 23, "red");
    Salamander* cat2 = new Salamander(34, "female", "black", 3, "blue");
    Frog* cat3 = new Frog(23, "male", "red", 1);


    Zoo<Animal*> p;
    //Breeder b;
    p.Add(cat3);
    p.Add(cat2);
    p.Show();
    p.RemoveAll();


    cout << "------------" << endl;
    p.Show();
}
