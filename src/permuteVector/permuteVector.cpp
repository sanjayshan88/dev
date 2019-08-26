#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permuteVectorHelper(vector<string>& in, vector<string>& out)
{

    // base case
    // in vector is empty
    if (in.empty()) {
        for (int i=0; i<out.size(); i++) {
            cout << out[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i=0; i<in.size(); i++) {
        // choose
        out.push_back(in[i]);
        in.erase(in.begin()+i);
        
        // explore
        permuteVectorHelper(in, out);
        
        // unchoose
        in.insert(in.begin()+i, out.back());
        out.pop_back();
    }
}

void permuteVector(vector<string>& in)
{
    vector<string> out;
    permuteVectorHelper(in, out);
}

int main()
{
    vector<string> in;
    in.push_back("a");
    in.push_back("b");
    in.push_back("c");
    in.push_back("d");
    permuteVector(in);
    
    return 0;
}