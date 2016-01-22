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

void show(struct citizen info);

int main(void)
{
	int index;
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
	
	for(index = 0; index < 5; index++)
	    show(info[index]);
    
	return 0;
}

void show(struct citizen info)
{
	int index;
	if(info.handle.mname[0] == '\0')
	    printf("%s, %s -- %lld\n",info.handle.lname,info.handle.fname,
                info.number);
   else
        printf("%s %s %c. -- %lld\n",info.handle.lname,info.handle.fname,
	            info.handle.mname[0],info.number);
}
