#ifndef DA_TRAINS_RAILGRAPH_H
#define DA_TRAINS_RAILGRAPH_H

#include <list>
#include <string>

#include "UGraph.h"
#include "Railway.hpp"
#include "Station.hpp"

class RailGraph : public UGraph {
    int superSourceID, superSinkID;
    bool profitMode;

public:
    // constructor
    explicit RailGraph(int n = 0);

    // methods
    bool addEdge(int src, int dest, double weight = 1, std::string service = "STANDARD", bool valid = true);
    int addSuperSource(), addSuperSink();
    bool addSource(int sourceID), addSink(int sinkID);

    double getFullPicture();
    std::list<std::pair<int, int>> getBusiestStationPairs(double& maxFlow);
};

#endif //DA_TRAINS_RAILGRAPH_H
