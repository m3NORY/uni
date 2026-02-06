#include "statistics.h"
#include <algorithm>


// Среднее = сумма всех / количество
double Stats::average(std::vector<double> nums) {
    if (nums.empty()) return 0;
    
    double sum = 0;
    for (double n : nums) {
        sum += n;
    }
    return sum / nums.size();
}

// Медиана: сортируем и берем средний элемент
double Stats::middle(std::vector<double> nums) {
    if (nums.empty()) return 0;
    
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    
    if (size % 2 == 1) {
        return nums[size / 2];  // Нечетное
    } else {
        int m = size / 2;
        return (nums[m-1] + nums[m]) / 2.0;  // Четное
    }
}

// Дисперсия
double Stats::spread(std::vector<double> nums) {
    if (nums.size() <= 1) return 0;
    
    double avg = average(nums);
    double sum = 0;
    
    for (double n : nums) {
        double diff = n - avg;
        sum += diff * diff;
    }
    
    return sum / nums.size();
}

double Stats::smallest(std::vector<double> nums) {
    if (nums.empty()) return 0;
    
    double min = nums[0];
    for (double n : nums) {
        if (n < min) min = n;
    }
    return min;
}

double Stats::largest(std::vector<double> nums) {
    if (nums.empty()) return 0;
    
    double max = nums[0];
    for (double n : nums) {
        if (n > max) max = n;
    }
    return max;
}