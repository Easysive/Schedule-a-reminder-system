#include <stdio.h> 
#include "menu.h"

int main()
{
	//��ȡ�ļ�
	read_file(ThingList, "thing.txt");
	List* searcher = ThingList->next;
	int cnt = 0;
	while (searcher != NULL) {
		//�ж�ʱ��
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