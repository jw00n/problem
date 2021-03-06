#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int sum_check = 1;
int result = 0;
int testcase;
bool visit[4];
deque <int> dq[4];

void Gear_turn(int Gear_num, int Gear_direction) {
	if (Gear_direction == 1) {
		int temp = dq[Gear_num].back();
		dq[Gear_num].pop_back();
		dq[Gear_num].push_front(temp);
	}
	else {
		int temp = dq[Gear_num].front();
		dq[Gear_num].pop_front();
		dq[Gear_num].push_back(temp);
	}
}

void Gear_Check(int Gear_num, int Gear_direction) { //돌아갈 기어 true
	visit[Gear_num] = true;
	int Prev_Gear_num = Gear_num - 1; int Next_Gear_num = Gear_num + 1;
	//3이 들어오고 기어넘버는 2로 넘어온다.
	//prev는 1
	cout << "이전기어" << Prev_Gear_num << "다음기어" << Next_Gear_num << endl;

	if (Prev_Gear_num >= 0 && !visit[Prev_Gear_num]) { //이전기어가 0(여기선 1)보다 같거나 크거나 
		cout << "여기"<<!visit[Prev_Gear_num] << endl;
		if (dq[Prev_Gear_num][2] != dq[Gear_num][6])
			Gear_Check(Prev_Gear_num, (Gear_direction) * (-1));
	}

	if (Next_Gear_num < 4 && !visit[Next_Gear_num]) {
		if (dq[Next_Gear_num][6] != dq[Gear_num][2])
			Gear_Check(Next_Gear_num, (Gear_direction) * (-1));
	}
	Gear_turn(Gear_num, Gear_direction);
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();

	for (int i = 0; i < 4; i++) { //톱니 상태
		string index;
		
		cin >> index;

		for (int j = 0; j < index.length(); j++)
			dq[i].push_back((index[j] - '0'));
	}


	cin >> testcase;
	while (testcase--) {
		int Gear_num, Gear_direction;
	
		cin >> Gear_num >> Gear_direction; //돌아갈 기어 넘버, 기어방향

		Gear_Check(Gear_num - 1, Gear_direction);
		memset(visit, false, sizeof(visit));
	}

	for (int i = 0; i < 4; i++) {
		if (dq[i][0] == 1)
			result += sum_check;
		sum_check *= 2;
	}
	cout << result;
	return 0;
}