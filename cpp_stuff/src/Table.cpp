
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Table.h"

void Table::AddToTable(std::string filename, std::string timestamp){
    // std::cout << "add timestamp: " << timestamp << std::endl;

    // parse timestmp string and convert to double
    row tmp_row;
    tmp_row.timestamp_orig = timestamp;
    tmp_row.filename = filename;
    
    size_t start = 0;
    size_t end = 4;
    std::string timestamp_year = timestamp.substr(start, end);
    start = 5;
    end = 2;
    std::string timestamp_month = timestamp.substr(start, end);
    start = 8;
    end = 2;
    std::string timestamp_day = timestamp.substr(start, end);

    // debug
    // std::cout << timestamp_year << std::endl;
    // std::cout << timestamp_month << std::endl;
    // std::cout << timestamp_day << std::endl;

    tmp_row.timestamp_int = std::stoi(timestamp_year + timestamp_month + timestamp_day);

    // pushback
    table_vec.push_back(tmp_row);
}

void Table::PrintTable(){
    for (int i; i<table_vec.size(); i++){
        std::cout << "row " << i << " --> " << table_vec.at(i).filename << ", " << 
                                               table_vec.at(i).timestamp_orig << ", " << 
                                               table_vec.at(i).timestamp_int << std::endl;
    }
}