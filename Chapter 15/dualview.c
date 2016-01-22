#include <stdio.h>
/* BIT-FIELD CONSTANTS */
/* opaque and show */
#define YES 1
#define NO 0
/* border color */ 
#define SOLID 0
#define DOTTED 1
#define DASHED 2
/* original color */
#define RED 1
#define GREEN 2
#define BLUE 4
/* mixed color */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

/*BITWISE CONSTANTS */
#define OPAQUE 0x1
#define FILL_RED    0x2
#define FILL_GREEN  0x4
#define FILL_BLUE   0x8
#define FILL_MASK   0xE
#define BORDER      0x100
#define BORDER_RED  0x200
#define BORDER_GREEN 0x400
#define BOREDER_BLUE 0x800
#define BORDER_MASK 0xE00
#define B_SOLID     0
#define B_DOTTED    0x1000
#define B_DASHED    0x2000
#define STYLE_MASK  0x3000

const char * color[8] = {"black", "red", "green", "yellow", "blue", "magneta", "cyan", "white"};

struct box_props {
	unsigned int opaque       : 1;
	unsigned int fill_color   : 3;
	unsigned int              : 4;
	unsigned int show_border  : 1;
	unsigned int border_color : 3;
	unsigned int border_style : 2;
	unsigned int              : 2;
};

union Views {
	struct box_props st_view;
	unsigned int ui_view;
};

void showsettings(const struct box_props * pb);
void showsettings1(unsigned short us);
char * itobs(unsigned int n, char * ps);


int main(void)
{
	union Views box = {{YES, YELLOW, YES, GREEN, DASHED}};
	char bin_str[8 * sizeof(int) + 1];
	
	puts("Original box settings:");
	showsettings(&box.st_view);
	showsettings1(box.ui_view);
	printf("bits are %s\n",itobs(box.ui_view, bin_str));
    
    box.ui_view &= ~FILL_MASK;
    box.ui_view |= (FILL_BLUE | FILL_GREEN);
    box.ui_view ^= OPAQUE;
    box.ui_view &= ~BORDER_MASK;
    box.ui_view |= BORDER_RED;
    box.ui_view &= ~STYLE_MASK;
    box.ui_view |= B_DOTTED;
    putchar('\n');
	puts("Modified box settings:");
	showsettings(&box.st_view);
	showsettings1(box.ui_view);
	printf("bits are %s\n",itobs(box.ui_view, bin_str));
	
	return 0;
}

void showsettings(const struct box_props * pb)
{
	printf("Box is %s.\n", pb->opaque == YES? "opaque": "transparent");
	printf("The fill color is %s.\n", color[pb->fill_color]);
	printf("Border %s.\n", pb->show_border == YES? "shown": "not shown");
	printf("The border color is %s.\n", color[pb->border_color]);
	printf("The border style is ");
	switch(pb->border_style)
	{
		case SOLID    : puts("solid.");
		                break;
        case DOTTED   : puts("dotted.");
                        break;
        case DASHED   : puts("dashed.");
                        break;
        default       : puts("Unknown type.");
                        break;
	}
	putchar('\n');
}

void showsettings1(unsigned short us)
{
	printf("Box is %s.\n", (us & OPAQUE) == OPAQUE? "opague": "transparent");
	printf("The fill color is %s.\n",color[(us >> 1) & 07]);
	printf("Border %s.\n",(us & BORDER) == BORDER? "Shown": "Not shown");
	printf("The border color is %s.\n", color[(us >> 9) & 07]);
	printf("The border style is ");
	switch(us & STYLE_MASK)
	{
		case B_SOLID    : puts("solid.");
		                  break;
        case B_DOTTED   : puts("dotted.");
                          break;
        case B_DASHED   : puts("dashed.");
                          break;
        default         : puts("Unknown type.");
                          break;
	}
}

char * itobs(unsigned int n, char * ps)
{
	int i;
	static size = 8 * sizeof(int);
	for(i = size - 1; i >= 0; i--, n >>= 1)
	    ps[i] = (n & 01) + '0';
    ps[size] = '\0';
    
    return ps;
}
