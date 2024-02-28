#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Task Scheduler with Priority Queue
// Work in progress

enum class TaskState { READY, RUNNING, BLOCKED, COMPLETED };

TaskState stringToTaskState(const std::string &state) {
  if (state == "READY") {
    return TaskState::READY;
  } else if (state == "RUNNING") {
    return TaskState::RUNNING;
  } else if (state == "BLOCKED") {
    return TaskState::BLOCKED;
  } else if (state == "COMPLETED") {
    return TaskState::COMPLETED;
  } else {
    throw std::invalid_argument("Invalid state string: " + state);
  }
}

struct Task {
  TaskState state;
  int start_time;
  int end_time;
  Task(int start_time, int end_time)
      : start_time(start_time), end_time(end_time) {
    state = TaskState::READY;
  }
};

// Read the string vector into multiple vectors for start time, end time, and
// function action
void parse_task_log(std::vector<std::string> &tasks) {
  // Iterate over tasks
  for (size_t i = 0; i < tasks.size(); i++) {
    std::cout << tasks[i] << std::endl;
  }
}

// Read the task log into a string vector
std::vector<std::string> get_task_log() {
  std::string task;
  std::vector<std::string> tasks;
  std::ifstream tasks_file("tasks.txt");

  while (std::getline(tasks_file, task)) {
    if (task != "" && task != "\n") {
      tasks.push_back(task);
    }
  }
  std::cout << "Found " << tasks.size() << " tasks to load\n";
  return tasks;
}

int main() {
  std::cout << "Task Scheduling\n";
  std::vector<std::string> tasks = get_task_log();
  parse_task_log(tasks);
}
