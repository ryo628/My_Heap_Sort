#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

//プロトタイプ宣言
void downheap(int, int);
void heap_sort(int);
void print_heap(int);

/* 【グローバル変数】*/
//データ保存配列
int data[MAX];

int main()
{
	//変数
	int num=0, seed;

	/* 入力 */
	//乱数の種
	printf("Input randam-seed>");
	scanf("%d",&seed);

	//データの個数
	printf("Input the number of data>");
	scanf("%d",&num);
	//エラー
	if( num>MAX )
	{
		printf("Error : N is too large!\n");
		exit(1);
	}

	//データ生成
	srand(seed);
	for(int i=1; i<=num; i++) data[i] = ( rand()*rand() / 1000 )%100;

	//入力データ表示
	printf("*** ImputData ***\n");
	for(int i=1; i<=num; i++) printf("d[%3d]: data = %2d\n",i,data[i]);

	//ソート実行
	heap_sort(num);

	//表示
	printf("*** OutputData ***\n");
	for(int i=1; i<=num; i++) printf("d[%3d]: data = %2d\n",i,data[i]);

	return 0;
}

//親と子の大小関係を与える【親>子】
void downheap(int j, int k)
{
	//変数
	int i, tmp = data[j];

	while( j<=k/2)
	{
		//子の添え字
		i = 2*j;

		//子が範囲内で、iを最大値の子の添え字にする
		if( i<k && data[i]<data[i+1] ) i++;
		//親が大きい時と、子が範囲外の時
		if( tmp>=data[i] || i>k ) break;

		data[j] = data[i];
		data[i] = tmp;
		j = i;
	}
}

//ヒープソート【昇順】
void heap_sort(int num)
{
	//変数初期化
	int tmp, loop = num;

	//初期のヒープ化
	printf("*** heep down ***\n");
	for(int j=num/2; j>=1; j--)
	{
		downheap(j,num);
		print_heap(num);
	}

	//根の再ヒープ化
	printf("*** sorting ***\n");
	
	while(loop > 1)
	{
		//最大値を底に置く
		tmp = data[1];
		data[1] = data[loop];
		data[loop] = tmp;

		//再ヒープ
		downheap(1, --loop);
		print_heap(num);
	}
}


//データ表示
void print_heap(int num)
{
	//変数
	int line = 1;	//行数
	int max = 2;	//最大文字数
	int n = 1;	//添字
	int k = 1;	//その行の許容文字数

	//行数計算
	while( num>max )
	{
		line++;
		max*=2;
	}
	
	/* 表示 */
	//行回し
	for(int i=0; i<line; i++)
	{
		//下の行は許容文字数は2倍
		k *= 2;

		//列回し
		for(int j=0; j<max; j++)
		{
			//jがその行の文字間隔でかつ、前の行で数字を表示してない時、値表示。
			if (j % (max / k) == 0 && j % (max * 2 / k) != 0) printf("%2d", data[n++]);
			//他は"  "でインデント
			else printf("  ");

			//データ数判定
			if (n > num) break;
		}
		printf("\n");
	}
}