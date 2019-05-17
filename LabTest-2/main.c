/*
NAME: NAMAN DEEP SRIVASTAVA
ID: 2016B4A70891P
*/

#include "node.h"
#include <stdio.h>
#include <stdlib.h>
extern NODE * root;
//create_node function crates a new node.
NODE* create_node(char temp)
{
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->c = temp;
    new->child = NULL;
    new->sibling = NULL;
    new->stop_word = FALSE;
    return new;
}
//Function printList takes the pointer to NODE and prints all its siblings.
void printlist(NODE *head)
{
    NODE *temp = head;
    while(temp != NULL)
    {
        printf("%c  ", temp->c);
        temp = temp->sibling;
    }
}

int main()
{
    char *words[] = {"BAD","BADGE","BED","BEDROCK","COMFORT","CONFIRM","CONFORM","CORN","CORNER","DAM","DAMAGE","DAMN","DEN","FULL","MAN","MEN","MENTOR"};
    root = (NODE*) malloc (sizeof (NODE));
    root -> c = '\0';
    root -> child = NULL;
    root ->sibling = NULL;
    root -> stop_word = FALSE;


   /* CODE BELOW CREATES TRIE WITH FIRST 9 WORDS OF array "words" ARRAY. YOU CAN USE IT AS PER YOUR CONVENIENCE TO TEST YOUR FUNCTIONS*/
    /*NODE *nb = create_node('B');
    root->child = nb;
    NODE *nba = create_node('A');
    nb->child = nba;
    NODE *nbad = create_node('D');
    nba->child = nbad;
    nbad->stop_word = TRUE;
    NODE *nbadg = create_node('G');
    nbad->child = nbadg;
    NODE *nbadge = create_node('E');
    nbadg->child = nbadge;
    nbadge->stop_word = TRUE;

    NODE *nbe = create_node('E');
    nba->sibling = nbe;
    NODE *nbed = create_node('D');
    nbe->child = nbed;
    nbed->stop_word = TRUE;
    NODE *nbedr = create_node('R');
    nbed->child = nbedr;
    NODE *nbedro = create_node('O');
    nbedr->child = nbedro;
    NODE *nbedroc = create_node('C');
    nbedro->child = nbedroc;
    NODE *nbedrock = create_node('K');
    nbedroc->child = nbedrock;
    nbedrock->stop_word = TRUE;

    NODE *nc = create_node('C');
    nb->sibling = nc;
    NODE *nco = create_node('O');
    nc->child = nco;
    NODE *ncom = create_node('M');
    nco->child = ncom;
    NODE *ncomf = create_node('F');
    ncom->child = ncomf;
    NODE *ncomfo = create_node('O');
    ncomf->child = ncomfo;
    NODE *ncomfor = create_node('R');
    ncomfo->child = ncomfor;
    NODE *ncomfort = create_node('T');
    ncomfor->child = ncomfort;
    ncomfort->stop_word = TRUE;

    NODE *ncon = create_node('N');
    ncom->sibling = ncon;
    NODE *nconf = create_node('F');
    ncon->child = nconf;
    NODE *nconfi = create_node('I');
    nconf->child = nconfi;
    NODE *nconfir = create_node('R');
    nconfi->child = nconfir;
    NODE *nconfirm = create_node('M');
    nconfir->child = nconfirm;
    nconfirm->stop_word = TRUE;

    NODE *nconfo = create_node('O');
    nconfi->sibling = nconfo;
    NODE *nconfor = create_node('R');
    nconfo->child = nconfor;
    NODE *nconform = create_node('M');
    nconfor->child = nconform;
    nconform->stop_word = TRUE;

    NODE *ncor = create_node('R');
    ncon->sibling = ncor;
    NODE *ncorn = create_node('N');
    ncor->child = ncorn;
    ncorn->stop_word = TRUE;
    NODE *ncorne = create_node('E');
    ncorn->child = ncorne;
    NODE *ncorner = create_node('R');
    ncorne->child = ncorner;
    ncorner->stop_word = TRUE;*/
    
    //CHECK-1
    printf("CHECK-1 :-\n");
    //"BAD","BADGE","BED","BEDROCK","COMFORT","CONFIRM","CONFORM","CORN","CORNER"
    
    insert_word("BAD");
    insert_word("BED");
    insert_word("BEDROCK");
    insert_word("CONFIRM");
    insert_word("BADGE");
    insert_word("CORNER");
    insert_word("COMFORT");
    insert_word("CORN");
    insert_word("CONFORM");
    printf("Inserted : BAD,BED,BEDROCK,CONFIRM,BADGE,CORNER,COMFORT,CORN,CONFORM\n");
    
    //Repetitions
    insert_word("CORN");
    insert_word("BADGE");
    insert_word("COMFORT");
    printf("Inserted : CORN,BADGE,COMFORT\n");
    
    printf("Tree Traversal: ");
    traverse_tree(root);
    printf("\n");
    
    //CHECK-2
    printf("\n");
    printf("CHECK-2 :-\n");
    //"DAM","DAMAGE","DAMN","DEN","FULL","MAN","MEN","MENTOR"
    
    insert_word("MENTOR");
    insert_word("MEN");
    insert_word("MAN");
    insert_word("DAM");
    insert_word("DAMAGE");
    insert_word("DAMN");
    insert_word("DEN");
    insert_word("FULL");
    
    printf("Inserted : MENTOR,MEN,MAN,DAM,DAMAGE,DAMN,DEN,FULL\n");
    
    boolean check = search_word("DAM");
    printf("DAM: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    	
    check = search_word("DAMAGE");
    printf("DAMAGE: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    check = search_word("CONFO");
    printf("CONFO: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    check = search_word("MENT");
    printf("MENT: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    check = search_word("MANT");
    printf("MANT: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    check = search_word("DENVER");
    printf("DENVER: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    check = search_word("FUL");
    printf("FUL: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    printf("Tree Traversal: ");	
    traverse_tree(root);
    printf("\n");
    
    //CHECK-3
    printf("\n");
    printf("CHECK-3 :-\n");
    
    insert_word("ZEN");
    insert_word("CAGE");
    insert_word("ZANDER");
    insert_word("WILLING");
    insert_word("WILL");
    
    printf("Inserted : ZEN,CAGE,ZANDER,WILLING,WILL\n");
    
    check = search_word("WANDERING");
    printf("WANDERING: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    check = search_word("WILLINGNESS");
    printf("WILLINGNESS: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    printf("Tree Traversal: ");	
    traverse_tree(root);
    printf("\n");
    
    //CHECK-4
    printf("\n");
    printf("CHECK-4 :-\n");
    insert_word("HOPE");
    printf("Inserted : HOPE\n");
    
    insert_word("I");
    insert_word("AM");
    insert_word("GONNA");
    insert_word("HOPEFULLY");
    insert_word("SCORE");
    insert_word("FULL");
    insert_word("IN");
    insert_word("THIS");
    insert_word("TEST");
    
    printf("Inserted : I,AM,GONNA,HOPEFULLY,SCORE,FULL,IN,THIS,TEST\n");
    
    check = search_word("HOPE");
    printf("HOPE: ");
    (check==TRUE)?printf("Its there!\n"):printf("Not in TRIE!\n");
    
    printf("Tree Traversal: ");	
    traverse_tree(root);
    printf("\n");
    
    

}
