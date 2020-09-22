#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t number;
  size_t bt0;  // burst time
  size_t bt;   // remaining time
  size_t at;
  size_t et;
  size_t rt;
  size_t wt;
  size_t tat;
} task_t;

static size_t n;
static size_t q;
static task_t* tasks;

static size_t current_tick;
static task_t* current_task;
static size_t current_i;
static size_t remaining_q;

static int should_run_next() {
  size_t i;
  int should_continue = 0;
  for (i = 0; i < n; ++i) {
    if ((tasks + i)->bt > 0) {
      should_continue = 1;
      break;
    }
  }
  return should_continue;
}

static void select_next_task() {
  // RoundRobin
  if (current_task) {
    current_task = NULL;
  }
  current_i = (current_i + 1) % n;  // the next task

  while (current_task == NULL) {
    if ((tasks + current_i)->at <= current_tick &&
        (tasks + current_i)->bt > 0) {  // if the task can be runned
      current_task = tasks + current_i;
    } else {
      current_i = (current_i + 1) % n;
    }
  }

  remaining_q = q;
}

static void run() {
  size_t i;

  current_i = n - 1;  // when selecting the task i'll be 0
  current_tick = 0;
  current_task = NULL;
  remaining_q = q;

  while (1) {
    if (current_task) {
      --remaining_q;
      if (current_task->bt == 0) {
        current_task->et = current_tick;
        current_task->tat = current_task->et - current_task->at;
        current_task->wt = current_task->tat - current_task->bt0;
        current_task = NULL;
        remaining_q = q;
      }
    }

    if (remaining_q == 0) {
      if (!should_run_next()) return;
      select_next_task();  // selecting the next task
    }

    if (current_task == NULL) {
      if (!should_run_next()) return;

      select_next_task();  // selecting the task for the first time

      if (current_task) {
        current_task->rt = current_tick - current_task->at;
      }
    }

    printf("tick: %3zu | ", current_tick);
    for (i = 0; i < n; ++i) {
      if ((tasks + i)->at > current_tick)
        printf(".");
      else if ((tasks + i) == current_task)
        printf("+");
      else if ((tasks + i)->bt == 0)
        printf(" ");
      else
        printf("-");

      printf(" | ");
    }
    printf("\n");

    if (current_task) {
      current_task->bt--;
    } else {
    }

    ++current_tick;
  }
}

int main(int argc, char const* argv[]) {
  scanf("%zu", &q);  // the quantum
  scanf("%zu", &n);  // the number of processes
  tasks = (task_t*)calloc(n, sizeof(task_t));

  size_t i;
  for (i = 0; i < n; ++i) {
    scanf("%zu", &((tasks + i)->at));   // arrival time
    scanf("%zu", &((tasks + i)->bt0));  // burst time
    (tasks + i)->bt = (tasks + i)->bt0;
    (tasks + i)->number = i;
  }

  printf(
      "\n"
      "Execution table: "
      "('+' = running, "
      "'-' = waiting, "
      "'.' = not yet arrived, "
      "' ' = completed)\n");

  run();

  double tat_total = 0;
  double wt_total = 0;

  printf("\n");
  printf("Per-task stats: \n");
  printf("Task | CT | TAT | WT\n");
  for (i = 0; i < n; ++i) {
    task_t* ti = tasks + i;
    printf("%4zu | %2zu | %3zu | %2zu\n", ti->number, ti->et, ti->tat, ti->wt);
    tat_total += (double)ti->tat;
    wt_total += (double)ti->wt;
  }

  printf("\n");
  printf("Avg TAT: %lf\n", tat_total / n);
  printf("Avg WT: %lf\n", wt_total / n);
  return 0;
}
