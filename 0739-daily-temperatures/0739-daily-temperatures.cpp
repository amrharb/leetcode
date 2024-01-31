class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        	vector<int>ans((int)temperatures.size(),0);
            	for (int i = 0; i < (int)temperatures.size(); i++)
                	{
                    		while (!st.empty() && temperatures[i] > temperatures[st.top()])
                            		{
                                    			ans[st.top()]=i-st.top();
                                                			st.pop();
                                                            		}
                                                                    		st.push(i);
                                                                            	}
                                                                                	return ans;
    }
};