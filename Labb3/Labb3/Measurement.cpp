#include "Measurement.h"

double average_value(const std::vector<double> data)
{
    double sum = std::accumulate(data.begin(),
        data.end(),
        0.0);
    const size_t N = data.size();
    double avg = sum / N;

    return avg;
}

double std_dev(std::vector<double> data)
{
    const size_t N = data.size();
    double avg_val = average_value(data);
    double dev_square = 0;

    for (std::vector<double>::iterator itr = data.begin(); itr != data.end(); itr++) {
        dev_square += pow((*itr - avg_val), 2);
    }

    return std::sqrt(dev_square * (1.0 / (N - 1)));
}