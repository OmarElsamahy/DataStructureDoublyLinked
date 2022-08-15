#include <stdio.h>
#include <string.h>
// Omar Mahmoud Elsamahy
// 18102063
// 7th Project
struct Node{
int playerID;
char playerName[30];
double playerScore;

Node *next;
Node *prev;
};
void addPlayer(Node *&head,int id,char name[50],double score)
{
    Node *temp=new Node();
    temp->playerID=id;
    temp->playerScore=score;
    strcpy(temp->playerName,name);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
        return;
    }

}
void updateScore(Node *&playerList,int id)
{
    bool found=false;
    double score;
    if(playerList==NULL)
    {
        printf("No Users");
        return;
    }
    Node *p=playerList;
    while(p!=NULL)
    {
        if(p->playerID==id)
        {
            found=true;
            printf("\nEnter Score : ");
            scanf("%lf",&score);
            p->playerScore=score;
            return;
        }
        else
            p=p->next;
    }
    if (found==false)
    {
        printf("\nUser Not Found\n");
    }

}

void findMax(Node *& playerList)
{
    double maxScore;
    int maxId;
    char name[50];
    Node *p=playerList;

    if(p==NULL)
    {
        printf("\nNO Players Found\n");
        return ;
    }
    else
    {
        maxScore = p->playerScore;
        maxId = p->playerID;
        strcpy(name,p->playerName);
        while(p!=NULL)
        {
            if(p->playerScore > maxScore)
            {
                maxScore=p->playerScore;
                maxId=p->playerID;
                strcpy(name,p->playerName);
            }
            p=p->next;
        }
        printf("\nPlayer With Highest Score Is %s and his score is %lf\n",name,maxScore);
    }
}

void display(Node *head){
	if(head == NULL){
		printf("Empty Linked List");
		return;
	}

	Node *p = head;
	while(p != NULL){
		printf("\nPlayer Id Is %d\t",p->playerID);
		printf("\tPlayer Name Is %s\t",p->playerName);
		printf("\tPlayer Score Is %lf\n",p->playerScore);
		p=p->next;
	}
}

void removePlayer(Node *&head,int id)
{
    Node *p=head;
    bool found=0;
    if(head==NULL)
    {
        printf("\n\nNo players found\n\n");
        return;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->playerID==id)
               {
                   found=1;
                   if(p==head)
                   {
                       head=head->next;
                       delete p;
                       return;
                   }
                   else if(p->next==NULL)
                   {
                       p->prev->next=NULL;
                       delete p;
                       return;
                   }
                   else
                   {
                    p->next->prev=p->prev;
                    p->prev->next=p->next;
                    delete p;
                    return;
                   }
               }

             p=p->next;
        }
    }
    if (found==false)
    {
        printf("\nUser Not Found No Deletion Occurred\n");
    }
}

void getAvg(Node *& head)
{
    double sum=0,avg,counter=0;
    Node *p=head;
    if(p==NULL)
    {
        printf("\nNo Users\n");
        return;
    }
    else
    {
        while(p!=NULL)
        {
            counter++;
            sum+=p->playerScore;
            p=p->next;
        }
        avg=sum/counter;
        printf("\nAverage Score Is %lf\n",avg);
    }
}








void swap(Node *p, Node *q)
{
    int temp = p->playerID;
    p->playerID = q->playerID;
    q->playerID = temp;
    double score=p->playerScore;
    p->playerScore=q->playerScore;
    q->playerScore=score;
    char name[50];
    strcpy(name,p->playerName);
    strcpy(p->playerName,q->playerName);
    strcpy(q->playerName,name);
}

void bubbleSort(struct Node *head)
{
    int swapped, i;
    struct Node *p;
    struct Node *q = NULL;


    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        p = head;

        while (p->next != q)
        {
            if (p->playerScore > p->next->playerScore)
            {
                swap(p, p->next);
                swapped = 1;
            }
            p = p->next;
        }
        q = p;
    }
    while (swapped);
}
void MainMenu()
{
    printf("============MAIN MENU=============");
        printf("\n\nEnter 1 To Start New Game\n");
        printf("Enter 2 To Add New Player\n");
        printf("Enter 3 To Update a Player's Score\n");
        printf("Enter 4 To Print Top Scorer Name\n");
        printf("Enter 5 To Remove Player\n");
        printf("Enter 6 To Print Sorted Scorers Data\n");
        printf("Enter 7 To Calculate Average Score \n");
        printf("Enter 8 To End Game\n");
}
void startNewGame(Node *&head)
{
    head=NULL;
}
int main()
{
    Node *head;
    while(true)
    {
        MainMenu();
        int i;
        scanf("%d",&i);
        if(i==1)
        {
            printf("\n\n ====You Chose To Start A New Game====\n\n");
            startNewGame(head);
        }
        else if(i==2)
        {
            printf("\nYou Chose To Add A new Player\n");
            printf("\nEnter Name : ");
            char name[50];
            scanf("%s",&name);
            printf("\nEnter ID : ");
            int id;
            scanf("%d",&id);
            printf("\nEnter Score : ");
            double score;
            scanf("%lf",&score);
            addPlayer(head,id,name,score);
        }
        else if(i==3)
        {
            printf("\nYou Chose to Edit A Player's Score\n");
            printf("\nEnter Player's Id : ");
            int id;
            scanf("%d",&id);
            updateScore(head,id);
        }
        else if(i==4)
        {
            printf("\nYou Chose To Get Highest Scorer's Name");
            findMax(head);
        }
        else if(i==5)
        {
            printf("\nYou Chose To Delete A Player\n");
            printf("\nEnter ID you Wish To Delete : ");
            int id;
            scanf("%d",&id);
            removePlayer(head,id);
        }
        else if(i==6)
        {
            printf("\nYou Chose to Print All Data Sorted\n");
            bubbleSort(head);
            display(head);
        }
        else if(i==7)
        {
            printf("\nYou Chose To Print Average Score\n");
            getAvg(head);
        }
        else if(i==8)
            break;
        else printf("\n\nWrong Input\n\n");
    }

    return 0;
}
