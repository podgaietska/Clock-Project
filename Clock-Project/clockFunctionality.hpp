//
//  clockFunctionality.hpp
//  Clock-Project
//
//  Created by Mariya Podgaietska on 11.03.2023.
//

#ifndef clockFunctionality_hpp
#define clockFunctionality_hpp

#include <stdio.h>
#include <cstring>
#include <fstream>

using namespace std;

class Clock{
private:
    int second;
    int minute;
    int hour;
    
    int validate_hour(int h);
    int validate_sec_min(int t);
    
    int hms_to_sec()const;
    void sec_to_hms(int s);
    
    
    
public:
    Clock(); //default constructor. sets values of s, m and h to 0
    Clock(int s);  //cstor receives seconds and sets clock
    Clock(int h, int m, int s);
    void display()const;
    
    int get_hour()const;
    int get_minute()const;
    int get_second()const;
    
    void set_hour(int h);
    void set_minute(int m);
    void set_second(int s);
    
    void increment();
    void decrement();
    
    void add_seconds(int s);
    
    
};

#endif 
