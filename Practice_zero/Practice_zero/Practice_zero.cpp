#include <iostream>
#include "Practice0.h" 

int main(int argc, char ** argv)
{
    std::ofstream off;
    std::ifstream in;
    char* infilename, * outfilename;

    if (argc < 3)
    {
        std::cout << "Invalid arguments!";
        return 1;
    }
    infilename = argv[1];
    outfilename = argv[2];

    TVector v1, v2;
    
    in.open(infilename); 
    in >> v1 >> v2; 
    in.close(); 

    std::cout << v1; 
    std::cout << v2; 

    TVector summ  = v1 + v2; 
    TVector diff = v1 - v2;
    double mult = v1 * v2; 
    
    off.open(outfilename);
    off << summ << diff << mult;
    off.close();
    
    return 0;
}