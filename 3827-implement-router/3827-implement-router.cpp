class Router {
public:
    unordered_map<int, deque<int>> router;
    map<vector<int>, bool> existed;
    deque<vector<int>> packets;
    int memoryLimit;
    Router(int memoryLimit) : memoryLimit(memoryLimit) { router.clear(); }

    bool addPacket(int source, int destination, int timestamp) {
        if (existed.count({source, destination, timestamp}))
            return false;
        existed[{source, destination, timestamp}] = true;
        router[destination].push_back(timestamp);
        packets.push_back({source, destination, timestamp});
        if (packets.size() > memoryLimit) {
            auto oldest = packets.front();
            packets.pop_front();
            existed.erase(oldest);
            router[oldest[1]].pop_front();
        }
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty())
            return {};
        auto oldest = packets.front();
        packets.pop_front();
        existed.erase(oldest);
        router[oldest[1]].pop_front();
        return oldest;
    }

    int getCount(int destination, int startTime, int endTime) {
        return upper_bound(router[destination].begin(),
                           router[destination].end(), endTime) -
               lower_bound(router[destination].begin(),
                           router[destination].end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */