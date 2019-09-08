
#include "../lib/print_ip.h"

#include <string>
#include <vector>
#include <list>

int main(int,char**)
{
    std::cout << ipp::print_ip(static_cast<char>(-1)) << std::endl;
    std::cout << ipp::print_ip(static_cast<short>(0)) << std::endl;
    std::cout << ipp::print_ip(2130706433) << std::endl;
    std::cout << ipp::print_ip(8875824491850138409) << std::endl;
    
    std::string sip{"1.1.1.255"};
    std::vector<int> vip{255,0,255,0};
    std::list<int> lip{1,255,1,255};

    std::cout << ipp::print_ip(sip) << std::endl;
    std::cout << ipp::print_ip(vip) << std::endl;
    std::cout << ipp::print_ip(lip) << std::endl;

    return 0;
}
