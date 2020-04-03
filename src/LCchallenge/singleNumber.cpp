#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{

    int result = 0;
    for (int i=0; i<nums.size(); i++) {
        result ^= nums[i];
    }

    return result;
}

int main() 
{
    vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    cout << singleNumber(v) << endl;

    return 0;
}