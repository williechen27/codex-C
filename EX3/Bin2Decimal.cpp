#include <iostream>
#include <string>
using namespace std;

class Bin2Decimal {
    private:
    string bin;
    int bin_to_int(const string &b) {
        int value = 0;
        for (char c : b) {
            value = value*2+(c-'0');
        }
        return value;
    }
    
    public:
    Bin2Decimal(const string &b) : bin(b) {}
    string to_decimal() {
        int dec = bin_to_int(bin);
        return bin + " -> " + to_string(dec);
    }
    string to_decimal(const string &b) {
        int dec = bin_to_int(b);
        return  b + " -> " + to_string(dec);
    }
};

int main() {
    Bin2Decimal d("1000");
    cout << d.to_decimal() << endl;
    cout << d.to_decimal("1111") << endl;
    return 0;
}
