#include <queue>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        // A graph of connections 
        std::vector<std::vector<int>> graph(n);

        // The number of connections each node has
        std::vector<int> connections(n, 0);     

        // The vector containing the answer
        std::vector<int> ans;    
        
        for(const auto &e : edges) { 
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            connections[e[0]]++;
            connections[e[1]]++;
        }

        // The topological order (where the last elements have no connections)
        std::queue<int> q;

        for(int i=0; i<n;i++) {
            if(connections[i] == 1) {
                q.push(i); // Adding leaf nodes to the queue
                connections[i]--; // Reducing the number of connections that node has
            }
        } 

        while(!q.empty()) {
            int s = q.size();
            ans.clear();

            for(int i=0; i < s; i++) {
                // Getting the last element of the queue and popping it from the queue
                int curr = q.front(); q.pop();

                // Adding that element to the current answer
                ans.push_back(curr);

                // Looping through the children of the current node and decrementing the number of connections that node has
                // If that child node now has only one connection (i.e is a leaf) then add it to the queue
                for(auto child : graph[curr]){ 
                    connections[child]--;
                    if(connections[child]==1) 
                        q.push(child);   
                }
            }
        }
        
        //If there is only 1 node in the graph, the min height is 0, with root being '0'
        if(n==1)
            ans.push_back(0); 

        return ans;
    }
};

int main(){
    std::cout << "LeetCode Problem 310 - Minimum Height Trees" << std::endl;
    Solution s;

    std::vector<std::vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    int n = 6;
    std::vector<int> ans = s.findMinHeightTrees(n, edges);

    std::cout << "Answer: [";
    for(const auto& val : ans) {
        std::cout << val << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}