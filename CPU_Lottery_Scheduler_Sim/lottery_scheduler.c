#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "LList.h"
#define char_arr_size 20

int main() {
    int total_tickets = 0, total_process_len = 0;
    char plen_arr[char_arr_size];
    char ptick_arr[char_arr_size];
    int job_id_cnt = 0;
    int plen, ptick;

    srand(time(0));

    printf("\n------------Create Jobs------------\n\n");
    printf("1. Type in the length of the job, then the number of tickets\n\n");
    printf("2. Type in '0' for the job's length to stop creating new jobs\n\n");

    while(1) {

        printf("Job %c Length: ",job_id_cnt + 'A'); // Enter job's length
        scanf("%d", &plen);
        plen_arr[job_id_cnt] = plen;

        if (plen == 0) break;

        printf("Job %c Tickets: ",job_id_cnt + 'A'); // Enter job's ticket amount
        scanf("%d", &ptick);
        ptick_arr[job_id_cnt] = ptick;

        printf("\n");

        total_tickets = total_tickets + ptick; // Add job's ticket to total tickets
        total_process_len = total_process_len + plen; // Add job's length to total run length

        insert(job_id_cnt + 65, ptick, plen); // Insert new job with specified length and number of tickets into linked list

        job_id_cnt++;
    }
    printf("----------------------------------\n\n");

    printf("\n--------Created Jobs--------\n");
    display();
    printf("----------------------------\n\n");

    printf("--------Job Statistics--------\n");
    printf("Total Job Length: %d\n", total_process_len);
    printf("Total Tickets: %d\n", total_tickets);
    printf("------------------------------\n\n");

    node_t* current = head;

    int lower = 0; 
    int upper = total_tickets - 1;
    int count = 0;
    int winning_ticket = 0;

    Sleep(5000);

    while(1) {
        //fflush(stdout);
        Sleep(250);
        while (current) {
            if (current->job_length == 0) {
                    printf("\nJob %c Finished (Run time: %f%%)\n", current->job_id, ((current->run_count) * 100) / (total_process_len));
                    upper -= current->tickets;
                    current = remove_node(current);
            }
            else current = current->next;            
        }

        if(!head) break;
        printf("\n---------------------------------------");
        current = head;
        winning_ticket = (rand() % (upper - lower + 1)) + lower;
        printf("\nWinning Ticket: %d\n", winning_ticket);

        while (current) {
            count = count + current->tickets;

            if (count > winning_ticket) {
                current->job_length -= 1;
                current->run_count += 1;
                printf("Current Job: %c | Length: %d | Count: %d\n",current->job_id,current->job_length , count);
                break;  
            }
            current = current->next;   
        }

        count = 0;
        current = head;
        printf("---------------------------------------\n");
    }

    return 0;

}