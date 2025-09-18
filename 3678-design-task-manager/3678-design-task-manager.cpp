class TaskManager {
public:
    multiset<vector<int>> st;
    map<int, int> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks)
            add(task[0], task[1], task[2]);
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = priority;
        st.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto idx = *st.lower_bound({mp[taskId], taskId, 0});
        st.erase(idx);
        mp[taskId] = newPriority;
        st.insert({mp[taskId], taskId, idx[2]});
    }

    void rmv(int taskId) {
        st.erase(st.lower_bound({mp[taskId], taskId, 0}));
        mp.erase(taskId);
    }

    int execTop() {
        if (st.empty())
            return -1;
        int idx = (*st.rbegin())[2];
        st.erase(*st.rbegin());
        return idx;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */