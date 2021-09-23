#include <stdio.h>

#include "skiplist.h"
int main(int argc, char const *argv[])
{
    printf("skip list \n");
    slist list = new_list();
    insert(list, 10, "abs");
    insert(list, 18, "ababs");
    insert(list, 160, "abeqws");
    insert(list, 129, "abqflp]gbs");
    insert(list, 149, "abqfku''lgbs");
    insert(list, 139, "abqfggsgsdbs");
    insert(list, 119, "abqfgbhass");
    insert(list, 419, "abdasbxc qfgbs");
    insert(list, 192, "abqfdfaasdgbs");
    insert(list, 519, "abqtuytufgbs");
    insert(list, 1291, "abqauysdfgbs");
    insert(list, 1249, "abqfg234bs");
    insert(list, 1569, "abqfmnghjmgbs");
    insert(list, 11239, "absxczqfgbs");
    insert(list, 1129, "abqfb nm,dxcvgbs");
    insert(list, 3519, "abqiortofgbs");
    insert(list, 6519, "abqfggiudwigbs");
    insert(list, 1439, "abqfgncdvfbs");
    insert(list, 624, "abzxcvbcwklobs");
    insert(list, 96, "azxbopipsbzbs");
    insert(list, 1321, "abgjhliuoohass");
    insert(list, 185, "abghasiortsooss");
    insert(list, 19465, "abgjseqjvblphass");
    insert(list, 175, "abghaxcxjouoss");
    // dup v = search(list, 96);
    // if (v != NULL)
    // {

    //     printf("value = %s \n", v);
    // }
    // else
    // {
    //     printf("value is null");
    // }
    sk_dump(list);

    delete (list, 1569);
    sk_dump(list);
    return 0;
}
