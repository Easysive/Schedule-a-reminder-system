#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define OK 1
#define Error 0
using namespace std;

//定义链表所存数据 
typedef struct Content
{
	char thing[100];
	char time[15]={0};
	bool preReming;
}content;
//定义链表节点
typedef struct ThingNode
{
	content data;
	struct ThingNode* next;
	int length;
}List;
//创建链表
List* creat_list()
{
	List* node = (List*)malloc(sizeof(List));
	node->next = NULL;
	node->length = 0;
	return node;
}

//创建日程事件链表
List* ThingList = creat_list();


//添加日程(头插法)
void add_list(List*& head, Content data)
{
	List* node = creat_list();
	node->data = data;
	node->next = head->next;
	head->next = node;
	head->length++;
}

//查找日程
List* search_list(List* head, char* time1)
{
	List* searcher = head->next;
	while (searcher != NULL && strcmp(searcher->data.time, time1) != 0) {
		searcher = searcher->next;
	}
	if (searcher == NULL) {
		return NULL;
	}
	else {
		return searcher;
	}
}

//对日程进行修改
void change_list(ThingNode* head, int x, int Page)
{
	ThingNode* p = head;
	x = ((Page - 1) * 15) + x;
	for (int i = 0; i < x - 1; i++) {
		if (p->next->next != NULL) {
			p = p->next;
		}
		else {
			return;
		}
	}
	Content* temp = (Content*)malloc(sizeof(Content));
	if (InputBox(temp->time, 16, "输入时间（请输入当年日期）", "时间", NULL, 0, 0, false)) {
		if (InputBox(temp->thing, 32, "输入事件", "事件", NULL, 0, 0, false)) {
			p->next = p->next->next;
			ThingList->length--;
			add_list(ThingList, *temp);
		}
	}
}

//删除日程
void delete_list(ThingNode* head, int x, int Page)
{
	ThingNode* p = head;
	x = ((Page - 1) * 15) + x;
	for (int i = 0; i < x - 1; i++) {
		if (p->next->next != NULL) {
			p = p->next;
		}
		else {
			return;
		}
	}
	p->next = p->next->next;
	ThingList->length--;
}

void ThingSort_ByTime(List* head) {
	//按照日期从早到晚排序
	//采用冒泡法进行排序
	List* front, * middle , * rear;
	for (int i = 0; i < head->length - 1; i++) {
		front = head, middle = head->next, rear = middle->next;
		for (int j = 0; j < head->length - 1 - i; j++) {
			if (strcmp(middle->data.time, rear->data.time) > 0) {
				middle->next = rear->next;
				rear->next = middle;
				front->next = rear;
			}
				front = front->next;
				middle = front->next;
				rear = middle->next;
		}
	}
}
//计算页数
int count_page(List* list) {
	List* show = (List*)malloc(sizeof(List));
	show = list->next;
	int page_number = 1;
	while (show != NULL) {
		for (int i = 0; i < 15; i++) {
			if (show->next != NULL) {
				show = show->next;
			}
			else {
				return page_number;
			}
		}
		page_number++;
	}
}

//读取文件
void read_file(List* list, const char* file)
{
	FILE* fp = fopen(file, "r");
	Content temp;
	if (fp == NULL) {
		fp = fopen(file, "w+");
		fclose(fp);
	}
	else {
		while (fscanf(fp, "%s\t%s\n", temp.time, temp.thing) != EOF) {
			add_list(list, temp);
			ThingSort_ByTime(list);
		}
	}
	fclose(fp);
}
//写入文件
void write_file(List* head, const char* flie)
{
	List* writer = head->next;
	FILE* fp = fopen(flie, "w");
	while (writer != NULL) {
		fprintf(fp, "%s\t%s\n", writer->data.time, writer->data.thing);
		writer = writer->next;
	}
	fclose(fp);
}