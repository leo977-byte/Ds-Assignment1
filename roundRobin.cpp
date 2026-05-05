#include <bits/stdc++.h>
using namespace std;


struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void calculateRemainingTime(vector<Process>& processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
}

void calculateTurnAroundTime(vector<Process>& processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void calculateWaitTime(vector<Process>& processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

double calculateAvgWaitingTime(vector<Process> p, int n) {
    double sum=0;
    double avgWaitingTime=0;
    for (int i = 0; i < n; i++) {
        sum+=p[i].waiting_time;
    }
    avgWaitingTime = sum/n;
    return avgWaitingTime;
}

void printQueueUpdates(queue<Process> q, int n) {
    vector<Process> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    cout << "Queue Updates: \n";
    cout << "[ ";
    for (int i = 0; i < temp.size(); i++) {
        cout << 'P' << temp[i].id;
        if (i != temp.size()-1) cout << ", ";
    }
    if (temp.empty()) cout << "EMPTY";
    cout << " ]\n";
}

void printTable(vector<Process> p, int n) {
    cout << "Process   Completion Time   Turnaround Time   Waiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << 'P' << p[i].id << "                 "
        << p[i].completion_time << "                "
        << p[i].turnaround_time << "                "
        << p[i].waiting_time;
        cout << '\n' << '\n';
    }
    cout << "Average Waiting Time: " << calculateAvgWaitingTime(p, n) << '\n';
}




queue<Process> processQueue;
vector<Process> processes;
int time_quantum;
int current_time=0;

 int main() {

    cout << "Time Quantum:  ";
    cin >> time_quantum;

    cout << '\n' << "Number of Processes: ";
    int num_of_processes; cin >> num_of_processes;

    for (int i = 0; i < num_of_processes; i++){
        Process process;
        cout << "Arrival Time, Needed Time P" << i+1 << ": ";
        int arrival_time, needed_time;
        cin >> arrival_time >> needed_time;
        process.id = i+1;
        process.arrival_time = arrival_time;
        process.burst_time = needed_time;
        processes.push_back(process);
    }

    calculateRemainingTime(processes, num_of_processes);

     vector<bool> added(num_of_processes, false);
     int completed = 0;
     while (current_time < processes[0].arrival_time) {
         current_time++;
     }

    while (completed < num_of_processes) {
        for (int j = 0; j < num_of_processes; j++) {
            if (processes[j].arrival_time <= current_time && !added[j]) {
                processQueue.push(processes[j]);
                added[j] = true;
                printQueueUpdates(processQueue, num_of_processes);
            }
        }


        if (processQueue.empty()) {
            current_time++;
            continue;
        }

        Process current = processQueue.front();
        int time = min(time_quantum, current.remaining_time);
        current_time += time;
        current.remaining_time -= time;
        processQueue.pop();

        if (current.remaining_time > 0) {
            for (int j = 0; j < num_of_processes; j++) {
                if (processes[j].arrival_time <= current_time && !added[j]) {
                    processQueue.push(processes[j]);
                    added[j] = true;
                }
            }
            processQueue.push(current);
        }
        else {
            current.completion_time = current_time;
            processes[current.id-1] = current;
            completed++;
        }
        printQueueUpdates(processQueue, num_of_processes);
    }

    calculateTurnAroundTime(processes, num_of_processes);
    calculateWaitTime(processes, num_of_processes);
    printTable(processes, num_of_processes);

}