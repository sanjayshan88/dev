#include <iostream>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int> stones)
{
    priority_queue<int> pq;
    for (int i=0; i<stones.size(); i++) {
        pq.push(stones[i]);
    }

    while (pq.size() > 1) {
        int elem1 = pq.top();
        pq.pop();
        int elem2 = pq.top();
        pq.pop();
        if (elem1 != elem2) {
            pq.push(elem1 - elem2);
        }
    }

    if (pq.empty()) {
        return 0;
    }
    return pq.top();
}

int main()
{

    vector<int> stones;
    stones.push_back(2);
    stones.push_back(7);
    stones.push_back(4);
    stones.push_back(1);
    stones.push_back(8);
    stones.push_back(1);

    cout << lastStoneWeight(stones) << endl;

    return 0;
}