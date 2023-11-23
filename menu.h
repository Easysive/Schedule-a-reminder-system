#pragma once
#include<windows.h>
#include <graphics.h>
#include <time.h>
#include "data_struct.h"

COLORREF butt = RGB(225, 255, 255);
COLORREF dark_orign = RGB(255, 140, 0);
COLORREF gray = RGB(220, 220, 220);
COLORREF skyblue = RGB(70, 130, 180);
COLORREF light_skyblue = RGB(135, 206, 235);

int page_cnt;	//页面数


//绘图函数
//主菜单
void first_menu();
void show_things();
void things_menu();
//按钮1
void button(int left, int top, int right, int bottom,
	const char* flag, COLORREF word, COLORREF back);
//按钮2
void button_delete(int left, int top, int right, int bottom,
	const char* flag, COLORREF word, COLORREF back);


//清空表格
void clear_excel();
void things_add(ExMessage msg);
void things_prepage(ExMessage msg);
void things_nextpage(ExMessage msg);
void things_change(ExMessage msg);
void things_finish(ExMessage msg);
char* ReadNowTime();
int JudgeTime(List* a);


/***************绘图***************/
//主界面
void first_menu()
{
	//绘制初始窗口
	initgraph(1080, 720);
	//背景
	setbkcolor(gray);
	cleardevice();
	//上方块
	setfillcolor(skyblue);
	solidrectangle(0, 0, 1080, 90);
	//左方块
	setfillcolor(light_skyblue);
	solidrectangle(0, 90, 140, 720);
	//装饰线条
	setfillcolor(WHITE);
	solidrectangle(0, 90, 1080, 95);
	solidrectangle(140, 90, 145, 720);
	//表格
	int i = 138;
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	for (int j = 1; j < 15; j++) {
		line(145, i + 35 * j, 1080, i + 35 * j);
	}
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
	line(340, 95, 340, 662);

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 4);
	line(145, 138, 1080, 138);
	line(1030, 95, 1030, 662);
	line(980, 95, 980, 662);
	line(145, 664, 1080, 664);

	settextcolor(dark_orign);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "宋体");
	outtextxy(210, 106, "时 间");
	outtextxy(590, 106, "事   件");
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, "宋体");
	outtextxy(985, 106, "修改");
	outtextxy(1035, 106, "完成");
	
	//欢迎标题
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "宋体");
	outtextxy(420, 20, "待办事项");
	//绘制初始窗口按钮
	button(25, 150, 115, 220, "新增", RED, butt);
	button(283, 674, 463, 711, "上一页", WHITE, RED);
	button(740, 674, 920, 711, "下一页", WHITE, RED);
} 

//寻常弹窗
void Normal() {
	initgraph(500, 500);//初始化图形窗口
	while (1) {
		BeginBatchDraw();//双缓冲绘图
		IMAGE first;
		setbkcolor(RGB(225, 245, 245));
		cleardevice();
		settextcolor(RGB(225, 0, 245));
		settextstyle(24, 0, "宋体");
		outtextxy(175, 150, "今日无待办事项");
		button(210, 300, 290, 350, "好的", dark_orign, skyblue);
		ExMessage msg;
		peekmessage(&msg, EM_MOUSE);
		if (msg.x >= 210 && msg.y >= 300 && msg.x <= 290 && msg.y <= 350) {
			clearroundrect(210, 300, 290, 350, 20, 20);
			button(210, 300, 290, 350, "好的", dark_orign, RED);
			if (msg.message == WM_LBUTTONDOWN) {
				break;
			}
		}
		else {
			button(210, 300, 290, 350, "好的", dark_orign, skyblue);
		}
		EndBatchDraw();
	}
}

//到时间的弹窗
void DeadLine(List* a) {
	initgraph(500, 500);//初始化图形窗口
	while (1) {
		BeginBatchDraw();//双缓冲绘图
		IMAGE first;
		setbkcolor(RGB(225, 245, 245));
		cleardevice();
		settextcolor(RGB(225, 0, 245));
		settextstyle(24, 0, "宋体");
		outtextxy(175, 150, "今日有待办事项");
		outtextxy(215, 240, a->data.thing);
		outtextxy(200, 200, a->data.time[8]);
		outtextxy(215, 200, a->data.time[9]);
		outtextxy(230, 200, "时");
		outtextxy(255, 200, a->data.time[10]);
		outtextxy(270, 200, a->data.time[11]);
		outtextxy(285, 200, "分");
		button(210, 300, 290, 350, "好的", dark_orign, skyblue);
		ExMessage msg;
		peekmessage(&msg, EM_MOUSE);
		if (msg.x >= 210 && msg.y >= 300 && msg.x <= 290 && msg.y <= 350) {
			clearroundrect(210, 300, 290, 350, 20, 20);
			button(210, 300, 290, 350, "好的", dark_orign, RED);
			if (msg.message == WM_LBUTTONDOWN) {
				break;
			}
		}
		else {
			button(210, 300, 290, 350, "好的", dark_orign, skyblue);
		}
		EndBatchDraw();
	}
}

//三天时候的弹窗
void ThreeDayLine(List* a) {
	initgraph(500, 500);//初始化图形窗口
	while (1) {
		BeginBatchDraw();//双缓冲绘图
		IMAGE first;
		setbkcolor(RGB(225, 245, 245));
		cleardevice();
		settextcolor(RGB(225, 0, 245));
		settextstyle(24, 0, "宋体");
		outtextxy(175, 150, "三日后有待办事项");
		outtextxy(215, 240, a->data.thing);
		outtextxy(200, 200, a->data.time[8]);
		outtextxy(215, 200, a->data.time[9]);
		outtextxy(230, 200, "时");
		outtextxy(255, 200, a->data.time[10]);
		outtextxy(270, 200, a->data.time[11]);
		outtextxy(285, 200, "分");
		button(210, 300, 290, 350, "好的", dark_orign, skyblue);
		ExMessage msg;
		peekmessage(&msg, EM_MOUSE);
		if (msg.x >= 210 && msg.y >= 300 && msg.x <= 290 && msg.y <= 350) {
			clearroundrect(210, 300, 290, 350, 20, 20);
			button(210, 300, 290, 350, "好的", dark_orign, RED);
			if (msg.message == WM_LBUTTONDOWN) {
				break;
			}
		}
		else {
			button(210, 300, 290, 350, "好的", dark_orign, skyblue);
		}
		EndBatchDraw();
	}
}

//按钮
void button(int left, int top, int right, int bottom,
	const char* flag, COLORREF word, COLORREF back)
{
	int x, y;
	settextcolor(word);
	setfillcolor(back);
	setbkmode(TRANSPARENT);
	settextstyle(24, 0, "宋体");
	solidroundrect(left, top, right, bottom, 20, 20);
	x = left + (right - left - textwidth(flag)) / 2;
	y = top + (bottom - top - textheight(flag)) / 2;
	outtextxy(x, y, flag);
}
void button_delete(int left, int top, int right, int bottom,
	const char* flag, COLORREF word, COLORREF back)
{
	int x, y;
	settextcolor(word);
	setfillcolor(back);
	setbkmode(TRANSPARENT);
	settextstyle(14, 0, "");
	solidroundrect(left, top, right, bottom, 0, 0);
	x = left + (right - left - textwidth(flag)) / 2;
	y = top + (bottom - top - textheight(flag)) / 2;
	outtextxy(x, y, flag);
}
/***************绘图****************/



/***************时间****************/
//读取现在的时间，并转化成temp字符串
char* ReadNowTime() {
	char temp[13];
	char* a;
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	a = asctime(timeinfo);
	temp[0] = a[20];
	temp[1] = a[21];
	temp[2] = a[22];
	temp[3] = a[23];
	//year
	if (a[4] == 'J' && a[5] == 'a') {
		temp[4] = '0'; temp[5] = '1';
	}
	else if (a[4] == 'F') {
		temp[4] = '0'; temp[5] = '2';
	}
	else if (a[4] == 'M' && a[6] == 'r') {
		temp[4] = '0'; temp[5] = '3';
	}
	else if (a[4] == 'A' && a[5] == 'p') {
		temp[4] = '0'; temp[5] = '4';
	}
	else if (a[4] == 'M' && a[5] == 'a') {
		temp[4] = '0'; temp[5] = '5';
	}
	else if (a[4] == 'J' && a[6] == 'n') {
		temp[4] = '0'; temp[5] = '6';
	}
	else if (a[4] == 'J') {
		temp[4] = '0'; temp[5] = '7';
	}
	else if (a[4] == 'A') {
		temp[4] = '0'; temp[5] = '8';
	}
	else if (a[4] == 'S') {
		temp[4] = '0'; temp[5] = '9';
	}
	else if (a[4] == 'O') {
		temp[4] = '1'; temp[5] = '0';
	}
	else if (a[4] == 'N') {
		temp[4] = '1'; temp[5] = '1';
	}
	else {
		temp[4] = '1'; temp[5] = '2';
	}
	//month
	if (a[8] == ' ') {
		temp[6] = '0';
	}
	else temp[6] = a[8];
	temp[7] = a[9];
	//day
	if (a[11] == ' ') {
		temp[8] = '0';
	}
	else temp[8] = a[11];
	temp[9] = a[12];
	//hour
	if (a[14] == ' ') {
		temp[10] = '0';
	}
	else temp[10] = a[14];
	temp[11] = a[15];
	//minute
	return temp;
}

//a为当前时间，b为用户设置函数
int ThreeDay(char* b, char* a) {//判断是否a比b早三天
	int a_year, a_month, a_day, a_sum = 0;
	int b_year, b_month, b_day, b_sum = 0;
	int flag = 0;

	a_year = (a[0] - 48) * 1000 + (a[1] - 48) * 100 + (a[2] - 48) * 10 + (a[3] - 48);
	a_month = (a[4] - 48) * 10 + (a[5] - 48);
	a_day = (a[6] - 48) * 10 + (a[7] - 48);

	b_year = (b[0] - 48) * 1000 + (b[1] - 48) * 100 + (b[2] - 48) * 10 + (b[3] - 48);
	b_month = (b[4] - 48) * 10 + (b[5] - 48);
	b_day = (b[6] - 48) * 10 + (b[7] - 48);


	if (a_year != b_year) {
		return 0;
	}
	else if (a_month == b_month || b_month == a_month + 1) {
		if (a_month == 2) {
			if (a_year % 400 == 0 || (a_year % 100 == 0 && a_year % 4 == 0)) {
				if (b_day + 29 - a_day == 3) {
					flag = 1;
				}
			}
			else if (b_day + 28 - a_day == 3) {
				flag = 1;
			}
		}
		else if (a_month == 1 || a_month == 3 || a_month == 5 ||
			a_month == 7 || a_month == 8 || a_month == 10 || a_month == 11) {
			if (b_day + 31 - a_day == 3) {
				flag = 1;
			}

		}
		else {
			if (b_day + 30 - a_day == 3) {
				flag = 1;
			}
		}
		if (b_day - a_day == 3) {
			flag = 1;
		}
	}
	if (flag == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

// 这个是判断是否要响铃，a是用户设置时间
int JudgeTime(List* a) {
	char b[13] = { 0 };
	char* h;

	h = ReadNowTime();
	for (int i = 0; i < 12; i++) {
		b[i] = h[i];
	}
	b[8] = '\0';

	if (!strncmp(a->data.time, b,8)) {
		DeadLine(a);
		return 1;
	}
	if (ThreeDay(a->data.time, b)) {
		ThreeDayLine(a);
		return 1;
	}
	else{
		return 0;
	}
}
/***************时间****************/

//	显示事项
void show_things()
{
	clear_excel();
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, "宋体");

	List* show = ThingList->next;
	int j = 35;
	int i = 0;
	int flag = 1;
	for (flag = 1; flag != page_cnt; flag++) {
		for (i = 0; i < 15; i++) {
			if (show != NULL) {
				show = show->next;
			}
			else {
				break;
			}
		}
	}
	for (i = 0; i < 15; i++) {
		if (show != NULL) {
			// 2022,11,25,11,25
			outtextxy(158, 149 + i * j, show->data.time[4]);
			outtextxy(168, 149 + i * j, show->data.time[5]);
			outtextxy(178, 149 + i * j, "月");
			outtextxy(198, 149 + i * j, show->data.time[6]);
			outtextxy(208, 149 + i * j, show->data.time[7]);
			outtextxy(218, 149 + i * j, "日");
			outtextxy(238, 149 + i * j, show->data.time[8]);
			outtextxy(248, 149 + i * j, show->data.time[9]);
			outtextxy(258, 149 + i * j, "时");
			outtextxy(278, 149 + i * j, show->data.time[10]);
			outtextxy(288, 149 + i * j, show->data.time[11]);
			outtextxy(298, 149 + i * j, "分");
			outtextxy(615, 149 + i * j, show->data.thing);
		}
		else {
			break;
		}
		show = show->next;
	}
	setfillcolor(gray);
	solidrectangle(570, 670, 700, 700);
	settextstyle(16, 0, "宋体");
	char pp[2];
	char qq[2];
	qq[0] = page_cnt + 48;
	pp[0] = count_page(ThingList) + 48;
	qq[1] = '\0';
	pp[1] = '\0';
	settextcolor(dark_orign);
	outtextxy(610, 683, pp);
	outtextxy(578, 683, qq);
	settextcolor(RED);
	outtextxy(554, 684, "第   |   页");
}

//菜单行为
void things_menu()			
{
	page_cnt = 1;
	show_things();
	while (true)
	{
		
		BeginBatchDraw();
		ExMessage msg;

		if (peekmessage(&msg, EM_MOUSE)) {
			things_add(msg);			//添加
			things_change(msg);		//查找
			things_prepage(msg);		//上一页
			things_nextpage(msg);		//下一页
			things_finish(msg);			//已完成
		}
		EndBatchDraw();
	}
}

//新增提醒
void things_add(ExMessage msg)
{
	if (msg.x >= 25 && msg.y >= 153 && msg.x <= 115 && msg.y <= 220) {
		clearroundrect(25, 150, 115, 220, 20, 20);
		button(28, 153, 112, 217, "添加", RED, butt);
		if (msg.message == WM_LBUTTONDOWN) {
			Content* temp = (Content*)malloc(sizeof(Content));
			if (InputBox(temp->time, 16, "输入时间（请输入当年日期）", "时间", NULL, 0, 0, false)) {
				if (InputBox(temp->thing, 32, "输入事件", "事件", NULL, 0, 0, false)) {
					add_list(ThingList, *temp);
					ThingSort_ByTime(ThingList);
					show_things();
					write_file(ThingList,"thing.txt");
				}
			}
		}
	}
	else {
		button(25, 150, 115, 220, "添加", RED, butt);
	}
}

//后一页
void things_prepage(ExMessage msg)
{
	if (msg.x >= 283 && msg.y >= 674 && msg.x <= 463 && msg.y <= 711) {
		clearroundrect(283, 674, 463, 711, 20, 20);
		button(287, 678, 459, 707, "上一页", WHITE, RED);
		if (msg.message == WM_LBUTTONDOWN) {
			if (page_cnt > 1) {
				page_cnt--;
				show_things();
			}
		}
	}
	else {
		button(283, 674, 463, 711, "上一页", WHITE, RED);
	}
}

//前一页
void things_nextpage(ExMessage msg)
{
	if (msg.x >= 740 && msg.y >= 674 && msg.x <= 920 && msg.y <= 711) {
		clearroundrect(740, 674, 920, 711, 20, 20);
		button(744, 678, 916, 707, "下一页", WHITE, RED);
		if (msg.message == WM_LBUTTONDOWN) {
			if (page_cnt < count_page(ThingList)) {
				page_cnt++;
				show_things();
			}
		}
	}
	else {
		button(740, 674, 920, 711, "下一页", WHITE, RED);
	}
}

//修改
void things_change(ExMessage msg)
{
	int i = 35, j = 0;
	for (j; j < 15; j++) {
		if (msg.x >= 980 && msg.y >= 140 + i * j && msg.x <= 1030 && msg.y <= 170 + i * j) {
			clearroundrect(982, 140 + i * j, 1028, 171 + i * j, 0, 0);
			button_delete(982, 142 + i * j, 1028, 169 + i * j, "修改", YELLOW, skyblue);
			if (msg.message == WM_LBUTTONDOWN) {
				change_list(ThingList, j+1, page_cnt);
				show_things();
			}
		}
		else {
			button_delete(982, 140 + i * j, 1028, 171 + i * j, "", YELLOW, gray);
		}
	}
	write_file(ThingList, "thing.txt");
}

//  已完成
void things_finish(ExMessage msg)
{
	int i = 35, j = 0;
	for (j; j < 15; j++) {
		if (msg.x >= 1030 && msg.y >= 140 + i * j && msg.x <= 1080 && msg.y <= 170 + i * j) {
			clearroundrect(1032, 140 + i * j, 1080, 171 + i * j, 0, 0);
			button_delete(1032, 142 + i * j, 1078, 169 + i * j, "已完成", YELLOW, skyblue);
			if (msg.message == WM_LBUTTONDOWN) {
				delete_list(ThingList, j+1, page_cnt);
				show_things();
			}
		}
		else {
			button_delete(1032, 140 + i * j, 1080, 171 + i * j, "", YELLOW, gray);
		}
	}
	write_file(ThingList, "thing.txt");
}



//  清空表格
void clear_excel()
{
	setfillcolor(gray);
	for (int i = 0; i < 15; i++) {
		solidrectangle(146, 140 + i * 35, 330, 171 + i * 35);
		//solidrectangle(262, 140 + i * 35, 478, 171 + i * 35);
		solidrectangle(482, 140 + i * 35, 960, 171 + i * 35);
	}
}