
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdint>

namespace ipp
{
    template<typename T>
    std::string print_ip(const T &ip)
    {
        using T_unsigned = std::make_unsigned<T>::type;

        std::string tmp{""};
        T_unsigned x = ip;
        unsigned k{sizeof(T)};
        unsigned sh{0};

        for (unsigned i = 0; i < k; ++i)
        {
            sh = (k - i - 1)*CHAR_BIT;
            tmp += (std::to_string(x>>sh) + ".");
            x &= ((static_cast<T_unsigned>(1)<<sh) - 1);
        }

        tmp.pop_back(); // remove last '.'

        return std::move(tmp);
    }
    //-------------------------------------


    template<> 
    std::string print_ip(const std::string &ip)
    {
        return ip;
    }
    //-------------------------------------


    template<typename T> 
    std::string print_ip(const std::vector<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        return std::move(tmp);
    }
    //-------------------------------------


    template<typename T> 
    std::string print_ip(const std::list<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        return std::move(tmp);
    }
    //-------------------------------------
}
