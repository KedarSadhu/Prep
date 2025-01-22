#include "Logger.h"

int Logger:: cnt = 0; 
Logger::Logger()
{
    cnt++;
    cout<<"New logger instance created :: "<<cnt <<endl;
}

void Logger::Log(const string &log_msg)
{
    cout<<log_msg<<endl;
}