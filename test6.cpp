#include <iostream>
#include <vector>
#include <map>
#include <string>
using std::map;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main()
{
    map<string, vector<string>> famls;
    string first_name, last_name;
    bool read(string &last_name);
    // while([&]() -> bool
    // {
    //     cout << "Please input your last_name:" << endl;
    //     return cin>>last_name && last_name!="@q";
    // }())
    while(read(last_name))
    {
        cout << "Please input your Children_name: " << endl;
        while( cin>>first_name && first_name != "@q")
        {
            famls[last_name].push_back(first_name);
        }
    }   
    for( auto m : famls)
    {   
        cout << m.first << endl;
        for( auto v : m.second)
            cout << v << endl;   
    }
    return 0;
}
bool read(string &last_name)
{
    cout << "Please Input last_name: "<< endl;
    return cin>>last_name && last_name!="@q";
}