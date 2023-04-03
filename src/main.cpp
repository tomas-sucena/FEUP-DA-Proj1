#include <iostream>

#include "network/RailGraph.h"
#include "Reader.h"

int main() {
    Reader reader("../data");
    RailGraph network = reader.read();

    time_t start, end;
    time(&start);

    double flow = 0;
    network.getBusiestStationPairs(flow);
    std::cout << flow << std::endl;

    time(&end);
    std::cout << "Execution time: " << double(end - start) << std::endl;

    return 0;
}
