
#include "../lib/print_ip.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <random>

static const unsigned N{1000};

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<unsigned> dis_ip(0,255);

TEST(test_print_ip,char_test)
{

    std::string ip_gold;
    unsigned char ip_num;

    for (unsigned i = 0; i < N; ++i)
    {
        ip_num = dis_ip(gen);
        ip_gold = std::to_string(ip_num);

        EXPECT_EQ(ipp::tostr(static_cast<char>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::tostr(static_cast<char>(-1)),"255");
    EXPECT_EQ(ipp::tostr(static_cast<char>(127)),"127");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,short_test)
{

    std::string ip_gold;
    unsigned short ip_num;
    unsigned short ip_term;

    for (unsigned i = 0; i < N; ++i)
    {
        ip_term = dis_ip(gen);
        ip_gold = std::to_string(ip_term) + ".";
        ip_num = ip_term<<8;

        ip_term = dis_ip(gen);
        ip_gold += std::to_string(ip_term);
        ip_num += ip_term;

        EXPECT_EQ(ipp::tostr(static_cast<short>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::tostr(static_cast<unsigned short>(65535)),"255.255");
    EXPECT_EQ(ipp::tostr(static_cast<short>(32767)),"127.255");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,int_test)
{

    std::string ip_gold;
    unsigned ip_num;
    unsigned ip_term;

    for (unsigned i = 0; i < N; ++i)
    {
        ip_term = dis_ip(gen);
        ip_gold = std::to_string(ip_term) + ".";
        ip_num = ip_term<<24;

        for (unsigned j = 1; j < 4; ++j)
        {
            ip_term = dis_ip(gen);
            ip_gold += std::to_string(ip_term) + ".";
            ip_num += ip_term<<(8*(3 - j));
        }

        ip_gold.pop_back();  // remove last '.'

        EXPECT_EQ(ipp::tostr(static_cast<int>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::tostr(4294967295),"255.255.255.255");
    EXPECT_EQ(ipp::tostr(2147483647),"127.255.255.255");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,long_test)
{
    std::string ip_gold;
    long long unsigned ip_num;
    long long unsigned ip_term;

    for (unsigned i = 0; i < N; ++i)
    {
        ip_term = dis_ip(gen);
        ip_gold = std::to_string(ip_term) + ".";
        ip_num = ip_term<<56;

        for (unsigned j = 1; j < 8; ++j)
        {
            ip_term = dis_ip(gen);
            ip_gold += std::to_string(ip_term) + ".";
            ip_num += ip_term<<(8*(7 - j));
        }

        ip_gold.pop_back();  // remove last '.'

        EXPECT_EQ(ipp::tostr(static_cast<long long int>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::tostr(18446744073709551613U),"255.255.255.255.255.255.255.253");
    EXPECT_EQ(ipp::tostr(9223372036854775807),"127.255.255.255.255.255.255.255");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,string_test)
{
    std::ostringstream local_cout;
    auto cout_buff = std::cout.rdbuf();
    std::cout.rdbuf(local_cout.rdbuf());

    std::string ip_gold;
    unsigned ip_term;
    unsigned ip_pos_begin;

    for (unsigned i = 0; i < N; ++i)
    {
        ip_term = dis_ip(gen);
        ip_gold = std::to_string(ip_term) + ".";

        for (unsigned j = 1; j < 4; ++j)
        {
            ip_term = dis_ip(gen);
            ip_gold += std::to_string(ip_term) + ".";
        }

        ip_gold.pop_back();  // remove last '.'

        ipp::print_ip(ip_gold);

        ip_pos_begin = local_cout.str().length() - ip_gold.length() - 1;
        EXPECT_EQ(local_cout.str().substr(ip_pos_begin,ip_gold.length()),ip_gold);
    }

    ip_gold = "255.255.255.255";
    ipp::print_ip(ip_gold);
    ip_pos_begin = local_cout.str().length() - ip_gold.length() - 1;
    EXPECT_EQ(local_cout.str().substr(ip_pos_begin,ip_gold.length()),ip_gold);

    ip_gold = "127.255.255.255";
    ipp::print_ip(ip_gold);
    ip_pos_begin = local_cout.str().length() - ip_gold.length() - 1;
    EXPECT_EQ(local_cout.str().substr(ip_pos_begin,ip_gold.length()),ip_gold);

    std::cout.rdbuf(cout_buff);
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,vector_test)
{

    std::string ip_gold;
    std::vector<int> ip_vec(4);

    for (unsigned i = 0; i < N; ++i)
    {
        ip_gold = "";

        for (unsigned j = 0; j < 4; ++j)
        {
            ip_vec[j] = dis_ip(gen);
            ip_gold += std::to_string(ip_vec.at(j)) + ".";
        }
        
        ip_gold.pop_back();  // remove last '.'

        EXPECT_EQ(ipp::tostr(ip_vec),ip_gold);
    }

    ip_vec = {255,255,255,255};
    EXPECT_EQ(ipp::tostr(ip_vec),"255.255.255.255");
    ip_vec = {127,255,255,255};
    EXPECT_EQ(ipp::tostr(ip_vec),"127.255.255.255");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,list_test)
{

    std::string ip_gold{""};
    std::list<int> ip_lst;

    for (unsigned i = 0; i < N; ++i)
    {
        for (unsigned j = 0; j < 4; ++j)
        {
            ip_lst.emplace_back(dis_ip(gen));
            ip_gold += std::to_string(ip_lst.back()) + ".";
        }
        
        ip_gold.pop_back();  // remove last '.'

        EXPECT_EQ(ipp::tostr(ip_lst),ip_gold);

        ip_lst.clear();
        ip_gold = "";
    }

    ip_lst = {255,255,255,255};
    EXPECT_EQ(ipp::tostr(ip_lst),"255.255.255.255");
    ip_lst = {127,255,255,255};
    EXPECT_EQ(ipp::tostr(ip_lst),"127.255.255.255");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,tuple_test)
{

    std::string ip_gold{""};
    std::tuple<int,int,int,int> ip_tpl;

    for (unsigned i = 0; i < N; ++i)
    {
        ip_tpl = std::make_tuple(dis_ip(gen),dis_ip(gen),dis_ip(gen),dis_ip(gen));
        ip_gold =         std::to_string(std::get<0>(ip_tpl)) 
                  + "." + std::to_string(std::get<1>(ip_tpl)) 
                  + "." + std::to_string(std::get<2>(ip_tpl)) 
                  + "." + std::to_string(std::get<3>(ip_tpl)) ;
 
        EXPECT_EQ(ipp::tostr(ip_tpl),ip_gold);
    }

    EXPECT_EQ(ipp::tostr(std::make_tuple(0)),"0");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1)),"0.1");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2)),"0.1.2");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3)),"0.1.2.3");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3,4)),"0.1.2.3.4");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3,4,5)),"0.1.2.3.4.5");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3,4,5,6)),"0.1.2.3.4.5.6");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3,4,5,6,7)),"0.1.2.3.4.5.6.7");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3,4,5,6,7,8)),"0.1.2.3.4.5.6.7.8");
    EXPECT_EQ(ipp::tostr(std::make_tuple(0,1,2,3,4,5,6,7,8,9)),"0.1.2.3.4.5.6.7.8.9");
}
//---------------------------------------------------------------------------------------
