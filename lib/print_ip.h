
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdint>

namespace ipp
{
    template<typename T>
    void print_ip(const T &ip)
    {
        std::string tmp{""};
        std::make_unsigned<T>::type x = ip;
        unsigned k{sizeof(T)};
        unsigned sh{0};

        for (unsigned i = 0; i < k; ++i)
        {
            sh = (k - i - 1)*CHAR_BIT;
            tmp += (std::to_string(x>>sh) + ".");
            x &= ((1<<sh) - 1);
        }

        tmp.pop_back(); // remove last '.'

        print_ip(tmp);
    }
    //-------------------------------------


    template<> 
    void print_ip(const std::string &ip)
    {
        std::cout << ip << std::endl;
    }
    //-------------------------------------


    template<typename T> 
    void print_ip(const std::vector<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        print_ip(tmp);
    }
    //-------------------------------------


    template<typename T> 
    void print_ip(const std::list<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        print_ip(tmp);
    }
    //-------------------------------------
}
