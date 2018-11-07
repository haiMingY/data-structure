#include <iostream>

using namespace std;

void leftRotate(int arr[], int d, int n);
void leftRotateByOne(int arr[], int n);
void printArray(int arr[], int n);

void leftRotateByOne(int arr[], int n) //运行一次只将第一个元素换到最后的位置
{
    int temp = arr[0], i;

    for (i = 0; i < n - 1; i++)
    {
        /* code */
        arr[i] = arr[i + 1];
    }
    arr[i] = temp;
};
void leftRotate(int arr[], int d, int n) // 转换d次
{

    for (int i = 0; i < d; i++)
    {
        /* code */
        leftRotateByOne(arr, n);
    }
};

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    };
};

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << "---sizeof:" << sizeof(arr) << " one is :" << sizeof(arr[0]) << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " n is :" << n << endl;
    // Function calling
    leftRotate(arr, 7, n);
    printArray(arr, n);
    return 0;
}
