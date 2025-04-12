#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

class comparator {
    public:
        bool operator() (vector <int> &a, vector <int> &b) {
            return a[0] < b[0];
        }
};

class Twitter {
    private: 
        int time = 0;        
        //userid = > {tweetid, time}
        unordered_map<int, vector <pair<int, int> > > posts;
        //followerId => {followeeId}
        unordered_map<int, set<int> > followers;
    public:
        Twitter() {
            time = 0; 
        }
        
        void postTweet(int userId, int tweetId) {
            posts[userId].push_back(make_pair(tweetId, time));
            time++;
        }
        
        vector<int> getNewsFeed(int userId) {

            vector <int> ans; 
            priority_queue<vector <int> , vector <vector <int> > , comparator> pq1;
            followers[userId].insert(userId);
            for (auto i : followers[userId]) {
                if (posts[i].size() != 0) {
                    int index = posts[i].size() - 1;
                    vector<pair<int, int> > v1 = posts[i];
                    pq1.push({v1[index].second, v1[index].first, index, i});
                }      
            }
            while (!pq1.empty() && ans.size() < 10) {
                vector<int> temp  = pq1.top();
                pq1.pop(); 
                ans.push_back(temp[1]);
                int index = temp[2];
                if (index > 0) {
                    index--;
                    vector <pair<int, int> > v1 = posts[temp[3]];
                    pq1.push({v1[index].second, v1[index].first, index, temp[3]});
                }
            }
            return ans;
        }

        void follow(int followerId, int followeeId) {
            followers[followerId].insert(followeeId); 
        }

        void unfollow(int followerId, int followeeId) {
            followers[followerId].erase(followeeId); 
        }
};
    
    /**
     * Your Twitter object will be instantiated and called as such:
     * Twitter* obj = new Twitter();
     * obj->postTweet(userId,tweetId);
     * vector<int> param_2 = obj->getNewsFeed(userId);
     * obj->follow(followerId,followeeId);
     * obj->unfollow(followerId,followeeId);
     */

int main() {
    return 0;
}
