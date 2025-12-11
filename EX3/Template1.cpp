#include <iostream>
#include <string>
using namespace std;

template <class T, class U>
class mypair {
    private:
    T m_first;
    U m_second;
    public:
    mypair (T t, U u) {
        m_first = t;
        m_second = u;
    }
    auto bigger() {
        return (m_first>m_second)?m_first:m_second;
    }
};

int main() {
    mypair<int, double> mypair(23, 55.688);
    cout << mypair.bigger() << " bigger" << endl;
    return 0;
}
