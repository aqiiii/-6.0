#include <stdio.h>
#define N 30
#define G 6
int InputList();                                //输入函数
int Menu();                                     //菜单函数
int Seek();                                     //查找函数
int Rank();                                     //排名函数
int Analyse();                                  //成绩分析函数
int Output();                                   //输出函数
int Line();                                     //读取行数的函数
int Ave (int score[],int n);					//平均分函数 
int Sort (int score[],int num[],int n);			//分数排序 
int Resort (int score[],int num[],int n);		//分数反向排序 
int Numsort (int score[],int num[],int n);		//学号排序函数 
int Statistic ();	                            //统计函数 
int Swap(int *x,int *y);    					//交换函数 

typedef struct Student{                         //学生结构体
    char name[20];
    int num;
    float score[6];

}STU;

int main(){
    int t;
    int g=0;
    do{
        t=0;
        switch(Menu()){
            case 1:
                {
                    t=InputList(g);
                    break;
                }
            case 2:
                {
                    Statistic();
                    t=1;
                    break;
                }
            case 3:
                {
                    t=0;
                    Seek();
                    break;
                }
            case 4:
                {
                    t=0;
                    Rank();
                    break;
                }
            case 5:
                {
                    t=0;
                    Analyse();
                    break;
                }
            case 6:
                {
                    t=0;
                    Output();
                    break;
                }
            case 0:
                {
                    t=0;
                    break;
                }
            default:t=1; 
        } 

    }while(t);

    return 0;
}
int Menu(){
    int choice;
    printf("\t\t\t欢迎来到学生成绩管理系统！！\n");
    printf("\t1，输入学号和成绩\t\t\t");
    printf("\t2，成绩统计\t\t\n");
    printf("\t3，查询成绩\t\t\t\t");
    printf("\t4，成绩排名\t\t\n");
    printf("\t5，课程分析\t\t\t\t");
    printf("\t6，输出列表\t\t\n");
    printf("\t0，退出\n");
    printf("\n请输入选项：");
    scanf("%d",&choice);
    return choice;
}
int InputList(int g){
    int n,i,j;
    if(g==0)
    {
        printf("请输入学科数：");
        scanf("%d",&g);
    }
    printf("请输入学生人数：");
    scanf("%d",&n);
    if(n+Line()<=N)
        printf("学生人数已经超出三十人");
    else{
        STU stu[N];
        for(i=0;i<n;i++)
        {
            printf("请输入第%d个人的姓名:",i+1);
            scanf("%s",stu[i].name);
            printf("请输入学号:");
            scanf("%d",&stu[i].num);
            for(j=0;j<g;j++)
            {
                printf("请输入第%d科成绩",j+1);
                scanf("%f",&stu[i].score[j]);

            }
        }
        FILE *fp=fopen("file.txt","a");
        if(fp==NULL)
        {
            printf("打开文件失败！");
        }
        for(i=0;i<n;i++)
        {
            fprintf(fp,"%s\t%d",stu[i].name,stu[i].num);
            for(j=0;j<g;j++)
            {
                fprintf(fp,"\t%f",stu[i].score[j]);

            }
            fprintf(fp,"\n");
        }
        fclose(fp);
        printf("成绩录入成功！");
    } 
    return 1;
}
int Statistic(){

}
int Seek(){

}
int Rank(){

}
int Analyse(){

}
int Output(){
    int i,j,g=3;
    STU stu[N];
    FILE *fp = fopen("file.txt","r");
    int n;
    n = Line();
    if(fp == NULL){
        printf("打开文件失败！");
    }
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s\t%d",stu[i].name,&stu[i].num);
        printf("%s\t%d",stu[i].name,stu[i].num);
        for(j=0;j<g;j++)
        {
            fscanf(fp,"\t%f",&stu[i].score[j]);
            printf("\t%f",stu[i].score[j]);
        }
        printf("\n");
    }
        fclose(fp);
}
int Line()
{
    int c;
    int lines=0;
    FILE *fp=fopen("flie.txt", "r");
    if(fp)
    {
        while((c=fgetc(fp)) != EOF)
            if(c=='\n') lines++;
    }
    fclose(fp);

    return lines;
}
