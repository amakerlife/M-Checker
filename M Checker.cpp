#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#define ll long long
#define ull unsigned long long
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
inline ll lread()
{
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int n,tim,ac=0,wa=0,tle=0,a[10001],b[10001];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	system("title 对拍 By Makerlife");
	system("title 对拍 By Makerlife 运行状态:正在收集信息");
	cout<<"请输入测试数据组数: ";
	n=read();
	cout<<"请输入时间限制(ms): ";
	tim=read();
	double stsum=clock();
	for(int i=1;i<=n;i++)
	{
		system("cls");
		system("color 09");
		cout<<"正在测试 "<<i<<"/"<<n<<" 测试点"<<endl;
//		system("title 对拍 By Makerlife 已完成");
		cout<<"测试点生成中 ...... ";
		double st1=clock();
		system("rand.exe > _in.txt");
//		system("rand.exe");
		double ed1=clock();
		cout<<"(用时 "<<ed1-st1<<" ms)"<<endl;
		char cmd[1145];
		int var=(i*4-3)*100/(4*n);
		sprintf(cmd, "title 对拍 By Makerlife 已完成 %d %s", var,"%");
		system(cmd);
//		system("title 对拍 By Makerlife 运行状态:正在运行程序 my.exe");
		cout<<"正在运行程序 my.exe ...... ";
		double st=clock();
		system("my.exe < _in.txt > _myout.txt");
//		system("my.exe");
		double ed=clock();
		cout<<"(用时 "<<ed-st<<" ms)"<<endl;
		var=(i*4-2)*100/(4*n);
		sprintf(cmd, "title 对拍 By Makerlife 已完成 %d %s", var,"%");
		system(cmd);
//		system("title 对拍 By Makerlife 运行状态:正在运行程序 std.exe");
		cout<<"正在运行程序 std.exe ...... ";
		st1=clock();
		system("std.exe < _in.txt > _stdout.txt");
//		system("std.exe");
		ed1=clock();
		cout<<"(用时 "<<ed1-st1<<" ms)"<<endl;
		var=(i*4-1)*100/(4*n);
		sprintf(cmd, "title 对拍 By Makerlife 已完成 %d %s", var,"%");
		system(cmd);
//		system("title 对拍 By Makerlife 运行状态:正在比较文件");
		st1=clock();
		if(system("fc _myout.txt _stdout.txt"))
		{
			var=(i*4)*100/(4*n);
			sprintf(cmd, "title 对拍 By Makerlife 已完成 %d %s", var,"%");
			system(cmd);
			cout<<"文件比较中 ...... ";
//			system("title 对拍 By Makerlife 运行状态:正在显示测试点信息");
			system("color 04");
			cout<<"Wrong Answer"<<endl;
			wa++;
			a[i]=2;
			cout<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<ed-st<<" ms"<<endl;
			system("pause");
//			system("color 07");
		}
		else
		{
			var=(i*4)*100/(4*n);
			sprintf(cmd, "title 对拍 By Makerlife 已完成 %d %s", var,"%");
			system(cmd);
//			cout<<"文件比较中 ...... ";
//			system("title 对拍 By Makerlife 运行状态:正在显示测试点信息");
			if(ed-st>tim)
			{
				system("color 06");
				cout<<"Time Limit Exceeded"<<endl;
				tle++;
				a[i]=3;
				cout<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<ed-st<<" ms"<<endl;
				system("pause");
//				system("color 07");
			}
			else
			{
				system("color 02");
				cout<<"Accepted! "<<endl;
				ac++;
				a[i]=1;
				cout<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<ed-st<<" ms"<<endl;
				system("TIMEOUT /T 2");
//				system("color 07");
			}
		}
//		cout<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<ed-st<<" ms"<<endl;
		b[i]=ed-st;
//		system("pause");
//		system("color 07");
	}
	system("title 对拍 By Makerlife 运行状态:正在显示测试记录");
	system("color 07");
	system("cls");
	double tac=double(ac)/n*100*1.0,twa=double(wa)/n*100*1.0,ttle=double(tle)/n*100*1.0;
	if(tac==100) system("color 02");
	if(twa==100) system("color 04");
	if(ttle==100) system("color 06");
	double edsum=clock();
	cout<<"程序总用时 "<<edsum-stsum<<" ms"<<endl;
	cout<<"测试点数量: "<<n<<" ,时间限制 "<<tim<<" ms"<<endl;
//	double tac=double(ac)/n*100*1.0,twa=double(wa)/n*100*1.0,ttle=double(tle)/n*100*1.0;
//	cout<<tac<<endl;
	cout<<"共通过 "<<ac<<" 组数据,占比 "<<tac<<"%"<<endl;
	cout<<"共错误 "<<wa<<" 组数据,占比 "<<twa<<"%"<<endl;
	cout<<"共超时 "<<tle<<" 组数据,占比 "<<ttle<<"%"<<endl;
	cout<<"记录详情: "<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1) cout<<"AC, "<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<b[i]<<" ms"<<endl;
		if(a[i]==2) cout<<"WA, "<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<b[i]<<" ms"<<endl;
		if(a[i]==3) cout<<"TLE, "<<"测试点 "<<i<<"/"<<n<<" ,用时 "<<b[i]<<" ms"<<endl;
	}
	system("pause");
	return 0;
}
