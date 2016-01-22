#include <stdio.h>
#define OFF 0
#define ON 1
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define ID_MASK 0xFF;
#define SIZE_MASK 0x7F;

struct design {
	unsigned int font_id   : 8;
	unsigned int           : 8;
	unsigned int font_size : 7;
	unsigned int           : 4;
	unsigned int align     : 2;
	unsigned int bold      : 1;
	unsigned int italic    : 1;
	unsigned int underline : 1;
};

enum {l,c,r};

const char * status[2] = {"off","on"};
void showmenu(void);
void showmenu2(void);
void showsettings(struct design * ps);
int getlet(char * s);
void eatline(void);

int main(void)
{
	char choice;
	int ans;
	struct design font = {1, 12, LEFT, OFF, OFF, OFF};
	showsettings(&font);
	showmenu();
	while((choice = getlet("fsabiuq")) != 'q')
	{
		switch(choice)
		{
			case 'f' : puts("Enter font ID (0 - 255):");
			           scanf("%d", &ans);
			           eatline();
			           font.font_id = ans & ID_MASK;
			           break;
            case 's' : puts("Enter font ID (0 - 127)");
                       scanf("%d", &ans);
                       eatline();
                       font.font_size = ans & SIZE_MASK;
                       break;
            case 'a' : puts("Select alignment:");
                       showmenu2();
                       ans = getlet("lcr");
                       font.align = ans;
                       break;
            case 'b' : font.bold ^= 01;
                       break;
            case 'i' : font.italic ^= 01;
                       break;
            case 'u' : font.underline ^= 01;
                       break;
            default  : puts("Input Error!");
                       break;
		}
		putchar('\n');
		showsettings(&font);
		putchar('\n');
		showmenu();
	}
	puts("Bye!");
	
	return 0;
}

void showmenu(void)
{
	printf("f)change font    s)change size    a)change alignment\n");
	printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
	printf("q)qiut");
	putchar('\n');
}

void showmenu2(void)
{
	printf("l)left  c)center  r)rignt\n");
}

void showsettings(struct design * ps)
{
	printf("ID SIZE ALIGNMENT   B   I   U\n");
	printf("%2d%5d",ps->font_id, ps->font_size);
	switch(ps->align)
	{
		case LEFT : printf("%8s", "left");
		            break;
		case CENTER : printf("%8s", "center");
                      break;
        case RIGHT : printf("%8s", "right");
                     break;
        default    : printf("%8s","Error");
                     break;
	}
	printf("%7s",status[ps->bold]);
	printf("%4s",status[ps->italic]);
	printf("%4s",status[ps->underline]);
	putchar('\n');
}
int getlet(char * s)
{
	int c;
	c = getchar();
	eatline();
	while(strchr(s, c) == NULL)
	{
        printf("Enter a letter in \"%s\"\n",s);
        c = getchar();
        eatline();
	}
    
    return c;
}

void eatline(void)
{
	while(getchar() != '\n')
	      continue;
} 
