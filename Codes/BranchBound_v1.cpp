// 1. Import the libraries //
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
const int INF = 1000; // Infinity value

// Structure to represent a job
struct Job {
    int id; // Job ID
    vector<int> machines; // Processing times on machines
};

int timeCompute(const vector<Job>& schedule, const vector<vector<int>>& duration) {
    int numberJobs = schedule.size();
    int numberMachines = duration[0].size();

    vector<int> machineCompletionTimes(numberMachines, 0);
    vector<int> jobCompletionTimes(numberJobs, 0);

    for (const Job& job : schedule) {
        int jobId = job.id;
        int jobStartTime = jobCompletionTimes[jobId];
        for (int machineId = 0; machineId < numberMachines; ++machineId) {
            int machineStartTime = max(jobStartTime, machineCompletionTimes[machineId]);
            machineCompletionTimes[machineId] = machineStartTime + duration[jobId][machineId];
            jobCompletionTimes[jobId] = machineCompletionTimes[machineId];
        }
    }
    return *max_element(jobCompletionTimes.begin(), jobCompletionTimes.end());
}

// Branch and bound function
void branchAndBound(const vector<vector<int>>& duration, vector<Job>& currentSchedule, int currentMakespan,
                    vector<Job>& bestSchedule, int& bestMakespan, vector<bool>& visited, int depth) {
    int numberJobs = duration.size();

    if (depth == numberJobs) {
        if (currentMakespan < bestMakespan) {
            bestMakespan = currentMakespan;
            bestSchedule = currentSchedule;
        }
        return;
    }

    for (int jobId = 0; jobId < numberJobs; ++jobId) {
        if (!visited[jobId]) {
            visited[jobId] = true;
            currentSchedule[depth] = {jobId, duration[jobId]};
            int newMakespan = timeCompute(currentSchedule, duration);
            if (newMakespan < bestMakespan) branchAndBound(duration, currentSchedule, newMakespan, bestSchedule, bestMakespan, visited, depth + 1);
            visited[jobId] = false; 
        }
    }
}

int main() {
    int numberJobs, numberMachines;
    cout << "Enter the number of jobs: ";
    cin >> numberJobs; 
    cout << "Enter the number of machines: ";
    cin >> numberMachines;

    vector<vector<int>> duration(numberJobs, vector<int>(numberMachines));
    cout << "Enter the processing times for each job and machine:\n";
    for (int i = 0; i < numberJobs; ++i) {
        for (int j = 0; j < numberMachines; ++j) {
            cin >> duration[i][j];
        }
    }

    vector<Job> currentSchedule(numberJobs);
    vector<Job> bestSchedule(numberJobs);
    vector<bool> visited(numberJobs,true);
    int bestMakespan = INF;
    branchAndBound(duration, currentSchedule, 0, bestSchedule, bestMakespan, visited, 0);
    return 0;
}
