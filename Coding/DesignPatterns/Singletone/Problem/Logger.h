#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<string>

using namespace std;

class Logger
{
    static int cnt;
    public:
       Logger();
       void Log(const string &log_msg);
};
#endif