/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:39:24 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/23 14:41:07 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * 개선된 경로 탐색 알고리즘
 * BFS(너비 우선 탐색)를 사용해 플레이어(P)부터 출구(E)까지의 경로를 찾습니다.
 */

#include "so_long.h"

// 효율적인 큐 구현을 위한 구조체
typedef struct s_queue {
	t_list *front;
	t_list *rear;
	int size;
} t_queue;

// 큐 초기화
static t_queue *init_queue(void)
{
	t_queue *queue;
	
	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

// O(1) 시간 복잡도로 큐에 요소 추가
static void enqueue_point(t_queue *queue, int x, int y)
{
	t_point *new_point;
	t_list *new_node;
	
	if (!queue)
		return;
	
	new_point = (t_point *)malloc(sizeof(t_point));
	if (!new_point)
		return;
	new_point->x = x;
	new_point->y = y;
	
	new_node = ft_lstnew(new_point);
	if (!new_node)
	{
		free(new_point);
		return;
	}
	
	// 큐가 비어 있으면 front와 rear를 모두 새 노드로 설정
	if (queue->rear == NULL)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		// rear 다음에 새 노드 추가하고 rear 업데이트
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
	queue->size++;
}

// O(1) 시간 복잡도로 큐에서 요소 제거
static t_point *dequeue_point(t_queue *queue)
{
	t_list *temp;
	t_point *point;
	
	if (!queue || !queue->front)
		return (NULL);
	
	temp = queue->front;
	point = temp->content;
	
	queue->front = queue->front->next;
	
	// 큐가 비어있게 되면 rear도 NULL로 설정
	if (queue->front == NULL)
		queue->rear = NULL;
	
	free(temp);
	queue->size--;
	
	return (point);
}

// 큐 메모리 해제
static void free_queue(t_queue *queue)
{
	t_point *point;
	
	if (!queue)
		return;
	
	while (queue->size > 0)
	{
		point = dequeue_point(queue);
		if (point)
			free(point);
	}
	
	free(queue);
}

// 방문 여부를 추적하는 2차원 배열 생성
static int **create_visited_map(t_set *set)
{
	int **visited;
	int i, j;

	visited = (int **)malloc(sizeof(int *) * set->y);
	if (!visited)
		return (NULL);
	
	i = 0;
	while (i < set->y)
	{
		visited[i] = (int *)malloc(sizeof(int) * set->x);
		if (!visited[i])
		{
			// 이전에 할당된 메모리 해제
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		
		// 직접 0으로 초기화 (더 명시적)
		j = 0;
		while (j < set->x)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

// 방문 배열 메모리 해제
static void free_visited_map(int **visited, int y)
{
	int i;

	i = 0;
	while (i < y)
		free(visited[i++]);
	free(visited);
}

// BFS 알고리즘으로 경로 탐색
int find_path_bfs(t_set *set)
{
	t_queue *queue;
	t_point *current;
	int **visited;
	int dx[4] = {-1, 0, 1, 0}; // 좌, 상, 우, 하
	int dy[4] = {0, -1, 0, 1};
	int i, nx, ny;
	int found_exit = 0;

	// 큐 초기화
	queue = init_queue();
	if (!queue)
		return (0);
	
	// 방문 맵 생성
	visited = create_visited_map(set);
	if (!visited)
	{
		free_queue(queue);
		return (0);
	}
	
	// 시작점 큐에 추가
	enqueue_point(queue, set->p_x, set->p_y);
	visited[set->p_y][set->p_x] = 1; // 시작 위치 방문 표시
	
	// BFS 시작
	while (queue->size > 0)
	{
		current = dequeue_point(queue);
		if (!current)
			break;
		
		// 현재 위치가 출구인지 확인
		if (set->map[current->y][current->x] == 'E')
		{
			found_exit = 1;
			free(current); // 마지막 포인트 해제
			break;
		}
		
		// 네 방향 탐색
		i = 0;
		while (i < 4)
		{
			nx = current->x + dx[i];
			ny = current->y + dy[i];
			
			// 유효한 위치이고, 벽이 아니며, 아직 방문하지 않은 경우
			if (nx >= 0 && nx < set->x && ny >= 0 && ny < set->y 
				&& set->map[ny][nx] != '1' && !visited[ny][nx])
			{
				visited[ny][nx] = 1; // 방문 표시
				enqueue_point(queue, nx, ny);
			}
			i++;
		}
		
		free(current); // 현재 포인트 해제
	}
	
	free_queue(queue);
	free_visited_map(visited, set->y);
	
	return (found_exit);
}

// 메인 검사 함수
void condition_check(t_set *set)
{
	if (!find_path_bfs(set))
		if_ret(1, set); // 경로를 찾지 못한 경우 에러 처리
}