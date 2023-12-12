#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 语法 迭代器，

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (string &s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto it = anagramGroups.begin(); it != anagramGroups.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(input);

    for (auto group : result) {
        for (string &s : group) {
            cout << s << " ";
        }
        cout << endl;
    }

    //============
    vector<int> arr = {2,4,6,9,60,19};
    sort(arr.begin(), arr.end());
    for(auto e : arr){
        cout<< e << " ";
    }
    cout<<endl;
    cout<< *arr.begin()<< endl;
    for(auto it = arr.begin(); it != arr.end(); it++){
    //for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++){
        cout<< *it << " ";
    }
    cout<<endl;
    return 0;
}
