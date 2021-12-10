#include<stdio.h>
#include<string.h>
#define MAXSIZE 200
typedef struct card{
    long long number;
    char name[20];
    char department[20];
    long long  classnumber;
}node;
typedef struct{
    node infocard;
}recordInfo;
typedef struct{
    recordInfo r[MAXSIZE];
    int length;
}table;
void init(table *tab)
{
    tab->length=0;
}
void create(table *tab)
{
    int n;
    printf("请输入录入学生信息个数\n");
    scanf("%d",&n);
    tab->length=n;
    printf("请依次输入学生卡号、姓名、系别、班号\n");
    for(int i=1;i<=tab->length;i++)
    {
        scanf("%lld",&tab->r[i].infocard.number);
        scanf("%s",&tab->r[i].infocard.name);
        scanf("%s",&tab->r[i].infocard.department);
        scanf("%lld",&tab->r[i].infocard.classnumber);
    }
}
void display(table *tab)
{
    for(int i=1;i<=tab->length;i++)
    {
        printf("学生卡号:%lld\t姓名:%s\t系别:%s\t班号:%lld\n",tab->r[i].infocard.number,tab->r[i].infocard.name,tab->r[i].infocard.department,tab->r[i].infocard.classnumber);
    }
}
void shellinsertsort(table *tab)
{
    int i,j,d;
    d=tab->length/2;
    while(d>=1)
    {
        for(i=d+1;i<=tab->length;i++)
        {
            tab->r[0]=tab->r[i];
            j=i-d;
            while(j>0&&tab->r[0].infocard.number<tab->r[j].infocard.number)
            {
                tab->r[j+d]=tab->r[j];
                j=j-d;
            }
            tab->r[j+d]=tab->r[0];
        }
        d=d/2;
    }
}
void find(table *tab)
{
    char depart[20];
    int numb=0;
    printf("请输入所要查找系名\n");
    scanf("%s",&depart);
    for(int i=1;i<=tab->length;i++)
    {
        if(strcmp(tab->r[i].infocard.department,depart)==0)
        {
            numb++;
            printf("系名为%s的查找结果为：\n",depart);
            printf("学生卡号:%lld\t姓名:%s\t系别:%s\t班号:%lld\n",tab->r[i].infocard.number,tab->r[i].infocard.name,tab->r[i].infocard.department,tab->r[i].infocard.classnumber);
        }
    }
    if(numb==0)
        printf("未找到该系的信息\n");
}
int main() {
    table tab;
    init(&tab);
    create(&tab);
    shellinsertsort(&tab);
    display(&tab);
    find(&tab);
    return 0;
}