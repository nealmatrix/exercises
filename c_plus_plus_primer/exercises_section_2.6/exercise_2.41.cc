#include <string>
#include <iostream>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream & read_data(Sales_data &data){
    double price;
    std::cin >> data.bookNo >> data.units_sold >> price;
    if (std::cin)
        data.revenue = data.units_sold * price;
    else
        data = Sales_data();
    return std::cin;
}

void write_data(Sales_data &data){
    std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << std::endl;
}

int main(){
    Sales_data data;
    while (read_data(data)){
        write_data(data);
    }
}

// 1.5.1 (p.22)
// 1.5.2 (p.24)
// 1.6 (p.25)