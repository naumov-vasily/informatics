#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_element* treeptr;

struct tree_element
{
    int dec;
    char bin[33];
    treeptr left;
    treeptr right;
};

treeptr new_element(int dec);
void insert_element(int dec, treeptr* first_element);
void print_ordered(treeptr head, int order_asc);
void find_number(int dec, treeptr* first_element);
void dectobin(int dec, char* bin);

int main(int argc, char** argv)
{
    //char bin[33];
    //bin[32] = '\0';
    //memset(bin, ' ', 32);
    //dectobin(12, bin);
    //puts(bin);
    treeptr head = NULL;
    for(;;)
    {
        printf("1. Add decimal number\n2. Find binary number\n3. Print all numbers\n");
        int a;
        scanf("%d", &a);
        switch(a)
        {
            case 1:
            {
                printf("Input decimal number:");
                int n;
                scanf("%d", &n);
                insert_element(n, &head);
            }
            break;
            
            case 2:
            {
                printf("Input decimal number:");
                int n;
                scanf("%d", &n);
                find_number(n, &head);
            }
            break;
            
            case 3:
                print_ordered(head, 1);
            break;
            
            default:
                puts("Incorrect input!");
            break;
        };
    }
    return 0;
}
treeptr new_element(int dec)
{
    treeptr result = (treeptr)malloc(sizeof(struct tree_element));
    memset(result->bin, ' ', 32);
    dectobin(dec, result->bin);
    result->bin[32] = '\0';
    result->left = NULL;
    result->right = NULL;
    result->dec = dec;
    return result;
}
void insert_element(int dec, treeptr* first_element)
{
    if(*first_element == NULL)
    {
        *first_element = new_element(dec);
        return;
    }
    treeptr curr = *first_element;
    int inserted = 0;
    while(!inserted)
    {
        if(dec < curr->dec)
        {
            if(curr->left == NULL)
            {
                curr->left = new_element(dec);
                inserted = 1;
            }
            else
                curr = curr->left;
        }
        else if(dec > curr->dec)
        {
            if(curr->right == NULL)
            {
                curr->right = new_element(dec);
                inserted = 1;
            }
            else
                curr = curr->right;
        }
        else
        {//такое число уже есть
            inserted = 1;
        }
    }

}
void print_ordered(treeptr head, int order_asc)
{

    if(order_asc)
    {
        if(head->left != NULL)
            print_ordered(head->left, order_asc);
        printf("%d | %s\n", head->dec, head->bin);
        if(head->right != NULL)
            print_ordered(head->right, order_asc);
    }

//     if(!order_asc)
//     {
//         if(head->right != NULL)
//             print_ordered(head->right, order_asc);
//         printf("%d -- %s\n", head->dec, head->bin);
//         if(head->left != NULL)
//             print_ordered(head->left, order_asc);
//     }
}


void dectobin(int dec, char* bin)
{
//     memset(bin, ' ', 32);
//     bin[32] = '\0';
        int dectmp = dec;

    if(dec > 0)
        bin[0] = ' ';
    else
    {
        bin[0] = '-';
        dectmp *= -1;
    }
    int counter = 1;
    do
    {
        bin[32 - counter++] = '0' + (dectmp % 2);
        dectmp /= 2;
    }while(dectmp != 0);
    
}
void find_number(int dec, treeptr* first_element)
{
 if(*first_element == NULL)
    {
        puts("The tree has no numbers!");
        return;
    }
    treeptr curr = *first_element;
    int found = 0;
 int reached_end = 0;
    while(!found && !reached_end)
    {
        if(dec < curr->dec)
        {
            if(curr->left == NULL)
            {
                reached_end = 1;
            }
            else
                curr = curr->left;
        }
        else if(dec > curr->dec)
        {
            if(curr->right == NULL)
            {
                reached_end = 1;

            }
            else
                curr = curr->right;
        }
        else
        {
            found = 1;
            printf("%d | %s\n", curr->dec, curr->bin);
        }
    }
    if(!found)
        puts("The table doesn't have this number!");
}
