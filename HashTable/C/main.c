#include <stdio.h>
#include "hashTable_linked.h"
int main(int argc, char const *argv[])
{
    /* code */
    printf("hash table \n");
    table h = initTable(15);
    insert("helloa", 504, h);
    insert("asdasdadasd", 154, h);
    insert("helasgfasasdasdasloa", 854, h);
    insert("helzxczxczxasloa", 364, h);
    insert("hellasdasdasoa", 754, h);
    insert("hedaszxcb zxxzxlloa", 144, h);
    insert("helasdsadasloa", 9634, h);
    insert("helbsdmafasdzxvzzxvzloa", 9841, h);
    insert("helloaqweuioquweopznmznxcmznc", 4, h);
    insert("helczcvzxczxaloa", 45741, h);
    insert("helzxvmhusdfyqzloa", 36, h);
    insert("ppqjkdgasknflkgmalkjpoq", 120, h);
    insert("kalglojlfsakaspqwnfgosnzm", 361, h);
    printTable(h);

    int data = find("kalglojlfsakaspqwnfgosnzm", h);
    printf("find data = %d \n", data);
    removeEntry("ppqjkdgasknflkgmalkjpoq", h);
    printTable(h);
    // destroyTable(h);
    // puts("destroyTable after");
    // if (h == NULL)
    // {
    //     puts("----------------");
    // }
    return 0;
}
