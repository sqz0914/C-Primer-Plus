#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ID_MASK 0xFF
#define SIZE_MASK 0x7F00
#define LEFT 0x00000
#define CENTER 0x08000
#define RIGHT 0x10000
#define ALIGN_MASK 0x18000
#define REGULAR 0x00000
#define BOLD 0x20000
#define ITALIC 0x40000
#define UNDERLINE 0x80000
#define STYLE_MASK 0xE0000
#define SIZE_SHIFT 8

typedef unsigned long font;

char do_menu(font * f);
char get_choice(const char * str);
void show_menu(void);
void show_font(font f);
void eatline(void);
void get_id(font * f);
void get_size(font * f);
void get_align(font * f);

int main(void)
{
	font sample = 1 | (12 << SIZE_SHIFT) | LEFT | REGULAR;
	
	while(do_menu(&sample) != 'q')
	      continue;
    puts("Bye!");
    
    return 0;
}

char do_menu(font * f)
{
	char response;
	show_font(*f);
	show_menu();
	response = get_choice("fsabiuq");
	switch(response)
	{
		case 'f' : get_id(f);
		           break;
        case 's' : get_size(f);
                   break;
        case 'a' : get_align(f);
                   break;
        case 'b' : *f ^= BOLD;
                   break;
        case 'i' : *f ^= ITALIC;
                   break;
        case 'u' : *f ^= UNDERLINE;
                   break;
        case 'q' : break;
        default  : puts("Error!\n");
	}
	
	return response;
}

char get_choice(const char * str)
{
	char ch;
	ch = tolower(getchar());
	while(strchr(str, ch) == NULL)
	{
		eatline();
		printf("Please enter the following letters: %s\n",str);
		ch = tolower(getchar());
		
	}
	eatline();
	return ch;
}

void show_menu(void)
{
	printf("f)change font    s)change size    a)change alignment\n");
	printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
	printf("q)qiut");
	putchar('\n');
}

void show_font(font f)
{
	printf("ID SIZE ALIGNMENT   B   I   U\n");
	printf("%2d%5d",f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT);
	switch(f & ALIGN_MASK)
	{
		case LEFT : printf("%8s", "left");
		            break;
		case CENTER : printf("%8s", "center");
                      break;
        case RIGHT : printf("%8s", "right");
                     break;
        default    : printf("%8s","unknown");
                     break;
	}
	printf("%7s",(f & BOLD) == BOLD? "on": "off");
	printf("%4s",(f & ITALIC) == ITALIC? "on": "off");
	printf("%4s\n",(f & UNDERLINE) == UNDERLINE? "on": "off");
	putchar('\n');
}
void eatline(void)
{
	while(getchar() != '\n')
	      continue;
}
void get_id(font * f)
{
	int id;
	puts("Enter font id (0 - 255):");
	scanf("%d", &id);
	id &= ID_MASK;
	*f &= ~ID_MASK;
	*f |= id;
	eatline();
}

void get_size(font * f)
{
	int size;
	puts("Enter font size (0 - 127):");
	scanf("%d", &size);
	*f &= ~SIZE_MASK;
	*f |= (size << SIZE_SHIFT);
	eatline();
}
void get_align(font * f)
{
	puts("Select alignment:");
    puts("l)left   c)center   r)right");
    switch(get_choice("lcr"))
    {
    	case 'l' : *f &= ~ALIGN_MASK;
    	           *f |= LEFT;
    	           break;
        case 'c' : *f &= ~ALIGN_MASK;
    	           *f |= CENTER;
    	           break;
        case 'r' : *f &= ~ALIGN_MASK;
                   *f |= RIGHT;
                   break;
        default  : puts("Error!");
                   break;
    }	
}
