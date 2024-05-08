#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Practice1cpp.h"

#define l 255

int main(int argc, char** argv)
{
    char firstname[l];
    char lastname[l];
    FilmLib lib;
    char* infilename;
    if (argc < 2)
    {
        std::cout << "incorrect arguments!";
        return 0;
    }
    infilename = argv[1];

    readFilmDataFromFile(infilename, &lib); 


    std::cout << "Enter director's first name: ";
    std::cin >> firstname;
    std::cout << "Enter director's last name: ";
    std::cin >> lastname;

    std::cout << "\nfilms by " << firstname << " " << lastname << ":\n";
    printFilmsByDirector(&lib, firstname, lastname);


    freefilmlibrary(&lib);

    return 0;
}