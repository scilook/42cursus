/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:04:09 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/23 14:04:38 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * 수정된 경로 탐색 알고리즘
 * BFS(너비 우선 탐색)를 사용해 플레이어(P)부터 출구(E)까지의 경로를 찾습니다.
 */

#include "so_long.h"

// 방문 여부를 추적하는 2차원 배열 생성
static size_t	**visited_map(t_set *set)
{
	size_t	**visited;
	size_t	i;

	visited = (size_t **)malloc(sizeof(size_t *) * set->y);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < set->y)
	{
		visited[i] = (size_t *)malloc(sizeof(size_t) * set->x);
		if (!visited[i])
		{
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		ft_memset(visited[i], 0, sizeof(size_t) * set->x);
		i++;
	}
	return (visited);
}

static void	free_visited_map(int **visited, int y)
{
	size_t	i;

	i = 0;
	while (i < y)
		free(visited[i++]);
	free(visited);
}

static void	enqueue_point(t_list **queue, int x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return ;
	point->x = x;
	point->y = y;

	if (*queue == NULL)
		*queue = ft_lstnew(point);
	else
		ft_lstadd_back(queue, ft_lstnew(point));
}

// 큐에서 첫 번째 요소 제거 및 반환
static t_point *dequeue_point(t_list **queue)
{
	t_list *temp;
	t_point *point;
	
	if (!*queue)
		return (NULL);
	
	temp = *queue;
	point = temp->content;
	*queue = temp->next;
	
	// 노드만 해제하고 content는 유지 (반환용)
	free(temp);
	
	return (point);
}

// BFS 알고리즘으로 경로 탐색
int find_path_bfs(t_set *set)
{
	t_list *queue = NULL;
	t_point *current;
	int **visited;
	int dx[4] = {-1, 0, 1, 0}; // 좌, 상, 우, 하
	int dy[4] = {0, -1, 0, 1};
	int i, nx, ny;
	int found_exit = 0;

	// 방문 맵 생성
	visited = create_visited_map(set);
	if (!visited)
		return (0);
	
	// 시작점 큐에 추가
	enqueue_point(&queue, set->p_x, set->p_y);
	visited[set->p_y][set->p_x] = 1; // 시작 위치 방문 표시
	
	// BFS 시작
	while (queue)
	{
		current = dequeue_point(&queue);
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
				enqueue_point(&queue, nx, ny);
			}
			i++;
		}
		
		free(current); // 현재 포인트 해제
	}
	
	// 남은 큐 정리
	while (queue)
	{
		current = dequeue_point(&queue);
		if (current)
			free(current);
	}
	
	free_visited_map(visited, set->y);
	
	return (found_exit);
}

// 메인 검사 함수
void condition_check(t_set *set)
{
	if (!find_path_bfs(set))
		if_ret(1, set); // 경로를 찾지 못한 경우 에러 처리
}
