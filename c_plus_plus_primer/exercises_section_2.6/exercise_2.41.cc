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
    if (data.units_sold)
        std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue << " " << data.revenue / data.units_sold<< std::endl;
    else   
        std::cout << data.bookNo << " not units sold" << std::endl;
}

Sales_data sum(Sales_data &data1, Sales_data &data2){
    Sales_data data;

    if (data1.bookNo != data2.bookNo){
        std::cout << "ISBN is not same" << std::endl;
        return data;
    }
    data.bookNo = data1.bookNo;
    data.units_sold = data1.units_sold + data2.units_sold;
    data.revenue = data1.revenue + data2.revenue;
    return data;
}

int main(){
    // 1.5.1 (p.22) exercise 1.20
    // Sales_data data;
    // while (read_data(data)){
    //     write_data(data);
    // }

    // 1.5.1 (p.22) exercise 1.21
    Sales_data data1, data2, data;
    read_data(data1);
    read_data(data2);
    write_data(data1);
    write_data(data2);
    data = sum(data1, data2);
    write_data(data);
    return 0;
}

// 1.5.2 (p.24)
// 1.6 (p.25)