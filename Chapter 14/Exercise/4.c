#include<stdio.h>

struct name {
	char fname[20];
	char mname[20];
	char lname[20];
};

struct citizen {
	long long number;
	struct name handle;
};

void show(struct citizen info[]);

int main(void)
{
	struct citizen info[5] = {
		{
			302039823,
			{"Flossie","Missle","Dribble"}
		},
		{
			302039824,
			{"Shen","Qi","Zhuo"}
		},
		{
			302039825,
			{"Chen","Jia","Kang"}
		},
		{
			302039826,
			{"Sun","Yue","Fan"}
		},
		{
			302039827,
			{"Xia","","Lei"}
		}
	};
	
	show(info);
	
	return 0;
}

void show(struct citizen info[])
{
	int index;
	for(index = 0; index < 5; index++)
	{
		if(info[index].handle.mname[0] == '\0')
			printf("%s, %s -- %lld\n",info[index].handle.lname,info[index].handle.fname,
			       info[index].number);
        else
            printf("%s %s %c. -- %lld\n",info[index].handle.lname,info[index].handle.fname,
			       info[index].handle.mname[0],info[index].number);
	}
}
