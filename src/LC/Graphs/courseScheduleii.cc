#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    if (numCourses == 0) {
        return {};
    }
    vector<int> result;
    /* adjacency list contains each course and
       its dependent courses
     */
    vector<vector<int>> adj(numCourses);
    /* count of number of courses that depend
       on each course
    */
    vector<int> num_dependencies(numCourses, 0);

    for (auto p : prerequisites) {
        int course = p[1];
        int dependent = p[0];
        adj[course].push_back(dependent);
        num_dependencies[dependent]++;
    }

    queue<int> q;
    for (int i=0; i<numCourses; i++) {
        if (num_dependencies[i] == 0) {
            q.push(i);
        } 
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i=0; i<adj[front].size(); i++) {
            int neighbor = adj[front][i];
            num_dependencies[neighbor]--;
            if (num_dependencies[neighbor] == 0) {
                q.push(neighbor);
            }
        }
        result.push_back(front);
    }
    return result;
}

int main()
{
    return 0;
}