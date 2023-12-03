#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    //creation
    unordered_map <string, int> m;

    //insertion:
    //1:
    pair<string,int> p= make_pair("asghar", 3);
    m.insert(p);

    //2:
    pair<string, int> p2("ali", 2);
    m.insert(p2);

    //3:
    m["CS"]= 1;

    //searching value of corresponding key:
    cout<<m["ali"]<<endl;
    cout<< m.at("asghar")<<endl;

    //size check
    cout<<m.size()<<endl;

    //to check presence of any key
    cout<< m.count("hello")<<endl;
    cout<< m.count("asghar")<<endl;

    //erase
    m.erase("CS");
    cout<< m.size()<<endl;

    //iteration
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout<< it->first << " " << it->second <<endl;
        it++;
    }
    /* in case of unordered_map, the way we insert the keys are not printed in the same way.
     but if we use map then it will display the keys in ordered way.*/




    
}