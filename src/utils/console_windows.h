#pragma once
#ifndef BASE4CONSOLEGAMES_HPP
#define BASE4CONSOLEGAMES_HPP

/*
Table showing how ASCII characters are drawn on the screen

0 |     32 |    64 | @  96 | `  128 | Ç 160 | á 192 | └ 224 | Ó
1 | ☺   33 | !  65 | A  97 | a  129 | ü 161 | í 193 | ┴ 225 | ß
2 | ☻   34 | "  66 | B  98 | b  130 | é 162 | ó 194 | ┬ 226 | Ô
3 | ♥   35 | #  67 | C  99 | c  131 | â 163 | ú 195 | ├ 227 | Ò
4 | ♦   36 | $  68 | D  100 | d 132 | ä 164 | ñ 196 | ─ 228 | õ
5 | ♣   37 | %  69 | E  101 | e 133 | à 165 | Ñ 197 | ┼ 229 | Õ
6 | ♠   38 | &  70 | F  102 | f 134 | å 166 | ª 198 | ã 230 | µ
7 | •   39 | '  71 | G  103 | g 135 | ç 167 | º 199 | Ã 231 | þ
8 | ◘   40 | (  72 | H  104 | h 136 | ê 168 | ¿ 200 | ╚ 232 | Þ
9 | ○   41 | )  73 | I  105 | i 137 | ë 169 | ® 201 | ╔ 233 | Ú
10 | ◙	42 | *  74 | J  106 | j 138 | è 170 | ¬ 202 | ╩ 234 | Û
11 | ♂  43 | +  75 | K  107 | k 139 | ï 171 | ½ 203 | ╦ 235 | Ù
12 | ♀  44 | ,  76 | L  108 | l 140 | î 172 | ¼ 204 | ╠ 236 | ý
13 | ♪	45 | -  77 | M  109 | m 141 | ì 173 | ¡ 205 | ═ 237 | Ý
14 | ♫  46 | .  78 | N  110 | n 142 | Ä 174 | « 206 | ╬ 238 | ¯
15 | ☼  47 | /  79 | O  111 | o 143 | Å 175 | » 207 | ¤ 239 | ´
16 | ►  48 | 0  80 | P  112 | p 144 | É 176 | ░ 208 | ð 240 | ­­­­­­­­­­­­­­­­­-
17 | ◄  49 | 1  81 | Q  113 | q 145 | æ 177 | ▒ 209 | Ð 241 | ±
18 | ↕  50 | 2  82 | R  114 | r 146 | Æ 178 | ▓ 210 | Ê 242 | ‗
19 | ‼  51 | 3  83 | S  115 | s 147 | ô 179 | │ 211 | Ë 243 | ¾
20 | ¶  52 | 4  84 | T  116 | t 148 | ö 180 | ┤ 212 | È 244 | ¶
21 | §  53 | 5  85 | U  117 | u 149 | ò 181 | Á 213 | ı 245 | §
22 | ▬  54 | 6  86 | V  118 | v 150 | û 182 | Â 214 | Í 246 | ÷
23 | ↨  55 | 7  87 | W  119 | w 151 | ù 183 | À 215 | Î 247 | ¸
24 | ↑  56 | 8  88 | X  120 | x 152 | ÿ 184 | © 216 | Ï 248 | °
25 | ↓  57 | 9  89 | Y  121 | y 153 | Ö 185 | ╣ 217 | ┘ 249 | ¨
26 | →  58 | :  90 | Z  122 | z 154 | Ü 186 | ║ 218 | ┌ 250 | ·
27 | ←  59 | ;  91 | [  123 | { 155 | ø 187 | ╗ 219 | █ 251 | ¹
28 | ∟  60 | <  92 | \  124 | | 156 | £ 188 | ╝ 220 | ▄ 252 | ³
29 | ↔  61 | =  93 | ]  125 | } 157 | Ø 189 | ¢ 221 | ¦ 253 | ²
30 | ▲  62 | >  94 | ^  126 | ~ 158 | × 190 | ¥ 222 | Ì 254 | ■
31 | ▼  63 | ?  95 | _  127 | ⌂ 159 | ƒ 191 | ┐ 223 | ▀ 255 |  

*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 ** Default SCREEN_WIDTH is 80.
 ** Default SCREEN_HEIGHT is 25.
 **/
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 80
#endif // SCREEN_WIDTH

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 80
#endif // SCREEN_HEIGHT

#define F_BLACK			0x00
#define	F_BLUE			0x01
#define	F_GREEN 		0x02
#define F_AQUA			0x03
#define	F_RED			0x04
#define F_PURPLE		0x05
#define F_YELLOW		0x06
#define F_WHITE			0x07
#define	F_GREY			0x08
#define	F_LIGHTBLUE		0x09
#define	F_LIGHTGREEN	0x0A
#define	F_LIGHTAQUA		0x0B
#define	F_LIGHTRED		0x0C
#define	F_LIGHTPURPLE	0x0D
#define	F_LIGHTYELLOW	0x0E
#define	F_BRIGTHWHITE	0x0F

#define B_BLACK			0x00
#define	B_BLUE			0x10
#define	B_GREEN 		0x20
#define B_AQUA			0x30
#define	B_RED			0x40
#define B_PURPLE		0x50
#define B_YELLOW		0x60
#define B_WHITE			0x70
#define	B_GREY			0x80
#define	B_LIGHTBLUE		0x90
#define	B_LIGHTGREEN	0xA0
#define	B_LIGHTAQUA		0xB0
#define	B_LIGHTRED		0xC0
#define	B_LIGHTPURPLE	0xD0
#define	B_LIGHTYELLOW	0xE0
#define	B_BRIGTHWHITE	0xF0

#define KEY_BACKSPACE	0x08
#define KEY_ENTER		0x0D
#define KEY_ESCAPE		0x1B
#define KEY_ARROW_LEFT	0x25
#define KEY_ARROW_UP	0x26
#define KEY_ARROW_RIGHT	0x27
#define KEY_ARROW_DOWN	0x28
#define KEY_0			0x30
#define KEY_1			0x31
#define KEY_2			0x32
#define KEY_3			0x33
#define KEY_4			0x34
#define KEY_5			0x35
#define KEY_6			0x36
#define KEY_7			0x37
#define KEY_8			0x38
#define KEY_9			0x39
#define KEY_A			0x41
#define KEY_B			0x42
#define KEY_C			0x43
#define KEY_D			0x44
#define KEY_E			0x45
#define KEY_F			0x46
#define KEY_G			0x47
#define KEY_H			0x48
#define KEY_I			0x49
#define KEY_J			0x4A
#define KEY_K			0x4B
#define KEY_L			0x4C
#define KEY_M			0x4D
#define KEY_N			0x4E
#define KEY_O			0x4F
#define KEY_P			0x50
#define KEY_Q			0x51
#define KEY_R			0x52
#define KEY_S			0x53
#define KEY_T			0x54
#define KEY_U			0x55
#define KEY_V			0x56
#define KEY_W			0x57
#define KEY_X			0x58
#define KEY_Y			0x59
#define KEY_Z			0x5A
#define KEY_NUMPAD0		0x60
#define KEY_NUMPAD1		0x61
#define KEY_NUMPAD2		0x62
#define KEY_NUMPAD3		0x63
#define KEY_NUMPAD4		0x64
#define KEY_NUMPAD5		0x65
#define KEY_NUMPAD6		0x66
#define KEY_NUMPAD7		0x67
#define KEY_NUMPAD8		0x68
#define KEY_NUMPAD9		0x69

enum FrameType : unsigned short int {DOUBLE = 0, SINGLE = 1};

class ConsoleWindows
{
	public:
		ConsoleWindows(SHORT width = SCREEN_WIDTH, SHORT height = SCREEN_HEIGHT);
		void fillCell(SHORT x, SHORT y, CHAR c, WORD attr);
		void drawBuffer();
		void drawBufferRegion(SHORT x, SHORT y, SHORT columns, SHORT rows);
		void fillBuffer(CHAR c, WORD attr);
		void drawFrame(int x, int y, int w, int h, FrameType type, unsigned char attr);
		void drawWords(int x, int y, const char* text, size_t n, unsigned char attr);
		void setTitle(const char* title);
		void setWindowSize(SHORT width, SHORT height, bool adjustBuffer);		
		void showConsoleCursor(BOOL visible);		
		void gotoxy(SHORT x, SHORT y);

		bool isKeyDown(int key);
		bool isKeyPressed(int key);


	private:
		HANDLE consoleOutput;
		COORD bufferSize, bufferCoord;
		SMALL_RECT region;
		CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
		bool keys[256];
};

#endif // BASE4CONSOLEGAMES_HPP
