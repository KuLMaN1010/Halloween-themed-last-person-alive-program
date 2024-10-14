#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Queue.h"
#include <vector>
#include <string>

class Simulation : private Queue<string> {
private:
    vector<string> eliminated;
    string survivor;
    int skip_number;

public:
  
    Simulation(vector<string> people, int skipNum) {
        RunNewSimulation(people, skipNum);
    }

    void RunNewSimulation(vector<string> people, int skipNum) {
        Clear();
        eliminated.clear();
        skip_number = skipNum;

        for (const auto& person : people) {
            Enqueue(person);
        }

        RunSimulation();
    }

    void RunSimulation() {
        string temp;
        while (GetCount() > 1) {
            
            for (int i = 1; i < skip_number; ++i) {
                Dequeue(temp);
                Enqueue(temp);
            }
            Dequeue(temp);
            eliminated.push_back(temp);
        }
        
        Dequeue(survivor);
    }

    vector<string> GetEliminationList() const {
        return eliminated;
    }

    string GetSurvivor() const {
        return survivor;
    }
};

#endif // SIMULATION_H

