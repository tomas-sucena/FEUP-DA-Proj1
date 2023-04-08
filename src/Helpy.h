#ifndef DA_TRAINS_HELPY_H
#define DA_TRAINS_HELPY_H

#include "network/RailGraph.h"
#include "Reader.h"
#include "Utils.hpp"

using std::string;

class Helpy {
/* ATTRIBUTES */
private:
    Reader reader;
    uMap<string, int> stationIDs;
    uMap<int, string> stationNames;

    // graphs
    RailGraph graph;
    RailGraph* original;

    uSet<string> districts, municipalities;
    uMap<string, string> districtStations, municipalityStations;

    // maps used to process commands
    static std::map<string, int> command, target, what;

/* CONSTRUCTOR */
public:
    Helpy();

/* METHODS */
private:
    void fetchData();

    static string readInput(const string& instruction, uSet<string>& options);
    static double readNumber(const string& instruction);
    string readStation();
    string readCity();

    void advanced_mode();
    void guided_mode();
    bool process_command(string& s1, string& s2, string& s3);

    static void printPath(Path& p);
    double getIncomingTrains(int index, bool display = false, bool original = false);
    double getTrainsBetweenStations(int src, int sink);

    // commands
    void displayAllStations();
    void displayDataDirectory();
    void displayOperatingMode();
    void displayBusiest(string& s);
    void displayBusiestPairs();
    void displayRailwaySources();
    void displayRailwaySinks();
    std::vector<Edge*> printEdges(int station);

    void changeDataDirectory();
    void changeOperatingMode();
    void calculateMaximumTrains();
    void determineAffectedStations();
    void changeRailwayNetwork();
    void changeRailwaySources();
    void changeRailwaySinks();
    void readInputFromTable(std::list<std::pair<int,int>>& edges, std::vector<Edge*> ref, int station);

public:
    void terminal();
};

#endif
