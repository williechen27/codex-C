#include <iostream>
#include <string>
using namespace std;

// 驅動方式的列舉型別
enum class Drivetrain {
    FWD,   // 前驅
    RWD,   // 後驅
    AWD    // 四驅 / 四輪傳動
};

// 把 Drivetrain 轉成好看的字串
string drivetrainToString(Drivetrain d) {
    switch (d) {
        case Drivetrain::FWD: return "FWD";
        case Drivetrain::RWD: return "RWD";
        case Drivetrain::AWD: return "AWD";
        default: return "Unknown";
    }
}

class Car {
private:
    string m_brand;
    string m_model;
    int m_year;
    int m_maxSeating;
    int m_horsepower;       // 馬力
    double m_zeroTo100;     // 0-100 km/h 加速 (秒)
    Drivetrain m_drivetrain; // 驅動方式

public:
    // 建構函式（初始化列表）
    Car(string brand, string model, int year,
        int maxSeating, int horsepower, double zeroTo100,
        Drivetrain drivetrain)
        : m_brand(brand),
          m_model(model),
          m_year(year),
          m_maxSeating(maxSeating),
          m_horsepower(horsepower),
          m_zeroTo100(zeroTo100),
          m_drivetrain(drivetrain) {
    }

    // Getter
    string getBrand() const { return m_brand; }
    string getModel() const { return m_model; }
    int getYear() const { return m_year; }
    int getMaxSeating() const { return m_maxSeating; }
    int getHorsepower() const { return m_horsepower; }
    double getZeroTo100() const { return m_zeroTo100; }
    Drivetrain getDrivetrain() const { return m_drivetrain; }

    // 車齡
    int getAge(int currentYear) const {
        return currentYear - m_year;
    }

    // 簡單判斷是不是「超跑 / Hypercar」等級
    // 這個條件你之後可以自己改：
    // 例：馬力 >= 600 或 0-100 <= 3.0 秒，就當作 hypercar
    bool isHyperCar() const {
        return (m_horsepower >= 600) || (m_zeroTo100 <= 3.0);
    }

    // 印出車輛資訊
    void printInfo() const {
        cout << "Brand: " << m_brand
             << ", Model: " << m_model
             << ", Year: " << m_year
             << ", Max Seating: " << m_maxSeating
             << ", Horsepower: " << m_horsepower << " hp"
             << ", 0-100 km/h: " << m_zeroTo100 << " s"
             << ", Drivetrain: " << drivetrainToString(m_drivetrain)
             << endl;
    }
};

int main() {
    // 幾台有感的車
    Car car1("Ferrari", "488 Pista", 2019, 2, 710, 2.85, Drivetrain::RWD);
    Car car2("Lamborghini", "Aventador SVJ", 2018, 2, 770, 2.80, Drivetrain::AWD);
    Car car3("McLaren", "720S", 2020, 2, 710, 2.90, Drivetrain::RWD);
    Car car4("Toyota", "GR Yaris", 2022, 4, 272, 5.2, Drivetrain::AWD);

    int currentYear = 2025;

    Car cars[] = {car1, car2, car3, car4};

    for (const auto& c : cars) {
        c.printInfo();
        cout << "  Age: " << c.getAge(currentYear) << " years" << endl;
        cout << "  Is HyperCar? "
             << (c.isHyperCar() ? "YES 🔥" : "NO (比較像性能車或鋼砲)") 
             << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
