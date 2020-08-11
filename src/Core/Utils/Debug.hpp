#pragma once
#include <iostream>

namespace Debug {
    template <typename T>
    void Log(T msg);
}

template <typename T>
void Debug::Log(T msg){
    std::cout << msg << std::endl;
}