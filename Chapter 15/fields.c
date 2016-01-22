#include <stdio.h>
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

void showsettings(const struct box_props * pb);

int main(void)
{
	struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};
	puts("Original box settings:");
	showsettings(&box);

	box.opaque = NO;
	box.fill_color  = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	
	puts("Modified box settings:");
	showsettings(&box);
	
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
