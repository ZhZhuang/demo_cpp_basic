//
// Created by Administrator on 2023/12/26.
//

// c++ 中 unordered_map和map的使用


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    std::unordered_map<std::string, int> myMap = {
            {"apple", 5},
            {"banana", 7},
            {"orange", 2}
    };
    /*************    遍历  *************/
    // 普通for循环遍历，迭代器
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    // foreach遍历
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    /*************   查找  *************/
    auto e = myMap.find("apple");
    if(e!=myMap.end()){
        cout << "apple found with value " << e->second << std::endl;
    }

    /*************    删除  *************/
    myMap.erase("apple");
    auto e1 = myMap.find("apple");
    if(e1!=myMap.end())
    {
        cout << "apple found with value " << e1->second << std::endl;
    } else{
        cout << "not found!"<< endl;
        //cout<<e1->second<<endl; // 报错Process finished with exit code 139， Segmentation Fault
    }

    /*************    查找  *************/
    int orangeCount = myMap["orange"];
    int bananaCount = myMap.at("banana");
    cout << "orange count:"<<orangeCount<<endl;
    cout << "banana count:"<<bananaCount<<endl;

    /*************    插入  *************/
    cout<<"insert..."<<endl;
    myMap.insert(make_pair("peer", 5));
    myMap.emplace("bar", 10);
    //myMap.insert(pair<>)

    // 使用下标操作符插入元素
    myMap["apple1"] = 5;
    myMap["banana1"] = 7;
    myMap["orange1"] = 2;

    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
