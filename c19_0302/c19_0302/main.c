#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//三子棋
#define ROW 3
#define COL 3
int g_chess_board[ROW][COL];
//棋牌初始化
void Init(){
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_chess_board[row][col] = ' ';
		}
	}
}
//打印棋牌
void Print(){
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n", g_chess_board[row][0], g_chess_board[row][1], g_chess_board[row][2]);
		if (row != ROW){
			printf("|---|---|---|\n");
		}
	}
}
//玩家请落子
void PlarMove(){
	//提示玩家输入一个坐标
	//读取玩家的输入
	//对玩家的输入进行校验（校验坐标是否在合理范围之内，玩家的输入坐标是否已经有子）
	//如果玩家的输入非法，就循环提示用户进行输入
	//如果玩家的输入合法，就把棋牌上的对应位置设为x
	while (1){
		int row = -1;
		int col = -1;
		printf("请玩家输入一个坐标:");
		scanf("%d %d", &row, &col);
		if (row<0 || row >= ROW || col<0 || col >= COL){
			printf("输入坐标非法！请重新输入!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' '){
			printf("此处已经有子了!请重新输入！\n");
			continue;
		}
		g_chess_board[row][col] = 'x';
		break;
	}	
}

//电脑请落子
//电脑落子完全是靠随机数产生一个行，随机数产生一个列。
//如果当前坐标已经有子了，就再产生一个行和列。
void ComputerMove(){
	printf("请电脑落子！\n");
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
//检测游戏是否结束
//使用x表示玩家，用o表示电脑
//约定checkwinner函数，放回x表示玩家胜利，返回o表示电脑胜利，返回一个q表示和棋
//如果返回空格表示胜负未分
char CheckWinner(){
	//先检验所有的行是否连在一起
	//再检验所有的列是否俩在一起
	//检验所偶有的对角线是否连在一起
	//检查是否和棋
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
	//1.棋牌初始化（将棋牌初始化为空格）
	Init();
	while (1){
		//2.打印一下棋牌
		
		Print();
		//3.请玩家落子，顺便检查一下游戏是否结束
		PlarMove();
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
		//4.请电脑落子，顺便检查一下游戏是否结束
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' '){
			break;
		}
	    }	
	if (winner == 'x'){
		printf("玩家胜利！\n");
	}
	else if (winner == 'o'){
		printf("电脑胜利！\n");
	}
	else if (winner == 'q'){
		printf("和棋！\n");
	}
	   //5.游戏赢家是谁（可能是电脑，可能是玩家，可能是和棋，）
	system("pause");
	return 0;
}


//冒泡排序:把一个数组变成一个有序的数组。
//void Swap(int* x, int* y){
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
////如果把一个数组当做函数参数，那么这个数组就会隐式退化成指针
////这个指针就指向了数组的首元素
//void BubbleSort(int arr[],int len){
//	//当前这个数组是需要知道数组的元素个数的。
//	//但是通过sizeof是获取不到的。
//	//[0,bound)是已经排好的数组
//	//[bound,len）是待排的数组
//	//如果删选出一个最小的元素放在意识位置了，就让bound++。
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