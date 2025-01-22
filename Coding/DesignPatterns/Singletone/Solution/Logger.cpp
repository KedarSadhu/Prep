#include "Logger.h"

int Logger:: cnt = 0; 
Logger * Logger ::pLoger =nullptr;
mutex Logger::mtx;

Logger * Logger::getLogger()
{
    if(pLoger == nullptr)
    {
        mtx.lock();
        if(pLoger ==nullptr)
        {
            pLoger = new Logger();
        }
        mtx.unlock();
    }
    return pLoger;
}


Logger::Logger()
{
    cnt++;
    cout<<"New logger instance created :: "<<cnt <<endl;
}

void Logger::Log(const string &log_msg)
{
    cout<<log_msg<<endl;
}