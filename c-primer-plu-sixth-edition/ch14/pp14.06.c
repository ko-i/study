// 2020-11-13 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 20
#define PLAYERNUM 19
#define RECORDLEN 200
#define LINESIZE 100

struct bbplayer
{
	int id;   // 0~18
	char fname[NAMELEN];
	char lname[NAMELEN];
	int play_cnt;
	int hit_cnt;
	int walk_cnt;
	int rbi;
};

int main(void)
{
	struct bbplayer players[PLAYERNUM];

	for(int i = 0; i < PLAYERNUM; i++)
	{
		players[i].id = i;
		players[i].play_cnt = 0;
		players[i].hit_cnt = 0;
		players[i].walk_cnt = 0;
		players[i].rbi = 0;
	}

	FILE * fp;
	char * file = "bbp";

	if((fp = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Open file %s failed.\n", file);
		exit(EXIT_FAILURE);
	}

	int count = 0;
	char st[LINESIZE];
	int temp_id;
	char temp_fname[NAMELEN];
	char temp_lname[NAMELEN];
	int temp_play_cnt;
	int temp_hit_cnt;
	int temp_walk_cnt;
	int temp_rbi;
	while(fgets(st, LINESIZE, fp) != NULL && st[0] != '\n')
	{
		sscanf(st, "%d %s %s %d %d %d %d", &temp_id, temp_fname, temp_lname, &temp_play_cnt, &temp_hit_cnt, &temp_walk_cnt, &temp_rbi);
		strcpy(players[temp_id].fname, temp_fname);
		strcpy(players[temp_id].lname, temp_lname);
		players[temp_id].play_cnt += temp_play_cnt;
		players[temp_id].hit_cnt += temp_hit_cnt;
		players[temp_id].walk_cnt += temp_walk_cnt;
		players[temp_id].rbi += temp_rbi;
		count++;
	}

	fclose(fp);

	double result[PLAYERNUM];
	for(int i = 0; i < PLAYERNUM; i++)
	{
		if(players[i].play_cnt == 0)
		{
			result[i] = 0.0;
		}
		else
		{
			result[i] = (double)players[i].hit_cnt / players[i].play_cnt;
		}

		printf("%d %s %s %d %d %d %d %.2lf\n", players[i].id, players[i].fname, players[i].lname, players[i].play_cnt, players[i].hit_cnt, players[i].walk_cnt, players[i].rbi, result[i]);
	}

	return 0;
}