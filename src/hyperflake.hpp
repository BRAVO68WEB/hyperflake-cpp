// Copyright (c) 2024 by Jyotirmoy Bandyopadhayaya

#include <bits/stdc++.h>

class Hyperflake {
    public:
        long long generate() {
            auto now = std::chrono::system_clock::now();
            auto epoch = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
            auto time_since_epoch = epoch - 946684800000;
            auto worker_id = getpid() % 1024;
            auto node_id = getpid() % 1024;
            static int sequence_number = 0;
            auto sequence = sequence_number++;
            long long id = (time_since_epoch << 22) | (worker_id << 10) | sequence;
            return id;
        }

        long decode(long long id) {
            auto time_since_epoch = (id >> 22) + 946684800000;
            return time_since_epoch;
        }
};