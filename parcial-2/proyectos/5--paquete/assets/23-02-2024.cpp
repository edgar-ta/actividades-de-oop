/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

class Interlocutor {
    private:
    
    std::string name;
    std::string city_name;
    std::string state_name;
    std::string zip_code;
    
    public:
    Interlocutor(
        std::string, 
        std::string, 
        std::string, 
        std::string
    );
    
    std::string get_name()       const { return name; }
    std::string get_city_name()  const { return city_name; }
    std::string get_state_name() const { return state_name; }
    std::string get_zip_code()   const { return zip_code; }
};

std::ostream& operator<<(std::ostream& cout, const Interlocutor& interlocutor) {
    return cout 
        << interlocutor.get_name() 
        << " (who lives in " 
        << interlocutor.get_city_name() 
        << ", " 
        << interlocutor.get_state_name() 
        << ")";
}

Interlocutor::Interlocutor(
    std::string name, 
    std::string city_name, 
    std::string state_name, 
    std::string zip_code
): 
    name(name), 
    city_name(city_name), 
    state_name(state_name), 
    zip_code(zip_code)
{}

inline double clamp_minimum(double minimum, double value) {
    if (value < minimum) return minimum;
    return value;
}

class Package {
    private:
    
    Interlocutor sender;
    Interlocutor receiver;
    double weight_in_ounzes;
    double price_per_ounze;
    
    public:
    
    Package(Interlocutor, Interlocutor, double, double);
    
    double get_cost() const;
    inline double get_weight_in_ounzes() const { return weight_in_ounzes; };
    inline double get_price_per_ounze() const { return price_per_ounze; };
    inline const Interlocutor& get_sender() const { return sender; };
    inline const Interlocutor& get_receiver() const { return receiver; };
};

Package::Package(
    Interlocutor sender, 
    Interlocutor receiver, 
    double weight_in_ounzes, 
    double price_per_ounze
): 
    sender(sender),
    receiver(receiver),
    weight_in_ounzes(clamp_minimum(0.0, weight_in_ounzes)),
    price_per_ounze(clamp_minimum(0.0, price_per_ounze))
{}

double Package::get_cost() const {
    return weight_in_ounzes * price_per_ounze;
}

class TwoDayPackage : public Package {
    private:
    
    double two_day_fee;
    
    public:
    
    TwoDayPackage(Interlocutor, Interlocutor, double, double, double);
    
    double get_cost() const;
    inline double get_two_day_fee() const { return two_day_fee; };
};

TwoDayPackage::TwoDayPackage(
    Interlocutor sender, 
    Interlocutor receiver, 
    double weight_in_ounzes, 
    double price_per_ounze,
    double two_day_fee
): 
    Package(sender, receiver, weight_in_ounzes, price_per_ounze),
    two_day_fee(two_day_fee)
{}

double TwoDayPackage::get_cost() const {
    return Package::get_cost() + two_day_fee;
}

class NightPackage : public Package {
    private:
    
    double additional_ounze_fee;
    
    public:
    
    NightPackage(Interlocutor, Interlocutor, double, double, double);
    
    double get_cost() const;
    inline double get_additional_ounze_fee() const { return additional_ounze_fee; };
};

NightPackage::NightPackage(
    Interlocutor sender, 
    Interlocutor receiver, 
    double weight_in_ounzes, 
    double price_per_ounze,
    double additional_ounze_fee
): 
    Package(sender, receiver, weight_in_ounzes, price_per_ounze),
    additional_ounze_fee(additional_ounze_fee)
{}

double NightPackage::get_cost() const {
    return Package::get_cost() + (get_additional_ounze_fee() * get_weight_in_ounzes());
}

void ship_package(const NightPackage& night_package) {
    std::cout 
        << night_package.get_sender() 
        << " is shipping a package to " 
        << night_package.get_receiver()
        << " at night..."
        << std::endl
        << "Because it is a night package, there is an additional fee of $" 
        << std::setprecision(2) << night_package.get_additional_ounze_fee()
        << " per ounze compared to the regular $"
        << std::setprecision(2) << night_package.get_price_per_ounze()
        << " that are required per package."
        << "Since the package weighs " 
        << std::setprecision(2) << night_package.get_weight_in_ounzes() 
        << " ounzes, the final shipping cost is: $"
        << std::setprecision(2) << night_package.get_cost()
        << std::endl
        ;
}

void ship_package(const TwoDayPackage& two_day_package) {
    std::cout 
        << two_day_package.get_sender()
        << " is shipping a package to "
        << two_day_package.get_receiver()
        << " in two days..."
        << std::endl
        << "The package weighs "
        << std::setprecision(2) << two_day_package.get_weight_in_ounzes()
        << " ounzes, at $"
        << std::setprecision(2) << two_day_package.get_price_per_ounze()
        << " per ounze, but because it is a quick delivery, there is an additional fee of $"
        << std::setprecision(2) << two_day_package.get_two_day_fee()
        << " over the original shipping cost of $"
        << std::setprecision(2) << two_day_package.Package::get_cost()
        << ", thus, the final shipping cost is: $" 
        << two_day_package.get_cost()
        << std::endl
        ;
}

int main() {
    TwoDayPackage two_day_package(
        Interlocutor(
            "Edgar Trejo Avila", 
            "San Juan del Río", 
            "Querétaro", 
            "76806"
        ),
        Interlocutor(
            "Daniel Hernández Martínez", 
            "San Juan del Río", 
            "Querétaro", 
            "43202"
        ),
        20.0,
        0.50,
        50.0
    );
    ship_package(two_day_package);
    
    std::cout << std::endl;
    
    NightPackage night_package(
        Interlocutor(
            "Edgar Trejo Avila", 
            "San Juan del Río", 
            "Querétaro", 
            "76806"
        ),
        Interlocutor(
            "Daniel Hernández Martínez", 
            "San Juan del Río", 
            "Querétaro", 
            "43202"
        ),
        20.0,
        0.50,
        50.0
    );
    ship_package(night_package);

    return 0;
}
