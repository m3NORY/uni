#ifndef statistics_h
#define statistics_h

#include <vector>


class Stats {
public:
    static double average(std::vector<double> nums);
    static double middle(std::vector<double> nums);
    static double spread(std::vector<double> nums);
    static double smallest(std::vector<double> nums);
    static double largest(std::vector<double> nums);
};

#endif