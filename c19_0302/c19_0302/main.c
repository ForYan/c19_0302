#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//������
#define ROW 3
#define COL 3
int g_chess_board[ROW][COL];
//���Ƴ�ʼ��
void Init(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_chess_board[row][col] = ' ';
		}
	}
}
//��ӡ����
void Print(){
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n", g_chess_board[row][0], g_chess_board[row][1], g_chess_board[row][2]);
		if (row != ROW){
			printf("|---|---|---|\n");
		}
	}
}
//���������
void PlarMove(){
	//��ʾ�������һ������
	//��ȡ��ҵ�����
	//����ҵ��������У�飨У�������Ƿ��ں���Χ֮�ڣ���ҵ����������Ƿ��Ѿ����ӣ�
	//�����ҵ�����Ƿ�����ѭ����ʾ�û���������
	//�����ҵ�����Ϸ����Ͱ������ϵĶ�Ӧλ����Ϊx
	while (1){
		int row = -1;
		int col = -1;
		printf("���������һ������:");
		scanf("%d %d", &row, &col);
		if (row<0 || row >= ROW || col<0 || col >= COL){
			printf("��������Ƿ�������������!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' '){
			printf("�˴��Ѿ�������!���������룡\n");
			continue;
		}
		g_chess_board[row][col] = 'x';
		break;
	}	
}

//����������
//����������ȫ�ǿ����������һ���У����������һ���С�
//�����ǰ�����Ѿ������ˣ����ٲ���һ���к��С�
void ComputerMove(){
	printf("��������ӣ�\n");
	int row = 0;
	int col = 0;
	while (1){
		row = rand() % ROW;
		col = rand() % COL;
		if (g_chess_board[row][col] == ' '){
			g_chess_board[row][col] = 'o';
			break;
		}
	}
}
int IsFull(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			if (g_chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
//�����Ϸ�Ƿ����
//ʹ��x��ʾ��ң���o��ʾ����
//Լ��checkwinner�������Ż�x��ʾ���ʤ��������o��ʾ����ʤ��������һ��q��ʾ����
//������ؿո��ʾʤ��δ��
char CheckWinner(){
	//�ȼ������е����Ƿ�����һ��
	//�ټ������е����Ƿ�����һ��
	//������ż�еĶԽ����Ƿ�����һ��
	//����Ƿ����
	for (int row = 0; row < ROW; ++row){
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] != ' '){
			return g_chess_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col){
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' '){
			return g_chess_board[0][col];
		}
	}
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[0][0] == g_chess_board[2][2]
		&& g_chess_board[0][0] != ' '){
		return g_chess_board[0][0];
	}
	if (g_chess_board[0][2] == g_chess_board[1][1]
		&& g_chess_board[0][2] == g_chess_board[2][0]
		&& g_chess_board[0][2] != ' '){
		return g_chess_board[0][2];
	}
	if (IsFull()){
		return 'q';
	}
	return ' ';
}
int main(){
	char winner = ' ';
	//1.���Ƴ�ʼ���������Ƴ�ʼ��Ϊ�ո�
	Init();
	while (1){
		//2.��ӡһ������
		
		Print();
		//3.��������ӣ�˳����һ����Ϸ�Ƿ����
		PlarMove();
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
		//4.��������ӣ�˳����һ����Ϸ�Ƿ����
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
	    }	
	if (winner == 'x'){
		printf("���ʤ����\n");
	}
	else if (winner == 'o'){
		printf("����ʤ����\n");
	}
	else if (winner == 'q'){
		printf("���壡\n");
	}
	   //5.��ϷӮ����˭�������ǵ��ԣ���������ң������Ǻ��壬��
	system("pause");
	return 0;
}


//ð������:��һ��������һ����������顣
//void Swap(int* x, int* y){
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
////�����һ�����鵱��������������ô�������ͻ���ʽ�˻���ָ��
////���ָ���ָ�����������Ԫ��
//void BubbleSort(int arr[],int len){
//	//��ǰ�����������Ҫ֪�������Ԫ�ظ����ġ�
//	//����ͨ��sizeof�ǻ�ȡ�����ġ�
//	//[0,bound)���Ѿ��źõ�����
//	//[bound,len���Ǵ��ŵ�����
//	//���ɾѡ��һ����С��Ԫ�ط�����ʶλ���ˣ�����bound++��
//	for (int bound = len-1; bound >=0; --bound){
//			int cur = 0;
//			for (; cur < bound;++cur){
//				if (arr[cur]>arr[cur + 1]){
//					Swap(&arr[cur], &arr[cur + 1]);
//				}
//			}
//		}
//	}
//int main(){
//	int arr[] = { 9, 5, 2, 7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr,len);
//	for (int i = 0; i < len; ++i){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}