#include "screen.h"
#include <stdint.h> //include it to get int16_t and some integer types

enum vga_color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

uint16_t make_vgaentry(char c, uint8_t color)
{
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

int strlen(const char* str);
int strlen(const char* str)
{
	int ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}

void clear_screen();
void clear_screen() {
    char *vga_addr = (char*) 0xB8000;
    vga_addr[0] = 'x';
    vga_addr[1] = 0x23;
}

void printf(const* str, int x, int y);
void printf(const* str, int x, int y) {
    char* vga_pointer = (char*) VIDEO_ADDRESS;
    for (int i = 0; i < strlen(str); i++) {
        vga_pointer[(y * MAX_ROWS + x) + i] = str[i];
        vga_pointer[(y * MAX_ROWS + x) + i + 1] = 0x36;
    }
}