#include <iostream>
#include <string>
using namespace std;

class Clock {
    protected:
    int hour;
    int minute;
    int second;
    string ampm;
    
    public:
    Clock(int h, int m, int s, const string &ap)
        : hour(h), minute(m), second(s), ampm(ap) {}
    void display() {
        cout << "Clock = "
             << hour << ':'
             << (minute < 10 ? "0" : "") << minute << ':'
             << (second < 10 ? "0" : "") << second << ' '
             << ampm << '\n';
    }
};

class CGUClock : public Clock {
    public:
    CGUClock(int h, int m, int s, const string &ap)
        : Clock(h, m, s, ap) {}
    void display() {
        int h24 = hour;
        if (ampm == "PM" && h24 != 12) h24 += 12;
        if (ampm == "AM" && h24 == 12) h24 = 0;
        cout << "CGUClock = "
             << h24 << "時"
             << minute << "分"
             << second << "秒" << '\n';
    }
};

int main() {
    Clock cc(10, 25, 43, "PM");
    CGUClock cguc(10, 25, 43, "PM");
    cc.display();
    cguc.display();
    return 0;
}
