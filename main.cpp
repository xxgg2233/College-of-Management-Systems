#include "windows.h"
#include "iostream"
using namespace std;

struct Login{//��¼�ṹ��
	char username[10];
	char password[10];
}lg[100];

struct Message{//��ְ���ṹ��
	char teaid[10];		//ְ����
	char teaname[20];	//��ʦ��
	char teatitle[10];	//ְ��
	char sex[4];		//�Ա�
	char claname1[10];	//�γ���1
	char clatime1[10];	//����ʱ��1
	char clatype1[10];	//��������1
	int  claefc1;		//�γ�Ч��1
	char claname2[10];	//�γ���2
	char clatime2[10];	//����ʱ��2
	char clatype2[10];	//��������2
	int  claefc2;		//�γ�Ч��2
	char claname3[10];	//�γ���3
	char clatime3[10];	//����ʱ��3
	char clatype3[10];	//��������3
	int  claefc3;		//�γ�Ч��3
}me[100],temp;

int SystemLogin(char *uname,char *passwrd){  //��¼
	FILE *fp;			//�����ļ�ָ��
	int i;
	if((fp=fopen("login.txt","r"))==NULL)//ָ���ļ�����ֻ����
	{
		printf("���ļ�ʧ�ܣ�");
		return 0;
	}
	for (i=0;!feof(fp);i++)		//��ȡ�ļ���Ϣ
	{
		fscanf(fp,"%s%s",&lg[i].username,&lg[i].password);
		if(strcmp(lg[i].username,uname)==0&&strcmp(lg[i].password,passwrd)==0)
			return 1;
	}
	return 0;
}

int MainMenu(){		//�˵�
int k=0;
printf("��ӭʹ��ѧԺ��ѧ��Ϣ����ϵͳ����ѡ����Ҫִ�еĲ�����\n");
printf("		------------------------------------------------------		\n");
printf("-			1.��ʦ��ѧ��Ϣ¼��			-\n");
printf("-			2.��ʦ��ѧ��Ϣ�޸�			-\n");
printf("-			3.��ʦ��ѧ��Ϣ����			-\n");
printf("-			4.��ʦ��ѧ��Ϣ��ʾ			-\n");
printf("-			0.�˳���ѧ��Ϣ����ϵͳ			-\n");
printf("		------------------------------------------------------		\n");
scanf("%d",&k);
while(k<0||k>4){
	printf("������Ĺ��ܴ�����������Ҫִ�еĹ��ܣ�0-4��\n");
	scanf("%d",&k);
}
return k;
}

void insertMessage(){		//¼����Ϣ
	FILE *fp;
	int i,j;
	char c;
	fp=fopen("message.txt","w");		//ֻ����ʽ��
	for(i=0;i<100;i++){
		printf("�������%d����ʦ����Ϣ��\n",i+1);
		printf("ְ���ţ�");
		scanf("%s",&me[i].teaid);
		printf("������");
		scanf("%s",&me[i].teaname);
		printf("ְ�ƣ�");
		scanf("%s",&me[i].teatitle);
		printf("�Ա�");
		scanf("%s",&me[i].sex);
		printf("��һ����������Ϣ�γ�����:");
		scanf("%s",&me[i].claname1);
		printf("��һ����������Ϣ����ѧ��:");
		scanf("%s",&me[i].clatime1);
		printf("��һ�������ογ����ʣ�ѧλ���ѧλ�Σ�:");
		scanf("%s",&me[i].clatype1);
		printf("��һ�������ν�ѧЧ��(�������):");
		scanf("%d",&me[i].claefc1);
		printf("�ڶ�����������Ϣ�γ�����:");
		scanf("%s",&me[i].claname2);
		printf("�ڶ�����������Ϣ����ѧ��:");
		scanf("%s",&me[i].clatime2);
		printf("�ڶ��������ογ����ʣ�ѧλ���ѧλ�Σ�:");
		scanf("%s",&me[i].clatype2);
		printf("�ڶ��������ν�ѧЧ��(�������):");
		scanf("%d",&me[i].claefc2);
		printf("��������������Ϣ�γ�����:");
		scanf("%s",&me[i].claname3);
		printf("��������������Ϣ����ѧ��:");
		scanf("%s",&me[i].clatime3);
		printf("�����������ογ����ʣ�ѧλ���ѧλ�Σ�:");
		scanf("%s",&me[i].clatype3);
		printf("�����������ν�ѧЧ��(�������):");
		scanf("%d",&me[i].claefc3);
		getchar();
		if((i+1)%1==0){
			printf("���Ƿ���Ҫ����¼���ʦ��Ϣ����y\\Y)��");
			scanf("%c",&c);
			if(c!='y'&&c!='Y')
				break;
		}
	}
	for(j=0;j<=i;j++)	//д�뵽�ļ�elseʱ���һ�䲻����
		if(j<i)
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3);
		else
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3);
		fclose(fp);
		printf("���ݱ���ɹ���\n");
		Sleep(1000);
}

void updatemessage() {		//�޸���Ϣ
	FILE* fp;
	int i, j, k, total = 0, flag = 0;
	char id[10];
	if ((fp = fopen("message.txt", "r")) == NULL) {
		printf("���ļ�ʧ�ܣ�");
		return;
	}
	for (i = 0; !feof(fp); i++) {
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", &me[i].teaid, &me[i].teaname, &me[i].teatitle, &me[i].sex, &me[i].claname1, &me[i].clatime1, &me[i].clatype1, &me[i].claefc1, &me[i].claname2, &me[i].clatime2, &me[i].clatype2, &me[i].claefc2, &me[i].claname3, &me[i].clatime3, &me[i].clatype3, &me[i].claefc3);
		total++;
	}
	printf("��ѡ������޸ĵķ�ʽ��\n");
	printf("1.����ѡ��������Ϣ\n");
	printf("2.ɾ��ѡ��������Ϣ\n");
	printf("3.����һ����ʦ��Ϣ\n");
	printf("0.������һ��\n");
	printf("���������޸ĵķ�ʽ��(0-3)\n");
	scanf("%d", &k);
	while (k < 0 || k>3) {
		printf("������Ĺ��ܴ���������������Ҫִ�еĹ��ܣ�0-3)\n");
		scanf("%d", &k);
	}
	if(k==0){
		return;
	}
	if (k == 1) {		//������Ϣ
		printf("������Ҫ�޸Ľ�ʦ�γ���Ϣ��ְ���ţ�");
		scanf("%s", id);		//��ȡְ����
		for (i = 0; i<total; i++) {
			fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", &me[i].teaid, &me[i].teaname, &me[i].teatitle, &me[i].sex, &me[i].claname1, &me[i].clatime1, &me[i].clatype1, &me[i].claefc1, &me[i].claname2, &me[i].clatime2, &me[i].clatype2, &me[i].claefc2, &me[i].claname3, &me[i].clatime3, &me[i].clatype3, &me[i].claefc3);
			if (strcmp(me[i].teaid, id) == 0) {//�ͻ�ȡְ���ŶԱ�
				printf("ְ��:");
				scanf("%s", &me[i].teatitle);
				printf("��һ����������Ϣ�γ�����:");
				scanf("%s", &me[i].claname1);
				printf("��һ����������Ϣ����ѧ�ڣ�");
				scanf("%s", &me[i].clatime1);
				printf("��һ�������ογ����ʣ�ѧλ���ѧλ�Σ�");
				scanf("%s", &me[i].clatype1);
				printf("��һ�������ν�ѧЧ��(�������):");
				scanf("%d", &me[i].claefc1);
				printf("�ڶ�����������Ϣ�γ�����:");
				scanf("%s", &me[i].claname2);
				printf("�ڶ�����������Ϣ����ѧ�ڣ�");
				scanf("%s", &me[i].clatime2);
				printf("�ڶ��������ογ����ʣ�ѧλ���ѧλ�Σ�");
				scanf("%s", &me[i].clatype2);
				printf("�ڶ��������ν�ѧЧ��(�������):");
				scanf("%d", &me[i].claefc2);
				printf("��������������Ϣ�γ�����:");
				scanf("%s", &me[i].claname3);
				printf("��������������Ϣ����ѧ�ڣ�");
				scanf("%s", &me[i].clatime3);
				printf("�����������ογ����ʣ�ѧλ���ѧλ�Σ�");
				scanf("%s", &me[i].clatype3);
				printf("�����������ν�ѧЧ��(�������):");
				scanf("%d", &me[i].claefc3);
				printf("�����ɹ�!");
				printf("���س�������...");
				getchar();
				getchar();//�ȴ��û�����
				flag = 1;
			}
		}
		if (!flag) {
			printf("�������ְ����������������Ҫ�޸Ľ�ʦ�γ���Ϣ����ȷְ����!\n");
			fclose(fp);		//�ر��ļ�
			printf("���س�������...");
			getchar();		//�ȴ��û�����
			getchar();
			return;
		}
		fclose(fp);
		fp = fopen("message.txt", "w");	//ֻ����
		for (j = 0; j <= i - 1; j++)
			if (j != i - 1)
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", me[j].teaid, me[j].teaname, me[j].teatitle, me[j].sex, me[j].claname1, me[j].clatime1, me[j].clatype1, me[j].claefc1, me[j].claname2, me[j].clatime2, me[j].clatype2, me[j].claefc2, me[j].claname3, me[j].clatime3, me[j].clatype3, me[j].claefc3);
			else
				fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n", me[j].teaid, me[j].teaname, me[j].teatitle, me[j].sex, me[j].claname1, me[j].clatime1, me[j].clatype1, me[j].claefc1, me[j].claname2, me[j].clatime2, me[j].clatype2, me[j].claefc2, me[j].claname3, me[j].clatime3, me[j].clatype3, me[j].claefc3);
		fclose(fp);
	}
	if (k == 2) {		//ɾ����Ϣ
		printf("����������Ҫɾ���Ľ�ʦ��Ϣ��ְ����");
		scanf("%s", id);
		for (i = 0; i < total; i++) {
			if (strcmp(me[i].teaid, id) == 0) {	
				k = i;
				flag = 1;
			}
		}
		if (!flag) {
			printf("�������ְ�����������֤���������룡\n");
			Sleep(1500);
			fclose(fp);
			return;
		}
		for (j = k; j < total; j++) { //���ϸ���
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
		printf("����ɾ���ɹ�,�밴�س�����������");
		getchar();
		getchar();
	}
	if (k == 3) {		//������Ϣ
		FILE *fp;
		int i,j;
		char c;
		fp=fopen("message.txt","w");
		for(i=total;i<100;i++){
		printf("�������%d����ʦ����Ϣ��\n",total+1);
		printf("ְ���ţ�");
		scanf("%s",&me[i].teaid);
		printf("������");
		scanf("%s",&me[i].teaname);
		printf("ְ�ƣ�");
		scanf("%s",&me[i].teatitle);
		printf("�Ա�");
		scanf("%s",&me[i].sex);
		printf("��һ����������Ϣ�γ�����:");
		scanf("%s",&me[i].claname1);
		printf("��һ����������Ϣ����ѧ��:");
		scanf("%s",&me[i].clatime1);
		printf("��һ�������ογ����ʣ�ѧλ���ѧλ�Σ�:");
		scanf("%s",&me[i].clatype1);
		printf("��һ�������ν�ѧЧ��(�������):");
		scanf("%d",&me[i].claefc1);
		printf("�ڶ�����������Ϣ�γ�����:");
		scanf("%s",&me[i].claname2);
		printf("�ڶ�����������Ϣ����ѧ��:");
		scanf("%s",&me[i].clatime2);
		printf("�ڶ��������ογ����ʣ�ѧλ���ѧλ�Σ�:");
		scanf("%s",&me[i].clatype2);
		printf("�ڶ��������ν�ѧЧ��(�������):");
		scanf("%d",&me[i].claefc2);
		printf("��������������Ϣ�γ�����:");
		scanf("%s",&me[i].claname3);
		printf("��������������Ϣ����ѧ��:");
		scanf("%s",&me[i].clatime3);
		printf("�����������ογ����ʣ�ѧλ���ѧλ�Σ�:");
		scanf("%s",&me[i].clatype3);
		printf("�����������ν�ѧЧ��(�������):");
		scanf("%d",&me[i].claefc3);
		getchar();
		if((i+1)%1==0){
			printf("���Ƿ���Ҫ���������ʦ��Ϣ����y\\Y)��");
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
		printf("���ݱ���ɹ���\n");
		Sleep(1000);
	}
}


void locateMessage(){		//��ȡ��ѯ
	FILE *fp;
	int i,j,k,total=0,flag=0;
	char id[10];
	if((fp=fopen("message.txt","r"))==NULL){
		printf("���ļ�ʧ�ܣ�");
		return;
	}
	for(i=0;!feof(fp);i++){
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",&me[i].teaid,&me[i].teaname,&me[i].teatitle,&me[i].sex,&me[i].claname1,&me[i].clatime1,&me[i].clatype1,&me[i].claefc1,&me[i].claname2,&me[i].clatime2,&me[i].clatype2,&me[i].claefc2,&me[i].claname3,&me[i].clatime3,&me[i].clatype3,&me[i].claefc3);
		total++;
	}
	printf("��ѡ����Ĳ�ѯ�ķ�ʽ��\n");
	printf("1.��������γ�����ѯ\n");
	printf("2.��ʾȫ����Ϣ\n");
	printf("0.������һ��\n");
	printf("���������ѯ�ķ�ʽ��(0-2)\n");
	scanf("%d",&k);
	while(k<0||k>2){
		printf("������Ĺ��ܴ���������������Ҫִ�еĹ��ܣ�0-2��\n");
		scanf("%d",&k);
	}
	if(k==0){
		return;
	}
	if(k==1){
		printf("��������Ҫ��ѯ�Ľ�ʦ������γ�����");
		scanf("%s",id);
		printf("ְ����\t����\tְ��\t�Ա�\t����������\t����ʱ��\t�γ�����\t��ѧЧ��\t��ѧЧ���ۺ�����\n");
		for(j=0;j<total;j++){
			if(strcmp(me[j].teaname,id)==0||strcmp(me[j].claname1,id)==0||strcmp(me[j].claname2,id)==0||strcmp(me[j].claname3,id)==0){
			printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3,(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3);
				flag=1;
			} 
		}
		if(!flag){
			printf("������Ľ�ʦ����γ����������֤�����²�ѯ��\n");
		}
	}
	if(k==2){
		printf("ְ����\t����\tְ��\t�Ա�\t����������\t����ʱ��\t�γ�����\t��ѧЧ��\t��ѧЧ���ۺ�����\n");
		for(j=0;j<total;j++)
			printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3,(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3);
	}
	fclose(fp);
	printf("�밴�س�����������������");
	getchar();
	getchar();
}

void SortMessage(){		//��ʾ����
	FILE *fp;
	int i,j,k,total=0,flag=0;
	if((fp=fopen("message.txt","r"))==NULL){
		printf("���ļ�ʧ�ܣ�");
		return;
	}
	for(i=0;!feof(fp);i++){
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%d\t\n",&me[i].teaid,&me[i].teaname,&me[i].teatitle,&me[i].sex,&me[i].claname1,&me[i].clatime1,&me[i].clatype1,&me[i].claefc1,&me[i].claname2,&me[i].clatime2,&me[i].clatype2,&me[i].claefc2,&me[i].claname3,&me[i].clatime3,&me[i].clatype3,&me[i].claefc3);
		total++;
	}
	printf("��ѡ�������ʾ�ķ�ʽ��\n");
	printf("1.��ְ���Ŵ�С��������\n");
	printf("2.���ۺϽ�ѧ���ִӴ�С����\n");
	printf("0.������һ��\n");
	printf("����������������ķ�ʽ��(0-2)\n");
	scanf("%d",&k);
	while(k<0||k>2){
		printf("������Ĺ��ܴ���������������Ҫִ�еĹ��ܣ�0-2��\n");
		scanf("%d",&k);
	}
	if(k==0){
		return;
	}
		for(i=0;i<total;i++)
			for(j=0;j<total-i-1;j++)
				if(k==1?strcmp(me[j].teaid,me[j+1].teaid)>0:(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3<(me[j+1].claefc1+me[j+1].claefc2+me[j+1].claefc3)/3){
					{ //����1ʱִ��ְ���Աȣ�����������н�ѧ���ֶԱ�
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

				printf("ְ����\t����\tְ��\t�Ա�\t����������\t����ʱ��\t�γ�����\t��ѧЧ��\t��ѧЧ���ۺ�����\n");
					for(j=0;j<total;j++)
						printf("%s\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\n\t\t\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n\n",me[j].teaid,me[j].teaname,me[j].teatitle,me[j].sex,me[j].claname1,me[j].clatime1,me[j].clatype1,me[j].claefc1,me[j].claname2,me[j].clatime2,me[j].clatype2,me[j].claefc2,me[j].claname3,me[j].clatime3,me[j].clatype3,me[j].claefc3,(me[j].claefc1+me[j].claefc2+me[j].claefc3)/3);
		fclose(fp);
		printf("�밴�س�����������������");
		getchar();
		getchar();
}



int n=0;
int main(){		//������
	char un[10],pwd[10];
	int k;
	system("mode con:cols=115 lines=35");
L:	printf ("��ӭʹ��ѧԺ��ѧ��Ϣ����ϵͳ�����¼������\n");
	printf ("�û���:");
	scanf("%s",un);
	printf("����:");
	scanf("%s",pwd);
	if(SystemLogin(un,pwd)==1){
		printf("�û�����������ȷ�����ڵ�½ϵͳ������\n");
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
			printf("���Ѿ�����3��������û������������ϵͳ�����˳���\n");
			exit(0);
		}
		printf("�û������������,���������룡\n");
		Sleep(1000);
		system("cls");
		goto L;
	}
	return 0;
}
