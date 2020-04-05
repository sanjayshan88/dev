#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isHappy(int n)
{
    vector<int> nums;
    int result = 0;
    unordered_set<int> s;
    
    while (1) {
        cout << "n: " << n;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }

        for (int i=0; i<nums.size(); i++) {
            result += nums[i] * nums[i];
        }
        cout << " result: " << result << endl;

        if (result == 1) {
            return true;
        }

        if (s.find(result) != s.end()) {
            return false;
        } else {
            s.insert(result);
        }

        n = result;
        result = 0;
        nums = {0};
    }

    return false;
}

int main()
{
    cout << isHappy(19) << endl;

    return 0;
}