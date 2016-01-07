#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

//�v���g�^�C�v�錾
void downheap(int, int);
void heap_sort(int);
void print_heap(int);

/* �y�O���[�o���ϐ��z*/
//�f�[�^�ۑ��z��
int data[MAX];

int main()
{
	//�ϐ�
	int num=0, seed;

	/* ���� */
	//�����̎�
	printf("Input randam-seed>");
	scanf("%d",&seed);

	//�f�[�^�̌�
	printf("Input the number of data>");
	scanf("%d",&num);
	//�G���[
	if( num>MAX )
	{
		printf("Error : N is too large!\n");
		exit(1);
	}

	//�f�[�^����
	srand(seed);
	for(int i=1; i<=num; i++) data[i] = ( rand()*rand() / 1000 )%100;

	//���̓f�[�^�\��
	printf("*** ImputData ***\n");
	for(int i=1; i<=num; i++) printf("d[%3d]: data = %2d\n",i,data[i]);

	//�\�[�g���s
	heap_sort(num);

	//�\��
	printf("*** OutputData ***\n");
	for(int i=1; i<=num; i++) printf("d[%3d]: data = %2d\n",i,data[i]);

	return 0;
}

//�e�Ǝq�̑召�֌W��^����y�e>�q�z
void downheap(int j, int k)
{
	//�ϐ�
	int i, tmp = data[j];

	while( j<=k/2)
	{
		//�q�̓Y����
		i = 2*j;

		//�q���͈͓��ŁAi���ő�l�̎q�̓Y�����ɂ���
		if( i<k && data[i]<data[i+1] ) i++;
		//�e���傫�����ƁA�q���͈͊O�̎�
		if( tmp>=data[i] || i>k ) break;

		data[j] = data[i];
		data[i] = tmp;
		j = i;
	}
}

//�q�[�v�\�[�g�y�����z
void heap_sort(int num)
{
	//�ϐ�������
	int tmp, loop = num;

	//�����̃q�[�v��
	printf("*** heep down ***\n");
	for(int j=num/2; j>=1; j--)
	{
		downheap(j,num);
		print_heap(num);
	}

	//���̍ăq�[�v��
	printf("*** sorting ***\n");
	
	while(loop > 1)
	{
		//�ő�l���ɒu��
		tmp = data[1];
		data[1] = data[loop];
		data[loop] = tmp;

		//�ăq�[�v
		downheap(1, --loop);
		print_heap(num);
	}
}


//�f�[�^�\��
void print_heap(int num)
{
	//�ϐ�
	int line = 1;	//�s��
	int max = 2;	//�ő啶����
	int n = 1;	//�Y��
	int k = 1;	//���̍s�̋��e������

	//�s���v�Z
	while( num>max )
	{
		line++;
		max*=2;
	}
	
	/* �\�� */
	//�s��
	for(int i=0; i<line; i++)
	{
		//���̍s�͋��e��������2�{
		k *= 2;

		//���
		for(int j=0; j<max; j++)
		{
			//j�����̍s�̕����Ԋu�ł��A�O�̍s�Ő�����\�����ĂȂ����A�l�\���B
			if (j % (max / k) == 0 && j % (max * 2 / k) != 0) printf("%2d", data[n++]);
			//����"  "�ŃC���f���g
			else printf("  ");

			//�f�[�^������
			if (n > num) break;
		}
		printf("\n");
	}
}