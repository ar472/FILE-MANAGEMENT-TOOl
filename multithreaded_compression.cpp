#include <iostream>
#include <thread>
#include <string>

using namespace std;

void compressPart(string text)
{
    for(char c : text)
    {
        if(c != ' ')
        cout << c;
    }
}

int main()
{
    string part1 = "This is ";
    string part2 = "multithread example";

    thread t1(compressPart, part1);
    thread t2(compressPart, part2);

    t1.join();
    t2.join();

    return 0;
}
