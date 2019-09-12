
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <cstdint>
#include <climits>
#include <functional>

namespace ipp
{
    template<typename T>
    std::string to_string(const T &ip)
    {
        using UT = typename std::make_unsigned<T>::type;

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

        return tmp;
    }
    //-------------------------------------


    template<typename T> 
    std::string to_string(const std::vector<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        return tmp;
    }
    //-------------------------------------


    template<typename T> 
    std::string to_string(const std::list<T> &ip)
    {
        std::string tmp{""};

        for (const auto &x : ip)
            tmp += (std::to_string(x) + ".");
            
        tmp.pop_back(); // remove last '.'

        return tmp;
    }
    //-------------------------------------


    template<std::size_t I,typename F,typename... A>
    struct foreach
    {
        static void next(F& f,const std::tuple<A...>& t)
        {
            const std::size_t i = sizeof...(A) - I; 
            f.operator()( std::get<i>(t) );
            foreach<I-1,F,A...>::next(f,t);
        }
    };
    //-------------------------------------


    template<typename F,typename... A>
    struct foreach<0,F,A...>
    {
        static void next(F&,const std::tuple<A...>&){}
    };
    //-------------------------------------


    template<typename F,typename... A>
    void foreach_tuple(F &f,const std::tuple<A...> &t)
    {
        foreach<sizeof...(A),F,A...>::next(f,t);
    }
    //-------------------------------------


    template<typename... A>
    std::string to_string(const std::tuple<A...> &ip)
    {
        std::string tmp{""};

        foreach_tuple([&tmp](const auto& x){tmp += std::to_string(x) + ".";},ip);

        tmp.pop_back();

        return tmp;
    }
    //-------------------------------------


    template<typename... A>
    void print_ip(const std::tuple<A...>& ip)
    {
        std::cout << to_string(ip) << std::endl;
    }
    //-------------------------------------


    template<typename T>
    void print_ip(const T& ip)
    {
        std::cout << to_string(ip) << std::endl;
    }
    //-------------------------------------


    template<> 
    void print_ip(const std::string &ip)
    {
        std::cout << ip << std::endl;
    }
    //-------------------------------------
}
