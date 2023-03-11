//
//  clockFunctionality.cpp
//  Clock-Project
//
//  Created by Mariya Podgaietska on 11.03.2023.
//

#include "clockFunctionality.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;


Clock::Clock(int s){
    sec_to_hms(s);
    
    hour = validate_hour(hour);
    minute = validate_sec_min(minute);
    second = validate_sec_min(second);
}

Clock::Clock(int h, int m, int s){
    hour = validate_hour(h);
    minute = validate_sec_min(m);
    second = validate_sec_min(s);
    
}

Clock::Clock(): hour(0), minute(0), second(0){}

void Clock::display()const{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
//getters
int Clock::get_hour()const{
    return hour;
}

int Clock::get_minute()const{
    return minute;
}

int Clock::get_second()const{
    return second;
}
//setters
void Clock::set_hour(int h){
    if (validate_hour(h) != 0 || h == 0)
        hour = h;
        
}

void Clock::set_minute(int m){
    if (validate_sec_min(m) != 0 || m == 0)
        minute = m;
}

void Clock::set_second(int s){
    if (validate_sec_min(s) != 0 || s == 0)
        second = s;
}
//implementor functions
void Clock::increment(){
    int s = hms_to_sec();
    s++;
    sec_to_hms(s);
    
    hour = validate_hour(hour);
    minute = validate_sec_min(minute);
    second = validate_sec_min(second);
}

void Clock::decrement(){
    second -= 1;
    
    if (validate_sec_min(second) == 0 && second != 0){
        second = 59;
        minute -= 1;
    }
    
    if (validate_sec_min(minute) == 0 && minute !=0 ){
        minute = 59;
        hour -= 1;
    }
    
    if (validate_hour(hour) == 0 && hour != 0){
        hour = 23;
    }
    
}

void Clock::add_seconds(int s){
    if (s>0){
        int current_s = hms_to_sec();
        s += current_s;
        sec_to_hms(s);
        }

    hour = validate_hour(hour);
    minute = validate_sec_min(minute);
    second = validate_sec_min(second);
}
//validation
int Clock::validate_hour(int h){
    if (h<=0 || h>=24)
        return 0;
    else
        return h;
}

int Clock::validate_sec_min(int t){
    if (t<=0 || t>=60)
        return 0;
    else
        return t;
}

int Clock::hms_to_sec()const{
    int s;
    s = (hour*3600) + (minute*60) + second;
    return s;
}

void Clock::sec_to_hms(int s){
    if (s<0){
        hour = 0;
        minute = 0;
        second = 0;
    }
    else
        hour = s/3600;
        minute = (s - hour*3600) / 60;
        second = s - (hour*3600 + minute*60);
}
