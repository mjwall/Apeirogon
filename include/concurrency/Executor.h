#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <iostream>

#include "ReturnType.h"
class Executor
{
public:

    virtual ReturnType *run() = 0;
};

#endif