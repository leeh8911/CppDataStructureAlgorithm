#include <iostream>
#include <vector>


std::ostream& operator<<(std::ostream& os, std::vector<int> v){
    os << "[";
    for(auto elm : v){
        os << elm << " ";
    }
    os << "]";
    return os;
}
