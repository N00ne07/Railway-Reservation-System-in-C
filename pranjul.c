#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
struct Train
{
    char train_no[10];
    char train_name[20];
    char from[10];
    char dep_time[10];
    char to[10];
    char arr_time[10];
    int fac_fare;
    int sac_fare;
};

 struct Passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    char mob_no[11];
};
typedef struct Train Train;
typedef struct Passenger Passenger;

int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
int* get_ticket_no(char*);
void view_ticket(int);
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);
Passenger* get_passenger_details();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int book_ticket(Passenger);
int check_mob_no(char*);
int accept_ticket_no();
char* accept_train_no();
char* accept_mob_no();
void view_all_tickets(char*,int*);
COORD coordinate = {0,0}; //initialization


void gotoxy(int x, int y){ //function definition

   coordinate.X = x; coordinate.Y =  y;

   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);

}

int main()
{

    Passenger *ptr;
    int ch;
    int ticket_no;
    int result;
    add_trains();
    char *pmob_no;
    int *pticket_no;
    char *ptrain_no;
    char username[20];
    char pwd[15];
    int i;
    new:
        for(i=1;i<=30;i++)
            printf("-");
        printf("RAILWAY RESERVATION SYSTEM");
        for(i=1;i<=30;i++)
            printf("-");
        printf("\n\n\n::::::LOGIN::::::\n");
        printf("\nENTER USERNAME: ");
        scanf("%s",username);
        printf("\nENTER PASSWORD:");
        if((strcmp(username,"SHIVANG")==0)){
        for(i=0;i<=8;i++)
        {
            pwd[i]=getch();
            printf("*");
        }
        pwd[i]='\0';
        getch();
        }
        if(strcmp(username,"ANANAY")==0)
        {
            for(i=0;i<=11;i++)
        {
            pwd[i]=getch();
            printf("*");
        }
        pwd[i]='\0';
        getch();
        }
        if(strcmp(username,"AGRAJ")==0)
        {
            for(i=0;i<=7;i++)
        {
            pwd[i]=getch();
            printf("*");
        }
        pwd[i]='\0';
        getch();
        }
        printf("\n\n\n\n\tPassword Verification Under Process.please wait!....");
        ///Sleep(2000);
        if(((strcmp(username,"SHIVANG")==0)&&(strcmp(pwd,"swordedge")==0))||((strcmp(username,"ANANAY")==0)&&(strcmp(pwd,"messikachela")==0))||((strcmp(username,"AGRAJ")==0)&&(strcmp(pwd,"ambivert")==0)))
           {

           }
           else
            {

                system("cls");
                printf("\n\nIncorrect! Username or Password.");
                printf("\n\nPress any key to re-login");
                getch();
                system("cls");
                goto new;
            }
            system("cls");
            while(1)
            {
                system("cls");
                ch=enterchoice();
                if(ch==9)
                {
                    exit(0);
                }
                else
                {
                    switch(ch)
                    {
                    case 1:
                        view_trains();
                        system("cls");
                        break;
                    case 2:
                        ptr=get_passenger_details();
                       // printf("%c",ptr->gender);
                        if(ptr!=NULL)
                        {
                            ticket_no=book_ticket(*ptr);
                            if(ticket_no==-1)
                            {
                                printf("\n\n Booking Failed!");
                            }
                            else
                            {
                                printf("\nCongratulations! You have successfully booked a ticket");
                                printf("\nYour ticket no is");
                                printf("%d\n\n",ticket_no);
                            }
                        }
                        printf("\n Press any key to go back to the main screen ");
                        getch();
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        ticket_no=accept_ticket_no();
                        if(ticket_no!=0)
                            view_ticket(ticket_no);
                        printf("\nPress any key to go back to the main screen ");
                    getch();
                    system("cls");
                    break;
                    case 4:
                        system("cls");
                        pmob_no=accept_mob_no();
                        if(pmob_no!=NULL)
                        {
                            pticket_no=get_ticket_no(pmob_no);
                            view_all_tickets(pmob_no,pticket_no);
                        }
                        printf("\nPress any key to go back to the main screen");
                        getch();
                        system("cls");
                        break;
                    case 5:
                        system("cls");
                        view_all_bookings();
                        printf("\nPress any key to go back to the main screen");
                        getch();
                        system("cls");
                        break;
                    case 6:
                        system("cls");
                        ptrain_no=accept_train_no();
                        if(ptrain_no!=NULL)
                        {
                            view_bookings(ptrain_no);
                        }
                        printf("\nPress any key to go back to the main screen");
                        getch();
                        system("cls");
                        break;
                    case 7:
                        system("cls");
                        ticket_no=accept_ticket_no();
                        if(ticket_no!=0)
                        {

                            result=cancel_ticket(ticket_no);
                            if(result==0)
                            {

                                printf("\nSorry! No Ticket booked On this Number");
                                printf("%d\n\n",ticket_no);
                            }
                            else if(result==1)
                            {
                                printf("\nTicket no");
                                printf("%d",ticket_no);
                                printf("%s\n\n",ptrain_no);
                            }
                            else if(result==1)
                            {
                                printf("\nTrain no");
                                printf("%s",ptrain_no);
                                printf("successfully cancelled!\n\n");
                            }
                        }
                        printf("\nPress any key to go back to the main screen");
                        getch();
                        system("cls");
                        break;
                    case 8:
                        system("cls");
                        ptrain_no=accept_train_no();
                        if(ptrain_no!=NULL)
                        {
                            result=cancel_train(ptrain_no);

                        if(result==0)
                        {
                            printf("\nSorry ! No train against Train no");
                            printf("%s\n\n",ptrain_no);
                        }
                        else if(result==1)
                        {
                            printf("\n Train no");
                            printf("%s",ptrain_no);
                            printf("successfully cancelled\n\n");
                        }
                    }
                    default:
                        printf("\nWrong Choice ! Try Again");
                        getch();
                        system("cls");
                        }

                    }
                }
                getch();
                return 0;
}

int enterchoice()
{
    int choice,i;
    system("cls");
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=40;i++)
        printf("_ ");
        printf("\nSelect an Option:");
        printf("\n\n1.View Trains\n2.Book Ticket\n3.View Ticket\n4.Search Ticket No\n5.View All Bookings\n6.View Train Bookings\n7.Cancel Ticket\n8.Cancel Train\n9.Quit");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        return choice;
        getch();
}

void add_trains()
{

    FILE *fp;
    fp=fopen("addtrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[6]={{"22163","BHOPAL EXP","BPL","6:50","MUM","1:15",1500,1200},{"22164","BHOPAL EXP","MUM","16:30","BPL","22:55",1500,1200},
        {"14765","RAJDHANI EXP","DEL","3:00","KOL","14:50",4500,3000},{"14766","RAJDHANI EXP","KOL","16:00","DEL","3:50",4500,3000},
        {"22280","SHATABDI EXP","DEL","23:00","LKN","6:00",1200,1000},{"22281","SHATABDI EXP","LKN","4:00","DEL","11:00",1200,1000}};

        fwrite(alltrains,sizeof(Train),6,fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
    }
}

void view_trains()
{
    int i;
    system("cls");
    printf("\nTRAIN NO  TRAIN NAME\tFROM\t To\tDEP TIME\tARR TIME\tFIRST AC FARE\t   SECOND AC FARE \n");
    for(i=0;i<=58;i++)
        printf("_ ");
    printf("\n");
    FILE *fp=fopen("addtrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
        printf("%s\t %s\t %s\t %s\t %s\t\t %s\t\t %d\t\t\t %d \n",tr.train_no,tr.train_name,tr.from,tr.to,tr.dep_time,tr.arr_time,tr.fac_fare,tr.sac_fare);
    for(i=0;i<=58;i++)
        printf("_ ");
    printf("\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
    system("cls");
}

int check_train_no(char *trainno)
{
    FILE *fp=fopen("addtrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

Passenger* get_passenger_details()
{
    system("cls");
    gotoxy(55,1);
    printf("Press 0 to exit");
    gotoxy(1,1);
    printf("Enter passenger name:");
    static Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,22);
        printf("Reservation cancelled!");
        return NULL;
    }
    int valid;
    printf("Enter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
           gotoxy(1,22);
           printf("\t\t\t\t\t\t\t\t\t");
           gotoxy(1,22);
           printf("Resevation cancelled!");
           return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            gotoxy(1,22);
            printf("Error! Gender should be M or F (in uppercase)");
            valid=0;
            getch();
            gotoxy(19,2);
            printf("\t\t\t\t");
            gotoxy(19,2);
        }
    }while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t\t\t\t");

    gotoxy(1,3);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
        {
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reservation Cancelled!");
            return NULL;
        }
        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            gotoxy(1,22);
            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,3);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(20,3);
        }
    }while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter travelling class(First AC-F/Second AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reseravtion Cancelled!");
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            gotoxy(1,22);
            printf("Error! Travelling class should be F or S(in uppercase)");
            valid=0;
            getch();
            gotoxy(48,4);
            printf("\t\t\t\t");
            gotoxy(48,4);
        }
    }while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address:");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        gotoxy(1,22);
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,22);
        printf("Reservation Cancelled!");
        return NULL;
    }
    gotoxy(1,6);
    printf("Enter age:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reseravtion Cancelled!");
            return NULL;
        }
        if(psn.age<=0)
        {
            gotoxy(1,22);
            printf("Error! Age should be positive");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t");
            gotoxy(11,6);
        }
    }while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter Mobile Number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.mob_no);
        if(strcmp(psn.mob_no,"0")==0)
        {
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reseravtion Cancelled!");
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            gotoxy(1,22);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(21,7);
            printf("\t\t\t\t");
            gotoxy(21,7);
        }
    }while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t");
    gotoxy(1,5);
    printf("Please wait!Ticket booking is under process.");
    ///sleep(3000);
    system("cls");
    return &psn;
}


int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}
int get_booked_ticket_count(char*train_no,char c)
{
    Passenger pr;
    int count=0;
    FILE *fp=fopen("\\bookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==c)
        {
            count++;
        }
    }
        fclose(fp);
        return count;
}
int last_ticket_no()
{
    Passenger pr;
    FILE*fp=fopen("\\bookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==30)
    {
        printf("\nAll Seats full in train no. ");
        printf("%s",p.train_no);
        printf(" in ");
        printf("%c",p.p_class);
        printf(" class");
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;

    FILE*fp=fopen("\\bookings.dat","ab");
    if(fp==NULL)
    {
        printf("\nSorry!File can not be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}
int accept_ticket_no()
{
    gotoxy(55,1);
    printf("Press 0 to exit");
    gotoxy(1,1);
    printf( "ticket no:");
    int valid;
    int ticket_no;
    do
    {
        scanf("%d",&ticket_no);
        valid=1;
if(ticket_no==0)
{
gotoxy(1,22);
printf("\t\t\t\t\t");
gotoxy(1,22);
printf("Cancelling input...");
return 0;
}
if(ticket_no<0)
{
gotoxy(1,22);
printf("\t\t\t\t\t");
gotoxy(1,22);
printf("Error! Ticket number should be positive");
valid=0;
gotoxy(17,1);
printf("\t\t\t");
gotoxy(17,1);
}
}while(valid==0);
return ticket_no;
system("cls");
}

void view_ticket(int ticket_no)
{
system("cls");
FILE*fp=fopen("\\bookings.dat","rb");
FILE*fp1=fopen("\\addtrains.dat","rb");
if(fp==NULL)
{
printf("\nNo bookings done yet");
return;
}

Passenger pr;
Train tr;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
if(ticket_no==pr.ticketno)
{
printf("DETAILS OF TICKET NO:");
printf("%d\n",pr.ticketno);
printf("\nName:");
printf("%s",pr.p_name);
printf("\nGENDER");
printf("%c",pr.gender);
printf("\nTRAIN NO:");
printf("%s",pr.train_no);
printf("\nCLASS:");
printf("%c",pr.p_class);
printf("\nADDRESS:");
printf("%s",pr.address);
printf("\nAGE:");
printf("%d",pr.age);
printf("\nMOBLIE NO");
printf("%s",pr.mob_no);
printf("\nTICKET NO:");
printf("%d",pr.ticketno);
while(fread(&tr,sizeof(tr),1,fp1)==1)
{
if(strcmp(pr.train_no,tr.train_no)==0)
{
printf("\nTRAIN NAME:");
printf("%s",tr.train_name);
printf("\nFROM:");
printf("%s",tr.from);
printf("\nTO:");
printf("%s",tr.to);
printf("\nDEPARTURE TIME:");
printf("%s",tr.dep_time);
printf("\nARRIVAL TIME:");
printf("%s",tr.arr_time);
if(pr.p_class=='F')
{
printf("\nFARE:");
printf("%d",tr.fac_fare);
}
else
{
printf("\nFARE:");
printf("%d",tr.sac_fare);
}
}
}
printf("\n\n");
return;
}
}
printf("\nNo details of ticket no ");
printf("%d",ticket_no);
printf(" found!\n\n");
fclose(fp);
}
int cancel_ticket(int ticket_no)
{
FILE*fp1=fopen("\\bookings.dat","rb");
if(fp1==NULL)
{
printf("\nNo bookings done yet");
return -1;
}
FILE*fp2=fopen("\\ticket.dat","wb");
Passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp1)==1)
{
if(pr.ticketno!=ticket_no)
{
fwrite(&pr,sizeof(pr),1,fp2);
}
else
{
found=1;
}
}
fclose(fp1);
fclose(fp2);
if(found==0)
{
remove("\\ticket.dat");
}
else
{
remove("\\bookings.dat");
rename("\\ticket.dat","\\bookings.dat");
}
return found;
system("cls");
}
char* accept_mob_no()
{
static char mob_no[11];
int valid;
gotoxy(55,1);
printf("Press 0 to exit");
gotoxy(1,1);
printf("Enter Mobile number:");
do
{
fflush(stdin);
scanf("%s",mob_no);
if(strcmp(mob_no,"0")==0)
{
gotoxy(1,22);
printf("\t\t\t\t\t\t");
gotoxy(1,22);
printf("Cancelling input...!");
return NULL;
}
valid=check_mob_no(mob_no);
if(valid==0)
{
gotoxy(1,22);
printf("\t\t\t\t\t\t\t");
gotoxy(1,22);
printf("Error! Invalid Mobile no");
getch();
gotoxy(21,1);
printf("\t\t\t");
gotoxy(21,1);
}
}while(valid==0);
system("cls");
return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
int count=0;
FILE *fp;
fp=fopen("\\bookings.dat","rb");
if(fp==NULL)
{
return NULL;
}
Passenger pr;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
if(strcmp(pr.mob_no,p_mob_no)==0)
{
count++;
}
}
if(count==0)
{
fclose(fp);
return NULL;
}
rewind(fp);
int *p=(int *)malloc((count+1)*sizeof(int));
int i=0;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
if(strcmp(pr.mob_no,p_mob_no)==0)
{
*(p+i)=pr.ticketno;
i++;
}
}
*(p+i)=-1;
fclose(fp);
return p;
}
void view_all_tickets(char*pmob_no, int*pticket_no)
{
if(pticket_no==NULL)
{
printf("\nSorry! No tickets booked against moblie no. ");
printf("%s\n\n",pmob_no);
return;
}
printf("\nFollowing tickets are booked for mobile no. ");
printf("%s",pmob_no);
int i;
printf("\n\nTicket No:\n");
printf("--------------");
for(i=0;*(pticket_no+i)!=-1;i++)
{
printf("\n%d",*(pticket_no+i));
}
printf("\n\n");
free(pticket_no);
}
char* accept_train_no()
{
static char train_no[10];
int valid;
gotoxy(55,1);
printf("Press 0 to exit");
gotoxy(1,1);
printf("Enter train number:");
do
{
fflush(stdin);
scanf("%s",train_no);
if(strcmp(train_no,"0")==0);
{
gotoxy(1,22);
printf("\t\t\t\t\t\t");
gotoxy(1,22);
printf("Cancelling Input...!");
return NULL;
}
valid=check_train_no(train_no);
if(valid==0)
{
gotoxy(1,22);
printf("Error! Invalid Train No.");
getch();
gotoxy(20,1);
printf("\t\t\t\t");
gotoxy(20,1);
}
}while(valid==0);
system("cls");
return train_no;
}
void view_bookings(char *train_no)
{
int found=0;
int i;
FILE*fp=fopen("\bookings.dat","rb");
Passenger pr;
printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\t\tMOBILE NO\n");
for(i=1;i<=80;i++)
{
printf("-");
}
int row=3;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
if(strcmp(pr.train_no,train_no)==0)
{
printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
gotoxy(41,row++);
printf("%c\t%d\t\t%s\n",pr.gender,pr.age,pr.mob_no);
found=1;
}
}
for(i=1;i<=80;i++)
{
printf("-");
}
if(!found)
{
system("cls");
printf("\nNo details of train no ");
printf("%s",train_no);
printf(" found!");
}
printf("\n\n");
fclose(fp);
}
void view_all_bookings()
{
int i;
FILE*fp=fopen("\\bookings.dat","rb");
if(fp==NULL)
{
printf("\nNo bookings done yet!\n");
return;
}
Passenger pr;
printf("TRAIN NO\tTICKET NO\tCLASS\tNAME\t\tAGE\tMOBILE NO\n");
for(i=1;i<=80;i++)
{
printf("-");
}
int row=3;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
printf("%s\t\t%d\t\t%c\t%s",pr.train_no,pr.ticketno,pr.p_class,pr.p_name);
gotoxy(57,row++);
printf("%d\t%s\n",pr.age,pr.mob_no);
}
for(i=1;i<=80;i++)
{
printf("-");
}
printf("\n");
fclose(fp);
}
int cancel_train(char* train_no)
{
FILE*fp1=fopen("\\bookings.dat","rb");
if(fp1==NULL)
{
printf("\nNo Trains done yet");
return -1;
}
FILE*fp2=fopen("\\train.dat","wb+");
Passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp1)==1)
{
if(strcmp(pr.train_no,train_no))
{
fwrite(&pr,sizeof(pr),1,fp2);
}
else
{
found=1;
}
}
fclose(fp1);
fclose(fp2);
if(found==0)
{
remove("\\train.dat");
}
else
{
remove("\\bookings.dat");
rename("\\train.dat","\\bookings.dat");
}
return found;
system("cls");
}
