// You are running a website, and you are trying to calculate your advertising revenue. 
// Write a program that allows you to enter 3 pieces of data:
// - How many ads were watched.
// - What percentage of users clicked on an ad.
// - The average earnings per clicked ad.
// Store those 3 values in a struct. Pass that struct to another function that prints each of the values.
// The print function should also print how much you made for that day (multiply the 3 fields together).

#include <iostream>

struct SiteStats {
    int adsNumber {};
    double userClickPercentage {};
    double averageEarning {};
};

void printSiteStats(const SiteStats& stats) {
    using namespace std;
    cout << stats.adsNumber << " ads  were watched ";
    cout << "with " << stats.userClickPercentage << "\% of user clicks. ";
    cout << "The average earning was " << stats.averageEarning << "$ per click. ";
    
    double totalEarning = stats.adsNumber * stats.averageEarning * stats.userClickPercentage;
    cout << "The total earning is " << totalEarning << "$" << "\n";
};

int main() {
    SiteStats stats {100, 0.2, 0.01};
    printSiteStats(stats);
}