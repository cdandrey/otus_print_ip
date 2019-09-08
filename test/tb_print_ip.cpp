
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

        EXPECT_EQ(ipp::print_ip(static_cast<char>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::print_ip(static_cast<char>(-1)),"255");
    EXPECT_EQ(ipp::print_ip(static_cast<char>(127)),"127");
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

        EXPECT_EQ(ipp::print_ip(static_cast<short>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::print_ip(static_cast<unsigned short>(65535)),"255.255");
    EXPECT_EQ(ipp::print_ip(static_cast<short>(32767)),"127.255");
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

        EXPECT_EQ(ipp::print_ip(static_cast<int>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::print_ip(4294967295),"255.255.255.255");
    EXPECT_EQ(ipp::print_ip(2147483647),"127.255.255.255");
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

        EXPECT_EQ(ipp::print_ip(static_cast<long long int>(ip_num)),ip_gold);
    }

    EXPECT_EQ(ipp::print_ip(18446744073709551615),"255.255.255.255.255.255.255.255");
    EXPECT_EQ(ipp::print_ip(9223372036854775807),"127.255.255.255.255.255.255.255");
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

        EXPECT_EQ(ipp::print_ip(ip_gold),ip_gold);
    }

    ip_gold = "255.255.255.255";
    EXPECT_EQ(ipp::print_ip(ip_gold),"255.255.255.255");
    ip_gold = "127.255.255.255";
    EXPECT_EQ(ipp::print_ip(ip_gold),"127.255.255.255");
}
//---------------------------------------------------------------------------------------

