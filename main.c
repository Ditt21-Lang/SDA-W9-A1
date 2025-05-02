#include <stdio.h>
#include "nbtrees.h"

void menu() {
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal LevelOrder\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 Node Tree\n");
    printf("11. Exit\n");
    printf("Pilih menu: ");
}

int main(){
    Tree tree;
    boolean is_found;
    boolean exit = false;
    int menu_select;
    int arg_int; 
    char arg_char1, arg_char2;
    Create_tree(tree, 0);

    while(!exit) {
        menu();
        scanf(" %d", &menu_select);
        

        switch (menu_select)
        {
        case 1:
            printf("Tree dengan pre order\n");
            PreOrder(tree);
            break;
        case 2:
            printf("Tree dengan in order\n");
            InOrder(tree);
            break;
        case 3:
            printf("Tree dengan post order\n");
            PostOrder(tree);
            break;
        case 4:
            printf("Maksimal kedalaman: ");
            scanf(" %d", &arg_int);
            printf("Tree dengan level order\n");
            Level_order(tree, arg_int);
            break;
        case 5:
            printf("Seluruh node pada binary tree\n");
            PrintTree(tree);
            break;
        case 6:
            printf("Node yang ingin dicari: ");
            scanf(" %c", &arg_char1);
            if(Search(tree, arg_char1) == true) {
                printf("node dengan info %c ditemukan\n", arg_char1);
            }else {
                printf("node dengan info %c tidak ditemukan\n", arg_char1);
            }
            break;
        case 7:
            arg_int = nbDaun(tree);
            printf("Banyak leaf adalah: %d\n", arg_int);
            break;
        case 8:
            printf("Node yang ingin dicari: ");
            scanf(" %c", &arg_char1);
            arg_int = Level(tree, arg_char1);
            if(arg_int != -1) {
                printf("node dengan info %c ditemukan di level %d\n", arg_char1, arg_int);
            }else {
                printf("node dengan info %c tidak ditemukan\n", arg_char1);
            }
            break;
        case 9:
            printf("Kedalaman tree adalah %d\n", Depth(tree));
            break;
        case 10:
            printf("Node yang ingin pilih: ");
            scanf(" %c", &arg_char1);
            printf("Node yang ingin dibandingkan: ");
            scanf(" %c", &arg_char2);
            if(Search(tree, arg_char1) == false){
                printf("Node dengan info %c tidak ditemukan\n", arg_char1);
                break;
            }
            if(Search(tree, arg_char2) == false) {
                printf("Node dengan info %c tidak ditemukan\n", arg_char1);
                break;
            }
            arg_char1 = Max(arg_char1, arg_char2);
            printf("Yang paling besar adalah %c\n", arg_char1);
            break;
        case 11:
            exit = true;
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }

        if(!exit) {
            printf("Klik apapun untuk melanjutkan\n");
            getchar();
            getchar();
        }
    }
    
    
    return 0;
}