#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
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
  int task_id;
  TaskState state;
  int start_time;
  int end_time;
  Task(int task_id, TaskState state, int time)
      : task_id(task_id), state(state) {
    switch (state) {
    case TaskState::RUNNING: {
      start_time = time;
      break;
    }
    case TaskState::COMPLETED: {
      end_time = time;
      break;
    }
    default:
      break;
    }
  }
  int get_start_time() { return start_time; }
  int get_end_time() { return end_time; }
};

// Read the string vector into multiple vectors for start time, end time, and
// function action
std::stack<Task> parse_task_log(std::vector<std::string> &tasks) {
  std::stack<Task> active_tasks;
  // Iterate over tasks
  for (size_t i = 0; i < tasks.size(); i++) {
    std::string task_id, action, time;
    char sep = ':';
    std::istringstream iss(tasks[i]);
    std::getline(iss, task_id, sep);
    std::getline(iss, action, sep);
    std::getline(iss, time, sep);

    if (action == "start") {
      Task new_task(std::stoi(task_id), TaskState::RUNNING, std::stoi(time));
      active_tasks.push(new_task);
    }
    if (action == "stop") {
      // pop from the FIFO stack
      std::cout << "Ending task " << active_tasks.top().task_id
                << " which started at " << active_tasks.top().get_start_time()
                << std::endl;
      active_tasks.pop();
    }

    std::cout << tasks[i] << std::endl;
  }
  return active_tasks;
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
