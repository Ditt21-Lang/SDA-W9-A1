#include <stdio.h>
#include "nbtrees.h"

int main(){
    Tree fanezi;
    boolean isKetemu;
    int okegas;
    printf("Biji\n");

    Create_tree(fanezi, 0);
    printf("%c\n", fanezi[1].info);

    PreOrder(fanezi);
    printf("\n");
    PostOrder(fanezi);
    printf("\n");
    Level_order(fanezi, 0);
    printf("\n");
    isKetemu = Search(fanezi, 'F');
    printf("%d", isKetemu);
    printf("\n");
    isKetemu = Search(fanezi, 'X');
    printf("%d\n", isKetemu);
    okegas = nbElmt (fanezi);
    printf("%d\n", okegas);

    okegas = nbDaun(fanezi);
    printf("%d\n", okegas);

    okegas = Level(fanezi, 'X');
    printf("%d\n", okegas);

    okegas = Depth(fanezi);
    printf("%d\n", okegas);

    InOrder(fanezi);
    return 0;
}