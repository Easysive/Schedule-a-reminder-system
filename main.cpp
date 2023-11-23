#include <stdio.h> 
#include "menu.h"

int main()
{
	//读取文件
	read_file(ThingList, "thing.txt");
	List* searcher = ThingList->next;
	int cnt = 0;
	while (searcher != NULL) {
		//判断时间
		if (JudgeTime(searcher) == 1) {
			cnt--;
		}
		searcher = searcher->next;
		cnt++;
	}
	if (cnt == ThingList->length) {
		Normal();
	}
	first_menu();
	while (true) {

		things_menu();
	}
	return 0;
}
