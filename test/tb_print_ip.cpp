
#include "..\lib\print_ip.h"
#include <gtest\gtest.h>
#include <string>
#include <vector>
#include <list>
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

        EXPECT_EQ(ipp::to_string(static_cast<char>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::to_string(static_cast<char>(-1)),"255");
    EXPECT_EQ(ipp::to_string(static_cast<char>(127)),"127");
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

        EXPECT_EQ(ipp::to_string(static_cast<short>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::to_string(static_cast<unsigned short>(65535)),"255.255");
    EXPECT_EQ(ipp::to_string(static_cast<short>(32767)),"127.255");
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

        EXPECT_EQ(ipp::to_string(static_cast<int>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::to_string(4294967295),"255.255.255.255");
    EXPECT_EQ(ipp::to_string(2147483647),"127.255.255.255");
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

        EXPECT_EQ(ipp::to_string(static_cast<long long int>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::to_string(18446744073709551615),"255.255.255.255.255.255.255.255");
    EXPECT_EQ(ipp::to_string(9223372036854775807),"127.255.255.255.255.255.255.255");
}
//---------------------------------------------------------------------------------------


TEST(test_print_ip,string_test)
{
    std::string ip_gold;
    unsigned ip_term;

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

        EXPECT_EQ(ipp::to_string(ip_gold),ip_gold);
    }

    ip_gold = "255.255.255.255";
    EXPECT_EQ(ipp::to_string(ip_gold),"255.255.255.255");
    ip_gold = "127.255.255.255";
    EXPECT_EQ(ipp::to_string(ip_gold),"127.255.255.255");
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

        EXPECT_EQ(ipp::to_string(ip_vec),ip_gold);
    }

    ip_vec = {255,255,255,255};
    EXPECT_EQ(ipp::to_string(ip_vec),"255.255.255.255");
    ip_vec = {127,255,255,255};
    EXPECT_EQ(ipp::to_string(ip_vec),"127.255.255.255");
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

        EXPECT_EQ(ipp::to_string(ip_lst),ip_gold);

        ip_lst.clear();
        ip_gold = "";
    }

    ip_lst = {255,255,255,255};
    EXPECT_EQ(ipp::to_string(ip_lst),"255.255.255.255");
    ip_lst = {127,255,255,255};
    EXPECT_EQ(ipp::to_string(ip_lst),"127.255.255.255");
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
 
        EXPECT_EQ(ipp::to_string(ip_tpl),ip_gold);
    }

    EXPECT_EQ(ipp::to_string(std::make_tuple(255,255,255,255)),"255.255.255.255");
    EXPECT_EQ(ipp::to_string(std::make_tuple(127,255,255,255)),"127.255.255.255");
    EXPECT_EQ(ipp::to_string(std::make_tuple(1,2,3,4)),"1.2.3.4");
    EXPECT_EQ(ipp::to_string(std::make_tuple(10,20,30,40)),"10.20.30.40");
}
//---------------------------------------------------------------------------------------
