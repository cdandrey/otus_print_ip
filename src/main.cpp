
#include "../lib/print_ip.h"

#include <string>
#include <vector>
#include <list>

int main(int,char**)
{
    ipp::print_ip(static_cast<char>(-1));
    ipp::print_ip(static_cast<short>(0));
    ipp::print_ip(2130706433);
    ipp::print_ip(8875824491850138409);
    
    std::string sip{"1.1.1.255"};
    std::vector<int> vip{255,0,255,0};
    std::list<int> lip{1,255,1,255};

    ipp::print_ip(sip);
    ipp::print_ip(vip);
    ipp::print_ip(lip);

    return 0;
}
