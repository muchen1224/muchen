#include<stdio.h>
#include<stdlib.h>
struct softball_player {
    char first_name[128];
    char last_name[128];
    int play_times;
    int hit_times;
    int run_bar_times;
    int rbi;
    double hit_rate;
};
void main(void)
{
    struct softball_player players[19] = { {'\0', '\0', 0, 0, 0, 0, 0.0} };
    FILE *fp;
    char file_name[128];
    struct softball_player player;
    int player_number;

    printf("Enter the file name: ");
    fgets(file_name, 128,stdin);

    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("Can't open the %s.\n", file_name);
    }

    while (feof(fp) == 0)
    {
        fscanf(fp, "%d", &player_number);
        fscanf(fp, "%s", &player.first_name);
        fscanf(fp, "%s", &player.last_name);
        fscanf(fp, "%d", &player.play_times);
        fscanf(fp, "%d", &player.hit_times);
        fscanf(fp, "%d", &player.run_bar_times);
        fscanf(fp, "%d", &player.rbi);
        if (players[player_number].first_name[0] == '\0')
        {
            players[player_number] = player;
        }
        else
        {
            players[player_number].play_times += player.play_times;
            players[player_number].hit_times += player.hit_times;
            players[player_number].run_bar_times += player.run_bar_times;
            players[player_number].rbi += player.rbi;
        }
    }

    for (int i = 0; i < 19; i++)
    {
        if (players[i].first_name[0] != '\0')
        {
            players[i].hit_rate = (double)players[i].hit_times / players[i].play_times;
        }
    }

    for (int i = 0; i < 19; i++)
    {
        if (players[i].first_name[0] != '\0')
        {
            printf("Player:%s %s, play times: %d, hit times: %d, run barrier times: %d, rbi: %d, hit_rate: %.2lf\n",
                    players[i].first_name, players[i].last_name, players[i].play_times, players[i].hit_times, players[i].run_bar_times, players[i].rbi, 
                    players[i].hit_rate);
        }
    }
    system("pause");
    return 0;
}
