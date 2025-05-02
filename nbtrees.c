#include <string.h>
#include <stdio.h>
#include "nbtrees.h"

void Create_tree(Tree tree, int Jml_Node){
    Tree pohon = {
        {0},
        {'A', 2, 0, 0}, 
        {'B', 4, 3, 1}, 
        {'C', 6, 0, 1}, 
        {'D', 0, 5, 2}, 
        {'E', 9, 0, 2},
        {'F', 0, 7, 3},
        {'G', 0, 8, 3},
        {'H', 0, 0, 3},
        {'I', 0, 10, 5},
        {'J', 0, 0, 5},
    };
    memcpy(tree, pohon, sizeof(pohon));
}

boolean IsEmpty (Tree tree){
    if (tree[1].first_son == 0 && tree[1].next_brother == 0)
    {
        return true;
    } else {
        return false;
    }
    
}

void PreOrderHelper(Tree tree, address index){
    if (tree[index].info == '\0'){
        return;
    } else {
        printf("%c", tree[index].info);
        PreOrderHelper(tree, tree[index].first_son);
        PreOrderHelper(tree, tree[index].next_brother);
    }
}

void PreOrder (Tree tree){
    PreOrderHelper(tree, 1);
    printf("\n");
}

void InOrderHelper(Tree tree, address index){
    int saudara;

    if (tree[index].info == '\0'){
        return;
    } else {
        InOrderHelper(tree, tree[index].first_son);
        saudara =  tree[tree[index].first_son].next_brother;
        printf("%c", tree[index].info);
        while (saudara != 0){
            InOrderHelper(tree, saudara);
            saudara = tree[saudara].next_brother;
        }

    }
}

void InOrder (Tree tree){
    InOrderHelper(tree, 1);
    printf("\n");
}

void PostOrderHelper(Tree tree, address index){
    if(tree[index].info == '\0'){
        return;
    } else {
        PostOrderHelper(tree, tree[index].first_son);
        printf("%c", tree[index].info);
        PostOrderHelper(tree, tree[index].next_brother);
    }
}

void PostOrder (Tree tree){
    PostOrderHelper(tree, 1);
    printf("\n");
}

void Level_order_Helper(Tree tree, int maks_level, address index, int level_sekarang){
    int level_lanjut = level_sekarang + 1;
    if(tree[index].info == '\0' || level_sekarang > maks_level){
        return;
    } else {
        printf("%c", tree[index].info);
        Level_order_Helper(tree, maks_level ,tree[index].next_brother, level_sekarang);
        Level_order_Helper(tree, maks_level ,tree[index].first_son, level_lanjut);
    }
}

void Level_order(Tree tree, int Maks_node){
    Level_order_Helper(tree, Maks_node, 1, 0);
    printf("\n");
}

void PrintTree (Tree tree){
    int index = 1;
    nbtree node = tree[index];
    while(node.info != '\0'){
        printf("--> Indeks ke-%d\n", index);
        printf("---------------------------\n");
        printf("Info array ke-%d        : %c\n", index, node.info);
        printf("First son array ke-%d   : %d\n", index, node.first_son);
        printf("next brother array ke-%d: %d\n", index, node.next_brother);
        printf("parent array ke-%d      : %d\n", index, node.parent);
        printf("---------------------------\n\n");

        index += 1;
        node = tree[index];
    }
}

boolean SearchHelper(Tree tree, infotype X, address index){
    if (tree[index].info == X){
        return true;
    }
    if (tree[index].info == '\0'){
        return false;
    } else {

        if(SearchHelper(tree, X, tree[index].first_son) == false){
            if(SearchHelper(tree, X, tree[index].next_brother) == false){
                return false;
            }
        }
        return true;
    }
}

boolean Search (Tree tree, infotype X){
    return SearchHelper(tree, X, 1);
}

int nbElmtHelper(Tree tree, address index){
    int anak, saudara;
    if(tree[index].info == '\0'){
        return 0;
    } else {
        anak = nbElmtHelper(tree, tree[index].first_son);
        saudara = nbElmtHelper (tree, tree[index].next_brother);
        return 1 + anak + saudara;
    }
}

int nbElmt (Tree tree){
    return nbElmtHelper(tree, 1);
}

int nbDaunHelper(Tree tree, address index){
    if(tree[index].info == '\0'){
        return 0;
    } else {
        if (tree[index].first_son == 0){
            return 1 + nbDaunHelper(tree, tree[index].next_brother);
        } else {
            return nbDaunHelper(tree, tree[index].first_son) + nbDaunHelper(tree, tree[index].next_brother);
        }
    }
}

int nbDaun (Tree tree){
    return nbDaunHelper(tree, 1);
}

int levelHelper(Tree tree, infotype X,address index, int level_sekarang){
    int level_lanjut = level_sekarang + 1;
    if(tree[index].info == '\0'){
        return -1;
    } else {
        if (tree[index].info == X){
            return level_sekarang;
        } else {
            return MaxInt(levelHelper(tree , X,tree[index].first_son, level_lanjut), levelHelper(tree , X, tree[index].next_brother, level_sekarang));
        }   
        
    }
}

int Level (Tree tree, infotype X){
    return levelHelper(tree, X, 1, 0);
}

int Max (infotype Data1, infotype Data2){
    if ( Data1 > Data2){
        return Data1;
    } 
    return Data2;
}

int MaxInt(int data1, int data2) {
    if ( data1 > data2){
        return data1;
    } 
    return data2;
}


int DepthHelper(Tree tree, address index, int level_sekarang){
    int level_lanjut = level_sekarang + 1;
    if(tree[index].info == '\0'){
        return level_sekarang;
    } else {
        return MaxInt(DepthHelper(tree,tree[index].next_brother, level_sekarang), DepthHelper(tree,tree[index].first_son, level_lanjut));
    }
}   


int Depth (Tree tree){
    if(IsEmpty(tree)){
        return 0;
    } else {
        return DepthHelper(tree, 1, 0);
    }
}