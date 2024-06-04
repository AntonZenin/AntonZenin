#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Practice1cpp.cpp"

#define l 255

int main(int argc, char** argv)
{
    int choice = 0;
    director director;
    filmlib lib;
    filmlib* newlib;
    char* infilename;
    if (argc < 2)
    {
        std::cout << "incorrect arguments!" << std::endl;
        return 0;
    }
    infilename = argv[1];

    readfilmdatafromfile(infilename, &lib);

    do {
        std::cout << "\ninput choice: 0 - show full library, 1 - search director, 2 - exit\n";
        std::cin >> choice;
        switch (choice) {
        case 0:
            printfilmlibrary(&lib);
            break;
        case 1:
            std::cout << "enter director's first name and last name separated by a space: ";
            director.directorfirstname = new char[l];
            director.directorlastname = new char[l];
            std::cin >> director.directorfirstname;
            std::cin >> director.directorlastname;


            newlib = printfilmsbydirector(&lib, director);
            printfilmlibrary(newlib);
            freefilmlibrary(newlib);
            break;
        case 2:
            break;

        default:
            std::cout << "wrong choice\n";
        }
    } while (choice != 2);

    freefilmlibrary(&lib);

    return 0;
}