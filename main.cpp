#include "windows.h"
#include "iostream"
using namespace std;

struct Login{//登录结构体
	char username[10];
	char password[10];
}lg[100];

struct Message{//教职工结构体
	char teaid[10];		//职工号
	char teaname[20];	//教师名
	char teatitle[10];	//职称
	char sex[4];		//性别
	char claname1[10];	//课程名1
	char clatime1[10];	//开课时间1
	char clatype1[10];	//开课性质1
	int  claefc1;		//课程效果1
	char claname2[10];	//课程名2
	char clatime2[10];	//开课时间2
	char clatype2[10];	//开课性质2
	int  claefc2;		//课程效果2
	char claname3[10];	//课程名3
	char clatime3[10];	//开课时间3
	char clatype3[10];	//开课性质3
	int  claefc3;		//课程效果3
}me[100],temp;

int SystemLogin(char *uname,char *passwrd){  //登录
	FILE *fp;			//设置文件指针
	int i;
	if((fp=fopen("login.txt","r"))==NULL)//指向文件，用只读打开
	{
		printf("打开文件失败！");
		return 0;
	}
	for (i=0;!feof(fp);i++)		//读取文件信息
	{
		fscanf(fp,"%s%s",&lg[i].username,&lg[i].password);
		if(strcmp(lg[i].username,uname)==0&&strcmp(lg[i].password,passwrd)==0)
			return 1;
	}
	return 0;
}

int MainMenu(){		//菜单
int k=0;
printf("欢迎使用学院教学信息管理系统，请选择你要执行的操作！\n");
printf("		------------------------------------------------------		\n");
printf("-			1.教师教学信息录入			-\n");
printf("-			2.教师教学信息修改			-\n");
printf("-			3.教师教学信息查找			-\n");
printf("-			4.教师教学信息显示			-\n");
printf("-			0.退出教学信息管理系统			-\n");
printf("		------------------------------------------------------		\n");
scanf("%d",&k);
while(k<0||k>4){
	printf("你输入的功能错误，请输入你要执行的功能（0-4）\n");
	scanf("%d",&k);
}
return k;
}

void insertMessage(){		//录入信息
	FILE *fp;
	int i,j;
	char c;
	fp=fopen("message.txt","w");		//只读方式打开
	for(i=0;i<100;i++){
		printf("请输入第%d个教师的信息！\n",i+1);
		printf("职工号：");
		scanf("%s",&me[i].teaid);
		printf("姓名：");
		scanf("%s",&me[i].teaname);
		printf("职称：");
		scanf("%s",&me[i].teatitle);
		printf("性别：");
		scanf("%s",&me[i].sex);
		printf("第一门主讲课信息课程名称:");
		scanf("%s",&me[i].claname1);
		printf("第一门主讲课信息开课学期:");
		scanf("%s",&me[i].clatime1);
		printf("第一门主讲课课程性质（学位与非学位课）:");
		scanf("%s",&me[i].clatype1);
		printf("第一门主讲课教学效果(输入分数):");
		scanf("%d",&me[i].claefc1);
		printf("第二门主讲课信息课程名称:");
		scanf("%s",&me[i].claname2);
		printf("第二门主讲课信息开课学期:");
		scanf("%s",&me[i].clatime2);
		printf("第二门主讲课课程性质（学位与非学位课）:");
		scanf("%s",&me[i].clatype2);
		printf("第二门主讲课教学效果(输入分数):");
		scanf("%d",&me[i].claefc2);
		printf("第三门主讲课信息课程名称:");
		scanf("%s",&me[i].claname3);
		printf("第三门主讲课信息开课学期:");
		scanf("%s",&me[i].clatime3);
		printf("第三门主讲课课程性质（学位与非学位课）:");
		scanf("%s",&me[i].clatype3);
		printf("第三门主讲课教学效果(输入分数):");
		scanf("%d",&me[i].claefc3);
		getchar();
		if((i+1)%1==0){
			printf("你是否需要继续录入教师信息！（y\\Y)：");
			scanf("%c",&c);
			if(c!='y'&&c!='Y')
				break;
		}
	}
	for(j=0;j<=i;j++)	//写入到文件else时最后一句不换行
		if(j<i)
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3);
		else
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3);
		fclose(fp);
		printf("数据保存成功！\n");
		Sleep(1000);
}

void updatemessage() {		//修改信息
	FILE* fp;
	int i, j, k, total = 0, flag = 0;
	char id[10];
	if ((fp = fopen("message.txt", "r")) == NULL) {
		printf("打开文件失败！");
		return;
	}
	for (i = 0; !feof(fp); i++) {
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", &me[i].teaid, &me[i].teaname, &me[i].teatitle, &me[i].sex, &me[i].claname1, &me[i].clatime1, &me[i].clatype1, &me[i].claefc1, &me[i].claname2, &me[i].clatime2, &me[i].clatype2, &me[i].claefc2, &me[i].claname3, &me[i].clatime3, &me[i].clatype3, &me[i].claefc3);
		total++;
	}
	printf("请选择你的修改的方式：\n");
	printf("1.更改选择的相关信息\n");
	printf("2.删除选择的相关信息\n");
	printf("3.插入一条教师信息\n");
	printf("0.返回上一级\n");
	printf("请输入你修改的方式：(0-3)\n");
	scanf("%d", &k);
	while (k < 0 || k>3) {
		printf("你输入的功能错误，请重新输入你要执行的功能（0-3)\n");
		scanf("%d", &k);
	}
	if(k==0){
		return;
	}
	if (k == 1) {		//更正信息
		printf("请输入要修改教师课程信息的职工号：");
		scanf("%s", id);		//获取职工号
		for (i = 0; i<total; i++) {
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", &me[i].teaid, &me[i].teaname, &me[i].teatitle, &me[i].sex, &me[i].claname1, &me[i].clatime1, &me[i].clatype1, &me[i].claefc1, &me[i].claname2, &me[i].clatime2, &me[i].clatype2, &me[i].claefc2, &me[i].claname3, &me[i].clatime3, &me[i].clatype3, &me[i].claefc3);
			if (strcmp(me[i].teaid, id) == 0) {//和获取职工号对比
				printf("职称:");
				scanf("%s", &me[i].teatitle);
				printf("第一门主讲课信息课程名称:");
				scanf("%s", &me[i].claname1);
				printf("第一门主讲课信息开课学期：");
				scanf("%s", &me[i].clatime1);
				printf("第一门主讲课课程性质（学位与非学位课）");
				scanf("%s", &me[i].clatype1);
				printf("第一门主讲课教学效果(输入分数):");
				scanf("%d", &me[i].claefc1);
				printf("第二门主讲课信息课程名称:");
				scanf("%s", &me[i].claname2);
				printf("第二门主讲课信息开课学期：");
				scanf("%s", &me[i].clatime2);
				printf("第二门主讲课课程性质（学位与非学位课）");
				scanf("%s", &me[i].clatype2);
				printf("第二门主讲课教学效果(输入分数):");
				scanf("%d", &me[i].claefc2);
				printf("第三门主讲课信息课程名称:");
				scanf("%s", &me[i].claname3);
				printf("第三门主讲课信息开课学期：");
				scanf("%s", &me[i].clatime3);
				printf("第三门主讲课课程性质（学位与非学位课）");
				scanf("%s", &me[i].clatype3);
				printf("第三门主讲课教学效果(输入分数):");
				scanf("%d", &me[i].claefc3);
				printf("更正成功!");
				printf("按回车键继续...");
				getchar();
				getchar();//等待用户按键
				flag = 1;
			}
		}
		if (!flag) {
			printf("你输入的职工号有误，请输入你要修改教师课程信息的正确职工号!\n");
			fclose(fp);		//关闭文件
			printf("按回车键继续...");
			getchar();		//等待用户按键
			getchar();
			return;
		}
		fclose(fp);
		fp = fopen("message.txt", "w");	//只读打开
		for (j = 0; j <= i - 1; j++)
			if (j != i - 1)
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", me[j].teaid, me[j].teaname, me[j].teatitle, me[j].sex, me[j].claname1, me[j].clatime1, me[j].clatype1, me[j].claefc1, me[j].claname2, me[j].clatime2, me[j].clatype2, me[j].claefc2, me[j].claname3, me[j].clatime3, me[j].clatype3, me[j].claefc3);
			else
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", me[j].teaid, me[j].teaname, me[j].teatitle, me[j].sex, me[j].claname1, me[j].clatime1, me[j].clatype1, me[j].claefc1, me[j].claname2, me[j].clatime2, me[j].clatype2, me[j].claefc2, me[j].claname3, me[j].clatime3, me[j].clatype3, me[j].claefc3);
		fclose(fp);
	}
	if (k == 2) {		//删除信息
		printf("请你输入你要删除的教师信息的职工号");
		scanf("%s", id);
		for (i = 0; i < total; i++) {
			if (strcmp(me[i].teaid, id) == 0) {	
				k = i;
				flag = 1;
			}
		}
		if (!flag) {
			printf("你输入的职工号有误，请查证后重新输入！\n");
			Sleep(1500);
			fclose(fp);
			return;
		}
		for (j = k; j < total; j++) { //向上覆盖
			strcpy(me[j].teaid, me[j + 1].teaid);
			strcpy(me[j].teaname, me[j + 1].teaname);
			strcpy(me[j].teatitle, me[j + 1].teatitle);
			strcpy(me[j].sex, me[j + 1].sex);
			strcpy(me[j].claname1, me[j + 1].claname1);
			strcpy(me[j].clatime1, me[j + 1].clatime1);
			strcpy(me[j].clatype1, me[j + 1].clatype1);
			strcpy(me[j].claname2, me[j + 1].claname2);
			strcpy(me[j].clatime2, me[j + 1].clatime2);
			strcpy(me[j].clatype2, me[j + 1].clatype2);
			strcpy(me[j].claname3, me[j + 1].claname3);
			strcpy(me[j].clatime3, me[j + 1].clatime3);
			strcpy(me[j].clatype3, me[j + 1].clatype3);
			me[j].claefc1 = me[j + 1].claefc1;
			me[j].claefc2 = me[j + 1].claefc2;
			me[j].claefc3 = me[j + 1].claefc3;
		}
		fclose(fp);
		fp = fopen("message.txt", "w");
		for (j = 0; j < total - 1; j++)
			if (j < total - 2)
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", me[j].teaid, me[j].teaname, me[j].teatitle, me[j].sex, me[j].claname1, me[j].clatime1, me[j].clatype1, me[j].claefc1, me[j].claname2, me[j].clatime2, me[j].clatype2, me[j].claefc2, me[j].claname3, me[j].clatime3, me[j].clatype3, me[j].claefc3);
			else
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", me[j].teaid, me[j].teaname, me[j].teatitle, me[j].sex, me[j].claname1, me[j].clatime1, me[j].clatype1, me[j].claefc1, me[j].claname2, me[j].clatime2, me[j].clatype2, me[j].claefc2, me[j].claname3, me[j].clatime3, me[j].clatype3, me[j].claefc3);
		fclose(fp);
		printf("数据删除成功,请按回车继续。。。");
		getchar();
		getchar();
	}
	if (k == 3) {		//插入信息
		FILE *fp;
		int i,j;
		char c;
		fp=fopen("message.txt","w");
		for(i=total;i<100;i++){
		printf("请输入第%d个教师的信息！\n",total+1);
		printf("职工号：");
		scanf("%s",&me[i].teaid);
		printf("姓名：");
		scanf("%s",&me[i].teaname);
		printf("职称：");
		scanf("%s",&me[i].teatitle);
		printf("性别：");
		scanf("%s",&me[i].sex);
		printf("第一门主讲课信息课程名称:");
		scanf("%s",&me[i].claname1);
		printf("第一门主讲课信息开课学期:");
		scanf("%s",&me[i].clatime1);
		printf("第一门主讲课课程性质（学位与非学位课）:");
		scanf("%s",&me[i].clatype1);
		printf("第一门主讲课教学效果(输入分数):");
		scanf("%d",&me[i].claefc1);
		printf("第二门主讲课信息课程名称:");
		scanf("%s",&me[i].claname2);
		printf("第二门主讲课信息开课学期:");
		scanf("%s",&me[i].clatime2);
		printf("第二门主讲课课程性质（学位与非学位课）:");
		scanf("%s",&me[i].clatype2);
		printf("第二门主讲课教学效果(输入分数):");
		scanf("%d",&me[i].claefc2);
		printf("第三门主讲课信息课程名称:");
		scanf("%s",&me[i].claname3);
		printf("第三门主讲课信息开课学期:");
		scanf("%s",&me[i].clatime3);
		printf("第三门主讲课课程性质（学位与非学位课）:");
		scanf("%s",&me[i].clatype3);
		printf("第三门主讲课教学效果(输入分数):");
		scanf("%d",&me[i].claefc3);
		getchar();
		if((i+1)%1==0){
			printf("你是否需要继续插入教师信息！（y\\Y)：");
			scanf("%c",&c);
			if(c!='y'&&c!='Y')
				break;
		}
	}
		for(i=0;i<total;i++)
			for(j=0;j<total-i;j++)
				if((me[j].claefc1+me[j].claefc2+me[j].claefc3)/3<(me[j+1].claefc1+me[j+1].claefc2+me[j+1].claefc3)/3){
					{ 
							strcpy(temp.teaid, me[j].teaid);
							strcpy(temp.teaname, me[j].teaname);
							strcpy(temp.teatitle, me[j].teatitle);
							strcpy(temp.sex, me[j].sex);
							strcpy(temp.claname1, me[j].claname1);
							strcpy(temp.clatime1, me[j].clatime1);
							strcpy(temp.clatype1, me[j].clatype1);
							strcpy(temp.claname2, me[j].claname2);
							strcpy(temp.clatime2, me[j].clatime2);
							strcpy(temp.clatype2, me[j].clatype2);
							strcpy(temp.claname3, me[j].claname3);
							strcpy(temp.clatime3, me[j].clatime3);
							strcpy(temp.clatype3, me[j].clatype3);
							temp.claefc1 = me[j].claefc1;
							temp.claefc2 = me[j].claefc2;
							temp.claefc3 = me[j].claefc3;
						}
						{
							strcpy(me[j].teaid, me[j + 1].teaid);
							strcpy(me[j].teaname, me[j + 1].teaname);
							strcpy(me[j].teatitle, me[j + 1].teatitle);
							strcpy(me[j].sex, me[j + 1].sex);
							strcpy(me[j].claname1, me[j + 1].claname1);
							strcpy(me[j].clatime1, me[j + 1].clatime1);
							strcpy(me[j].clatype1, me[j + 1].clatype1);
							strcpy(me[j].claname2, me[j + 1].claname2);
							strcpy(me[j].clatime2, me[j + 1].clatime2);
							strcpy(me[j].clatype2, me[j + 1].clatype2);
							strcpy(me[j].claname3, me[j + 1].claname3);
							strcpy(me[j].clatime3, me[j + 1].clatime3);
							strcpy(me[j].clatype3, me[j + 1].clatype3);
							me[j].claefc1 = me[j + 1].claefc1;
							me[j].claefc2 = me[j + 1].claefc2;
							me[j].claefc3 = me[j + 1].claefc3;
						}
						{
							strcpy(me[j+1].teaid, temp.teaid);
							strcpy(me[j+1].teaname, temp.teaname);
							strcpy(me[j+1].teatitle, temp.teatitle);
							strcpy(me[j+1].sex, temp.sex);
							strcpy(me[j+1].claname1, temp.claname1);
							strcpy(me[j+1].clatime1, temp.clatime1);
							strcpy(me[j+1].clatype1, temp.clatype1);
							strcpy(me[j+1].claname2, temp.claname2);
							strcpy(me[j+1].clatime2, temp.clatime2);
							strcpy(me[j+1].clatype2, temp.clatype2);
							strcpy(me[j+1].claname3, temp.claname3);
							strcpy(me[j+1].clatime3, temp.clatime3);
							strcpy(me[j+1].clatype3, temp.clatype3);
							me[j+1].claefc1 = temp.claefc1;
							me[j+1].claefc2 = temp.claefc2;
							me[j+1].claefc3 = temp.claefc3;
						}
				}
	for(j=0;j<=i;j++)
		if(j<i)
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3);
		else
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3);
		fclose(fp);
		printf("数据保存成功！\n");
		Sleep(1000);
	}
}


void locateMessage(){		//读取查询
	FILE *fp;
	int i,j,k,total=0,flag=0;
	char id[10];
	if((fp=fopen("message.txt","r"))==NULL){
		printf("打开文件失败！");
		return;
	}
	for(i=0;!feof(fp);i++){
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",&me[i].teaid,&me[i].teaname,&me[i].teatitle,&me[i].sex,&me[i].claname1,&me[i].clatime1,&me[i].clatype1,&me[i].claefc1,&me[i].claname2,&me[i].clatime2,&me[i].clatype2,&me[i].claefc2,&me[i].claname3,&me[i].clatime3,&me[i].clatype3,&me[i].claefc3);
		total++;
	}
	printf("请选择你的查询的方式：\n");
	printf("1.按姓名或课程名查询\n");
	printf("2.显示全部信息\n");
	printf("0.返回上一级\n");
	printf("请输入你查询的方式：(0-2)\n");
	scanf("%d",&k);
	while(k<0||k>2){
		printf("你输入的功能错误，请重新输入你要执行的功能（0-2）\n");
		scanf("%d",&k);
	}
	if(k==0){
		return;
	}
	if(k==1){
		printf("请输入你要查询的教师姓名或课程名：");
		scanf("%s",id);
		printf("职工号\t姓名\t职称\t性别\t主讲课名称\t开课时期\t课程性质\t教学效果\t教学效果综合评分\n");
		for(j=0;j<total;j++){
			if(strcmp(me[j].teaname,id)==0||strcmp(me[j].claname1,id)==0||strcmp(me[j].claname2,id)==0||strcmp(me[j].claname3,id)==0){
			printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3,(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3);
				flag=1;
			} 
		}
		if(!flag){
			printf("你输入的教师名或课程名有误，请查证后重新查询！\n");
		}
	}
	if(k==2){
		printf("职工号\t姓名\t职称\t性别\t主讲课名称\t开课时期\t课程性质\t教学效果\t教学效果综合评分\n");
		for(j=0;j<total;j++)
			printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3,(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3);
	}
	fclose(fp);
	printf("请按回车键继续。。。。。");
	getchar();
	getchar();
}

void SortMessage(){		//显示排序
	FILE *fp;
	int i,j,k,total=0,flag=0;
	if((fp=fopen("message.txt","r"))==NULL){
		printf("打开文件失败！");
		return;
	}
	for(i=0;!feof(fp);i++){
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",&me[i].teaid,&me[i].teaname,&me[i].teatitle,&me[i].sex,&me[i].claname1,&me[i].clatime1,&me[i].clatype1,&me[i].claefc1,&me[i].claname2,&me[i].clatime2,&me[i].clatype2,&me[i].claefc2,&me[i].claname3,&me[i].clatime3,&me[i].clatype3,&me[i].claefc3);
		total++;
	}
	printf("请选择你的显示的方式：\n");
	printf("1.按职工号从小到大排序\n");
	printf("2.按综合教学评分从大到小排序\n");
	printf("0.返回上一级\n");
	printf("请输入你排序输出的方式：(0-2)\n");
	scanf("%d",&k);
	while(k<0||k>2){
		printf("你输入的功能错误，请重新输入你要执行的功能（0-2）\n");
		scanf("%d",&k);
	}
	if(k==0){
		return;
	}
		for(i=0;i<total;i++)
			for(j=0;j<total-i-1;j++)
				if(k==1?strcmp(me[j].teaid,me[j+1].teaid)>0:(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3<(me[j+1].claefc1+me[j+1].claefc2+me[j+1].claefc3)/3){
					{ //等于1时执行职工对比，若不是则进行教学评分对比
							strcpy(temp.teaid, me[j].teaid);
							strcpy(temp.teaname, me[j].teaname);
							strcpy(temp.teatitle, me[j].teatitle);
							strcpy(temp.sex, me[j].sex);
							strcpy(temp.claname1, me[j].claname1);
							strcpy(temp.clatime1, me[j].clatime1);
							strcpy(temp.clatype1, me[j].clatype1);
							strcpy(temp.claname2, me[j].claname2);
							strcpy(temp.clatime2, me[j].clatime2);
							strcpy(temp.clatype2, me[j].clatype2);
							strcpy(temp.claname3, me[j].claname3);
							strcpy(temp.clatime3, me[j].clatime3);
							strcpy(temp.clatype3, me[j].clatype3);
							temp.claefc1 = me[j].claefc1;
							temp.claefc2 = me[j].claefc2;
							temp.claefc3 = me[j].claefc3;
						}
						{
							strcpy(me[j].teaid, me[j + 1].teaid);
							strcpy(me[j].teaname, me[j + 1].teaname);
							strcpy(me[j].teatitle, me[j + 1].teatitle);
							strcpy(me[j].sex, me[j + 1].sex);
							strcpy(me[j].claname1, me[j + 1].claname1);
							strcpy(me[j].clatime1, me[j + 1].clatime1);
							strcpy(me[j].clatype1, me[j + 1].clatype1);
							strcpy(me[j].claname2, me[j + 1].claname2);
							strcpy(me[j].clatime2, me[j + 1].clatime2);
							strcpy(me[j].clatype2, me[j + 1].clatype2);
							strcpy(me[j].claname3, me[j + 1].claname3);
							strcpy(me[j].clatime3, me[j + 1].clatime3);
							strcpy(me[j].clatype3, me[j + 1].clatype3);
							me[j].claefc1 = me[j + 1].claefc1;
							me[j].claefc2 = me[j + 1].claefc2;
							me[j].claefc3 = me[j + 1].claefc3;
						}
						{
							strcpy(me[j+1].teaid, temp.teaid);
							strcpy(me[j+1].teaname, temp.teaname);
							strcpy(me[j+1].teatitle, temp.teatitle);
							strcpy(me[j+1].sex, temp.sex);
							strcpy(me[j+1].claname1, temp.claname1);
							strcpy(me[j+1].clatime1, temp.clatime1);
							strcpy(me[j+1].clatype1, temp.clatype1);
							strcpy(me[j+1].claname2, temp.claname2);
							strcpy(me[j+1].clatime2, temp.clatime2);
							strcpy(me[j+1].clatype2, temp.clatype2);
							strcpy(me[j+1].claname3, temp.claname3);
							strcpy(me[j+1].clatime3, temp.clatime3);
							strcpy(me[j+1].clatype3, temp.clatype3);
							me[j+1].claefc1 = temp.claefc1;
							me[j+1].claefc2 = temp.claefc2;
							me[j+1].claefc3 = temp.claefc3;
						}
				}

				printf("职工号\t姓名\t职称\t性别\t主讲课名称\t开课时期\t课程性质\t教学效果\t教学效果综合评分\n");
					for(j=0;j<total;j++)
						printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3,(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3);
		fclose(fp);
		printf("请按回车键继续。。。。。");
		getchar();
		getchar();
}



int n=0;
int main(){		//主函数
	char un[10],pwd[10];
	int k;
	system("mode con:cols=115 lines=35");
L:	printf ("欢迎使用学院教学信息管理系统，请登录。。。\n");
	printf ("用户名:");
	scanf("%s",un);
	printf("密码:");
	scanf("%s",pwd);
	if(SystemLogin(un,pwd)==1){
		printf("用户名和密码正确，正在登陆系统。。。\n");
		Sleep(1000);
		system("cls");
		k=MainMenu();
		while (1){
			if(k==0)
				exit (0);
			switch (k){
				case 1:insertMessage(); break;
				case 2:updatemessage(); break;
				case 3:locateMessage(); break;
				case 4:SortMessage();   break;
			}
			Sleep(1000);
			system("cls");
			k=MainMenu();
		}
	}
	else{
		n++;
		if(n==3){
			printf("你已经连续3次输入的用户名和密码错误，系统将会退出！\n");
			exit(0);
		}
		printf("用户名或密码错误,请重新输入！\n");
		Sleep(1000);
		system("cls");
		goto L;
	}
	return 0;
}
