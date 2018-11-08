#include <iostream>
#include <time.h>

#include "LinkList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    LinkList<int> list;
    clock_t startTime, endTime;
    startTime = clock();
    for (int i = 0; i < 10; i++)
    {
        /* code */
        list.push(i);
    }
    endTime = clock();
    cout << "----push耗时:" << endTime - startTime<<"ms" << endl;

    // startTime = clock();
    // list.deleteNode(9);
    // endTime = clock();
    // cout << "----delete耗时:" << endTime - startTime<<"ms" << endl;
    // startTime = clock();
    // list.deleteByPos(8);
    // endTime = clock();
    // cout << "----delet epos 耗时:" << endTime - startTime<<"ms" << endl;
    list.printData();
    return 0;
}
