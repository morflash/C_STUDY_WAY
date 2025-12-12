#include <stdio.h>
//#include <stdlib.h>
#include <easyx.h>
#include <direct.h>

#include <graphics.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")

#define GRID_W 20
#define INTERVAL (1*GRID_W)
#define ROW 19
#define COL 19

bool judge(int r, int c);
//存储数据的二维数组
int map[ROW][COL];
enum Chess//棋子状态
{
	None,Black,White
};

struct //位置结构体
{
	int x;int y;//像素坐标
	bool isShow;//判断是否显示的状态
	int row; int col;//格点坐标
	Chess chessplayer = Black;//棋手
}op;

void draw()//绘制界面
{
	setlinecolor(BLACK);//线条颜色
	setlinestyle(PS_SOLID, 1);//设置线条样式
	for (int i = 0; i < 19; i++)
	{
		line(INTERVAL, INTERVAL+ GRID_W*i, INTERVAL + GRID_W * 18, INTERVAL+ GRID_W*i);//两点一线
		line(INTERVAL + GRID_W * i, INTERVAL, INTERVAL + GRID_W * i, INTERVAL + GRID_W * 18);
	}

	//设置线条样式
	setlinestyle(PS_SOLID, 2);
	//绘制一个矩形
	rectangle(INTERVAL, INTERVAL, INTERVAL + GRID_W * 18, INTERVAL + GRID_W * 18);
	

	//绘制下棋选择框
	if (op.isShow)
	{
		setlinecolor(BLUE);
		rectangle(op.x - 10, op.y - 10, op.x + 10, op.y + 10);
	}

	//绘制棋子
	for(int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL;j++)
		{
			switch (map[i][j])
			{
			case None:
					break;
			case Black:
				setfillcolor(BLACK);
				solidcircle((i + 1) * GRID_W, (j + 1) * GRID_W, 5);
				break;
			case White:
				setfillcolor(WHITE);
				solidcircle((i + 1) * GRID_W, (j + 1) * GRID_W, 5);
			}
		}
	}
}

void PlayEffect(const char* file)//下棋音效
{
	char cmd[256];

	// 打开
	sprintf_s(cmd, sizeof(cmd), "open \"%s\" type waveaudio alias eff", file);
	mciSendString("close eff", NULL, 0, NULL);  // 防止未关闭
	mciSendString(cmd, NULL, 0, NULL);

	// 播放
	mciSendString("play eff from 0", NULL, 0, NULL);

	// 音效短，不必close，也不影响播放
}


void mouseevent()//获取鼠标消息
{
	ExMessage msg;
	if (peekmessage(&msg))//有消息就进来
	{
		op.isShow = false;

		for (int i = 0; i < 19; i++)//校准坐标
		{
			for (int j = 0; j < 19; j++)
			{
				int grid_x = (1 + i) * GRID_W;
				int grid_y = (1 + j) * GRID_W;
				if (abs(msg.x - grid_x) < 10 && abs(msg.y - grid_y) < 10)
				{
					op.x = grid_x;
					op.y = grid_y;
					op.row = i;
					op.col = j;
					op.isShow = true;
				}
			}
		}

		
		if (msg.message == WM_LBUTTONDOWN && map[op.row][op.col]==None)//左键下棋
		{
			map[op.row][op.col] = op.chessplayer;

			//下棋音效
			if(map[op.row][op.col] == Black) PlayEffect("Res\\put.wav");
			else PlayEffect("Res\\put2.wav");

			

			if (judge(op.row, op.col))
			{
				draw();
				FlushBatchDraw();

				PlaySound(TEXT("Res\\wintrue.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				MessageBox(GetHWnd(), "你赢了", op.chessplayer==Black?"黑哥们":"白哥们", MB_OK);
			}
			op.chessplayer = (op.chessplayer == Black ? White : Black);
		}
	}

}


bool judge(int r, int c) //判断胜负
{
	// 1. 检查落子位置是否有效，且不是空位置
	if (r < 0 || r >= 18 || c < 0 || c >= 18 || map[r][c] == 0) {
		return false;
	}

	// 当前落子的颜色
	int color = map[r][c];

	// 定义4个方向对（每个方向对包含两个相反的方向）
	// 格式：{dr1, dc1, dr2, dc2}，分别表示两个方向的行/列偏移量
	int directions[4][4] = {
		{0, 1, 0, -1},   // 水平方向（右、左）
		{1, 0, -1, 0},   // 垂直方向（下、上）
		{1, 1, -1, -1},  // 正斜线（右下、左上）
		{1, -1, -1, 1}   // 反斜线（左下、右上）
	};

	// 2. 遍历每个方向对，统计连续同色棋子数量
	for (int i = 0; i < 4; i++) {
		int count = 1;  // 初始为1，包含当前落子

		// 第一个方向（如水平向右）
		int dr = directions[i][0];
		int dc = directions[i][1];
		int nr = r + dr;
		int nc = c + dc;
		while (nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && map[nr][nc] == color) {
			count++;
			nr += dr;
			nc += dc;
		}

		// 第二个方向（如水平向左）
		dr = directions[i][2];
		dc = directions[i][3];
		nr = r + dr;
		nc = c + dc;
		while (nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && map[nr][nc] == color) {
			count++;
			nr += dr;
			nc += dc;
		}

		// 3. 只要有一个方向连续数量>=5，判定获胜
		if (count >= 5) {
			return true;
		}
	}

	// 所有方向都不足5个，未获胜
	return false;
}



int main()
{
	//播放音乐
	PlaySound(TEXT("Res\\aqbgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	initgraph(400, 600,EX_SHOWCONSOLE);

	setbkcolor(RGB(230, 231, 232));
	cleardevice();
	//创建文件对象
	IMAGE img_bk;
	//加载图片
	loadimage(&img_bk, "Res/bk1.jpg",400,600);
	//输出图片
	putimage(0,0,&img_bk);


	//双缓冲绘图
	BeginBatchDraw();



	while (true)
	{
		
		cleardevice();//清屏
		putimage(0, 0, &img_bk);
		draw();
		mouseevent();
		FlushBatchDraw();//刷新
	}

	//结束双缓冲绘图
	EndBatchDraw();
	return 0;
}
