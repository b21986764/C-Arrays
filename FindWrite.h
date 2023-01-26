//
//  FindWrite.h
//  C++Assignment1
//  Created by Sertaç Güler on 24.10.2022.

#ifndef FindWrite_h
#define FindWrite_h
//include necessary file and string files
#include <fstream>
#include <string>
using namespace std;
class FindWrite{
    public:
    //Constructor and Destructor
    FindWrite();
    virtual ~FindWrite();
    void set(string str);
    //Findwrite function to finding the position and writing to file
    void findwrite(int** mapptr, int** keyptr, int keylen, int m, int n);
    int findvalue(int** mapptr, int** keyptr,int keylen , int& i, int& j);
    
};

#endif /* FindWrite_h */
