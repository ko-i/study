#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    unique_ptr<int> orig(new int(5));
    cout << *orig << endl;
    auto stolen = move(orig);
    cout << *orig << endl;

    return 0;
}