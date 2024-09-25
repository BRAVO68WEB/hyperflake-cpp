// Copyright (c) 2024 by Jyotirmoy Bandyopadhayaya

#include "hyperflake.hpp"
#include <iostream>

using namespace std;
using namespace chrono;

int main(){
    Hyperflake hf;
    long current_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    for (int i = 0; i < 10000; i++) {
        long long id = hf.generate();
        cout << "ID: " << id << endl;
        cout << "Time since epoch: " << hf.decode(id) << endl;
    }
    
    long end_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    cout << "Time taken: " << end_time - current_time << "ms" << endl;
    return 0;
}