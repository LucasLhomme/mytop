/*
** EPITECH PROJECT, 2024
** get the status
** File description:
** get the status of all PID file
*/

#include "my.h"
#include "struct.h"

void update_counts(count_file_t *count, char *state)
{
    switch (state[0]) {
        case 'R':
            count->running_count++;
            break;
        case 'S':
        case 'I':
        case 'D':
        case 'W':
            count->sleep_count++;
            break;
        case 'T':
            count->stopped_count++;
            break;
        case 'Z':
            count->zombie_count++;
            break;
    }
}

void parse_state_line(char *line, count_file_t *count)
{
    char *state = line + 7;

    state[strcspn(state, "\n")] = '\0';
    while (*state == ' ')
        state++;
    update_counts(count, state);
}

int process_file(const char *path, count_file_t *count)
{
    FILE *status_file = fopen(path, "r");
    char line[256];

    while (fgets(line, sizeof(line), status_file) != NULL) {
        if (strncmp(line, "State:", 6) == 0) {
            parse_state_line(line, count);
            break;
        }
    }
    fclose(status_file);
    return (0);
}

int process_directory(DIR *proc_dir, count_file_t *count)
{
    struct dirent *entry;
    char path[512];

    for (entry = readdir(proc_dir); entry != NULL; entry = readdir(proc_dir)) {
        if (!check_strisnum(entry->d_name[0]))
            continue;
        snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
        process_file(path, count);
    }
    return (0);
}

int check_status(void)
{
    DIR *proc_dir = opendir("/proc");
    count_file_t count = {0, 0, 0, 0, 0};

    process_directory(proc_dir, &count);
    closedir(proc_dir);
    mvprintw(1, 18, "running %d, %d sleeping, %d stopped, %d zombies",
        count.running_count, count.sleep_count,
            count.zombie_count, count.stopped_count);
    refresh();
    return (0);
}
