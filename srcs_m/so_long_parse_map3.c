/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:10 by tnam              #+#    #+#             */
/*   Updated: 2023/03/04 17:19:43 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	11111\n
	10P01\n
	10001\n
	1E011\n
	11111\n
*/

/*
	* DFS 알고리즘 구현
	- 1. 현재 위치를 시작 지점으로 지정한다.
	- 2. 현재 위치를 방문했다고 표시해둔다.
	- 3. 현재 위치의 위쪽을 확인한다.
		3-1. 탈출 지점인 경우 : 탈출 지점을 찾았다고 표시 후, DFS를 중단한다. (return ;)
		3-2. 길이거나 수집품인 경우 : 해당 위치로 이동하여 DFS를 호출한다.
		3-3. 벽인 경우 : 4번으로 이동.
	- 4. 현재 위치의 오른쪽을 확인한다.
		3-1. 탈출 지점인 경우 : 탈출 지점을 찾았다고 표시 후, DFS를 중단한다. (return ;)
		3-2. 길이거나 수집품인 경우 : 해당 위치로 이동하여 DFS를 호출한다.
		3-3. 벽인 경우 : 5번으로 이동.
	- 5. 현재 위치의 아래쪽을 확인한다.
		3-1. 탈출 지점인 경우 : 탈출 지점을 찾았다고 표시 후, DFS를 중단한다. (return ;)
		3-2. 길이거나 수집품인 경우 : 해당 위치로 이동하여 DFS를 호출한다.
		3-3. 벽인 경우 : 6번으로 이동.
	- 6. 현재 위치의 왼쪽을 확인한다.
		3-1. 탈출 지점인 경우 : 탈출 지점을 찾았다고 표시 후, DFS를 중단한다. (return ;)
		3-2. 길이거나 수집품인 경우 : 해당 위치로 이동하여 DFS를 호출한다.
		3-3. 벽인 경우 : 7번으로 이동.
	- 7. DFS 종료 후 탈출 경로 없음 에러 출력.
*/

void	find_escape_path(t_info *info, int pos, bool *found_e, bool *visited)
{
	visited[pos] = TRUE;
	if (visited[pos - info->map_col] == FALSE && pos - info->map_col >= 0)
	{
		if (info->map[pos - info->map_col] == ESCAPE)
		{
			*found_e = 1;
			return ;
		}
		else if (info->map[pos - info->map_col] == FREE_SPACE
			|| info->map[pos - info->map_col] == COLLECTABLE)
			find_escape_path(info, pos - info->map_col, found_e, visited);
	}
	if (visited[pos + 1] == FALSE)
	{
		if (info->map[pos + 1] == ESCAPE)
		{
			*found_e = 1;
			return ;
		}
		else if (info->map[pos + 1] == FREE_SPACE
			|| info->map[pos + 1] == COLLECTABLE)
			find_escape_path(info, pos + 1, found_e, visited);
	}
	if (visited[pos + info->map_col] == FALSE)
	{
		if (info->map[pos + info->map_col] == ESCAPE)
		{
			*found_e = 1;
			return ;
		}
		else if (info->map[pos + info->map_col] == FREE_SPACE
			|| info->map[pos + info->map_col] == COLLECTABLE)
			find_escape_path(info, pos + info->map_col, found_e, visited);
	}
	if (visited[pos - 1] == FALSE)
	{
		if (info->map[pos - 1] == ESCAPE)
		{
			*found_e = 1;
			return ;
		}
		else if (info->map[pos - 1] == FREE_SPACE
			|| info->map[pos - 1] == COLLECTABLE)
			find_escape_path(info, pos - 1, found_e, visited);
	}
}
