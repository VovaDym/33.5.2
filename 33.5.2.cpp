#include <iostream>
#include <ctime>
#include <string>
#include <exception>

int getRandomPos(int max)
{
    return (std::rand() % max);
}

int main()
{
    std::srand(std::time(nullptr));

    const int pondSize = 9;
    std::string pond[pondSize];
    for (auto& el : pond)
    {
        el = "empty";
    }
    int pos = getRandomPos(pondSize);
    pond[pos] = "fish";

    const int amountBoots = 3;
    for (int i = 0; i < amountBoots; ++i)
    {
        while (pond[pos] != "empty")
        {
            pos = getRandomPos(pondSize);
        }   
        pond[pos] = "boot";
    }

    int attemptsCount = 0;
    try
    {
        while (true)
        {
            int answer;
            do
            {
                std::cout << "Enter sector [1.." << pondSize << ") to catch fish: ";
                std::cin >> answer;
                answer -= 1;
            } while (answer < 0 || answer >= pondSize);

            ++attemptsCount;

            if (pond[answer] == "fish")
            {
                std::cout << "Number of your attempts was " << attemptsCount << std::endl;
                throw std::runtime_error("You catch a fish");
                
            }   
            else if (pond[answer] == "boot")
            {
                throw std::runtime_error("You catch a boot");
            }      
        }
    }
    catch (std::runtime_error err)
    {
        std::cout << err.what() << std::endl;
    }
}
