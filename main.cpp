#include <iostream>
#include "set.h"
#include <vector>

/*-----------------------------------
 * Program Name: Balance Tree
 * Author: Andrew Miner
 * Purpose: Self Balancing Tree Structure
 * Notes: Sizes of each node customizalbe
 *        in set
 */

using namespace std;

void test();

int main(int argc, char *argv[])
{
    test();
    return 0;
}

void test()
{
    int ins[34] = {10, 28, 2, 5, 13, 16, 19, 22, 33, 40, 0, 1, 3, 4, 6, 7, 8, 11, 12, 14, 15, 17, 18, 20, 21, 23, 24, 26, 31, 32, 34, 35, 50, 51};
    Set<int> bTree;

    for(int i = 0; i < 34; i++)
    {
        cout << "Inserting: " << ins[i] << endl;
        if(!bTree.insert(ins[i]))
            cout << "Insertion Failed" << endl;
        cout << bTree << std::endl;
        cout << "========================" << std::endl;
    }

    cout << "========================" << std::endl << "DONE INSERTING" << std::endl << "========================" << std::endl;

    cout << "Testing Copy Function " << std::endl;
    Set<int> cTree(bTree);
    cout << "Copy: " << std::endl << cTree << std::endl << "=================================" << std::endl;


    cout << "Testing Delete Functions:\nDeleting: 22\n";
    bTree.erase(22);
    cout << bTree << std::endl << "=================================" << std::endl;

    cout << "Deleting: 3" << std::endl;
    if(!bTree.erase(3))
        cout << "DELETE FAILED\n";
    cout << bTree << std::endl << "=================================" << std::endl;

    cout << "Deleting: 51" << std::endl;
    if(!bTree.erase(51))
        cout << "DELETE FAILED\n";
    cout << bTree << std::endl << "=================================" << std::endl;

    for(int i = 33; i >= 0; i--)
    {
         cout << "Deleting: " << ins[i] << std::endl;
         if(!bTree.erase(ins[i]))
             cout << "DELETE FAILED: Not Found\n";
         cout << bTree << std::endl << "=================================" << std::endl;
    }

    cout << "========================" << std::endl << "DONE DELETING" << std::endl << "========================" << std::endl;
    cout << "Testing Clear on following tree: \n" << cTree << "==================================" << std::endl;
    cTree.clear();
    cout << "Clear Result: " << std::endl << cTree << std::endl;
}
