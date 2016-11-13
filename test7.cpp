#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::ifstream;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> m;
    string key,value;
    for(;map_file>>key &&getline(map_file, value);)
    {
        if(value.size()>0) m[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
    }
    return m;
}
const string& transform(string &s, map<string, string> &m)
{
    auto m_it = m.find(s);
    return m_it == m.cend() ? s : m_it -> second;
}
void word_transform(ifstream &map, ifstream &input)
{
    auto trans_map = buildMap(map);
    for(string text;getline(input,text);)
    {
        std::istringstream iss(text);
        for(string word; iss>>word;)
            cout << transform(word, trans_map) <<" ";
        cout << std::endl;
    }
}
int main()
{
    ifstream ifs_map("./data/give.txt");
    ifstream ifs_content("./data/tran.txt");
    if(ifs_map && ifs_content) word_transform(ifs_map, ifs_content);
    else cout << "file is empty!";
}
