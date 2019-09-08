
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdint>

namespace ipp
{
    template<typename T>
    void print_ip(const T& ip)
    {
        std::cout << to_string(ip) << std::endl;
    }
    //-------------------------------------

    template<typename T>
    auto to_string(const T &ip)
    {
        using UT = std::make_unsigned<T>::type;

        std::string tmp{""};
        UT x = ip;
        unsigned k{sizeof(T)};
        unsigned sh{0};

        for (unsigned i = 0; i < k; ++i)
        {
            sh = (k - i - 1)*CHAR_BIT;
            tmp += (std::to_string(x>>sh) + ".");
            x &= ((static_cast<UT>(1)<<sh) - 1);
        }

        tmp.pop_back(); // remove last '.'

        return std::move(tmp);
    }
    //-------------------------------------

    template<> 
    auto to_string(const std::string &ip)
    {
        return ip;
    }
    //-------------------------------------

    template<typename T> 
    auto to_string(const std::vector<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        return std::move(tmp);
    }
    //-------------------------------------


    template<typename T> 
    auto to_string(const std::list<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        return std::move(tmp);
    }
    //-------------------------------------

    template<typename T>
    auto to_string(const std::tuple<T,T,T,T> &ip)
    {
        std::string tmp{""};

        tmp =         std::to_string(std::get<0>(ip)) 
              + "." + std::to_string(std::get<1>(ip)) 
              + "." + std::to_string(std::get<2>(ip)) 
              + "." + std::to_string(std::get<3>(ip));

        return std::move(tmp);
    }
}
