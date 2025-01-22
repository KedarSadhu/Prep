#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<string>
#include<thread>
#include<mutex>

using namespace std;

class Logger
{
    static int cnt;
    static Logger * pLoger;
    static mutex mtx;
    Logger();
    Logger(const Logger &){}
    Logger operator =(const Logger &){}
    
    public:
       static Logger * getLogger();   
       void Log(const string &log_msg);
};
#endif