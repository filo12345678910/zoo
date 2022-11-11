#include<iostream>
namespace zoo
{
    class Animal
    {
        int age;
        std::string gender;
    public:
        Animal(int age, std::string gender);
        void virtual toString();
    };
    class Amphibiant: Animal
    {
        std::string color_of_skin;
    public:
        Amphibiant(int age, std::string gender,std::string color_of_skin);
        void virtual toString();
    };
    class Salamander: Amphibiant
    {
        int tail_length;
        std::string color_of_dots;
    public:
        Salamander(int age, std::string gender,std::string color_of_skin,int tail_length,std::string color_of_dots);
        void toString();
    };
}
