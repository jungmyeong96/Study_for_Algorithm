#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int QUEUE[30];//큐!
int map[30][30];//기준이 되는 맵
int visit[30]; //어디까지 방문을 했는지 맵을 체크할 메모장
int	max;
int head = 0;
int tail = 0;

void	push(int num)
{
	QUEUE[tail++] = num;
}
int	pop()
{
		head++;
		return(QUEUE[head - 1]);
}

void	BFS(int offset)
{
	int i;

	visit[offset] = 1; //정점 offset을 방문했다고 표시
	printf("%d에서 시작\n", offset);
	push(offset); // 큐에 push로 offset를 삽입하고 큐의 tail을 증가해줌
	while (head < tail)// tail이 head이 같거나 작으면 루프탈출
	{
		// 큐의 head위치에 있는 데이터를 변수에 저장하고 pop으로 값을 지우고 head를 증가
		offset = pop();
		i = 1;
		while (i <= max)
		{
			//정점 offset와 정점 i가 연결되어있고, 정점 i를 방문하지 않은 상태일 경우
			if (map[offset][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				printf("%d에서 %d로 이동\n", offset, i);
				push(i); //큐에 i를 삽입하고 tail을 1증가시킴
			}
			i++;
		}
	}
}

int main()
{
	int	start;	//시작 정점을 나타내는 변수
	int	v1;
	int v2;

	scanf("%d%d", &max, &start);

	while (1) //map생성기 v1v2 짝지어서 갈수 있는 길 이면 1
	{
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1)
			break;
		map[v1][v2] = 1; //v1과 v2를 연결시켜줌
		map[v2][v1] = 1;
	}

	BFS(start); //BFS의 시작
	
	return 0;
}