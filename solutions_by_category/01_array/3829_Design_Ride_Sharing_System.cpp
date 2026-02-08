/*
[Medium]
3829. Design Ride Sharing System
https://leetcode.com/problems/design-ride-sharing-system/
*/

#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
/*
std::pair 
std::move
std::forward
std::swap
std::make_pair
*/
using namespace std;

using pii = pair<int, int>;

class RideSharingSystem {
private:
    int t;
    set<pii> riders; // {t, riderId}
    set<pii> drivers; // {t, dirverId}
    unordered_map<int, int> d; // (riderId, t) | for cancelRider()!

public:
    RideSharingSystem(): t(0) {
    }

    void addRider(int riderId) {
        d[riderId] = t;
        riders.insert({t, riderId});
        ++t;
    }

    void addDriver(int driverId) {
        drivers.insert({t, driverId});
        ++t;
    }

    vector<int> matchDriverWithRider() {
        if (riders.empty() || drivers.empty()) {
            return {-1, -1};
        }
        int driverId = drivers.begin()->second;
        int riderId = riders.begin()->second;
        drivers.erase(drivers.begin());
        riders.erase(riders.begin());
        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        auto it = d.find(riderId);
        if (it != d.end()) {
            riders.erase({it->second, riderId});
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */