/* Name: Bunyamin YAVUZ Number: 200254018 COM_201_HW_2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10



//struct for binarySearchTreeNode
struct binarySearchTreeNode {
    char *value;            // all void* types replaced by char*
    struct binarySearchTreeNode *leftChild;
    struct binarySearchTreeNode *rightChild;
    int cnt;

};

//root of the bst
struct binarySearchTreeNode *p_root = NULL;

//compares value of the new binarySearchTreeNode against the previous binarySearchTreeNode
int myStrcmp(char *a, char *b) {
    // string comparison instead of pointer comparison
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] == b[i]) {
                if(i + 1 == strlen(a)) {
                    return 0;
                }
            continue;
        }else if(a[i] > b[i]) {
            return 1;
        }else if(a[i] < b[i]) {
            return -1;
        }else {
            return 0;
        }
    }

}

//insertBstNodes elements into the tree
void insertBstNode(char* data, struct binarySearchTreeNode* *leafNode)
{
    int res;
    if( *leafNode == NULL ) {
        *leafNode = (struct binarySearchTreeNode*) malloc( sizeof( struct binarySearchTreeNode ) );
        (*leafNode)->value = malloc( strlen (data) +1 );     // memory for data
        strcpy ((*leafNode)->value, data);                   // copy the data
        (*leafNode)->cnt = 1;
        (*leafNode)->leftChild = NULL;
        (*leafNode)->rightChild = NULL;
        //printf(  "\nnew binarySearchTreeNode for %s" , data);
    } else {
        res = myStrcmp (data, (*leafNode)->value);

        if( res < 0) {
            insertBstNode( data, &(*leafNode)->leftChild);
        }

        else if( res > 0) {
            insertBstNode( data, &(*leafNode)->rightChild);
        }

        else {
                (*leafNode)->cnt = (*leafNode)->cnt + 1;
                //printf ("data '%s' already in tree\n", data);             // data already exists
        }

    }
}




//recursive function to print out the tree postorder
void post_order(struct binarySearchTreeNode *root)
{
    if( root != NULL ) {
        post_order(root->leftChild);
        post_order(root->rightChild);
        printf("%s %d Times\n", root->value, root->cnt);
        printf("\n------------------------------\n");
    }
}


//recursive function to print out the tree inorder
void in_order(struct binarySearchTreeNode *root)
{
    if( root != NULL ) {
        in_order(root->leftChild);
        printf("%s %d Times\n", root->value, root->cnt);
        printf("\n------------------------------\n");
        in_order(root->rightChild);
    }
}





//searches elements in the tree
void search(char* data, struct binarySearchTreeNode* leafNode)  // no need for **
{
    if(data[0] >= 97) {     // Lowercase to uppercase
        data[0] -= 32;
    }


    int res;

    if( leafNode != NULL ) {
        res = myStrcmp(data,leafNode->value);
        if( res < 0) {
                //printf("\nleft %d\n",leafNode->depth);
            search(data, leafNode->leftChild);
        }
        else if( res > 0) {
                //printf("\nright %d\n",leafNode->depth);
                search(data, leafNode->rightChild);

        }else{
            printf("\%s     Depth : %d     %d Times\n\n", leafNode->value, calculatorDepth(data),leafNode->cnt);
        }

    }
    else printf("\nNot-found(%s) not in the tree!\n",data);
    return;
}

//displays menu for user
void menu()
{
        printf("\n1-) Print Different Words\n");
        printf("2-) Print Different Words in Alphabetical Order\n");
        printf("3-) Search word\n");
       printf("4-) Exit\n");
       printf("Please choose : \n");
}



int binarySearchTreeNodeDepth(struct binarySearchTreeNode *root, char* data) {
        if(root == NULL) return -1;
        if(myStrcmp(root->value, data) == 0) {
            return 0;
        }
        if(myStrcmp(data, root->value) < 0) {
            return 1 + binarySearchTreeNodeDepth(root->leftChild, data);
        }
        else if(myStrcmp(data, root->value) > 0) {
            return 1 + binarySearchTreeNodeDepth(root->rightChild, data);
        }
    }

int calculatorDepth(char *data) {
    return binarySearchTreeNodeDepth(p_root, data);
}

char *input( void )
{
    static char line[MAXLEN+1];       // where to place data
    printf("Please enter a string : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));    // remove trailing newline
}



int main()
{
    char *filename = "Words.txt";
    FILE *fp = fopen(filename, "r");

    int selectedAction;
    char searchData[20] = "";


    if (fp == NULL)
    {
        printf("Error: Could not open file %s", filename);
        return 1;
    }

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH][20];

    while (fgets(buffer, MAX_LENGTH, fp)){
            if(buffer[0][0] >= 97){
        buffer[0][0] -= 32;
   }


            insertBstNode(buffer,  &p_root);
            //printf("%s", buffer);


    }
    printf("\n**************** BST *******************\n");


    // close the file
    fclose(fp);

    char *value;
    char option = 'b';

    while( option != '4' ) {
        //displays menu for program
        menu();

        //gets the char input to drive menu
        option = getch();           // instead of two getchar() calls

        if( option == '1') {
            post_order(p_root);
        }
        else if( option == '2' ) {
            in_order(p_root);
        }
        else if( option == '3' ) {
            value = input();
            printf("\n--------------------------\n");
            search(value, p_root);
        }

        else if( option == '4' ) {
            printf("Quitting");
        }
        else {
            printf("\nInvalid!\n");
            continue;
        }
    }
return 0;
}
