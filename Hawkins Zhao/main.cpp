//
//  main.cpp
//  robot
//
//  Created by Hawkins Zhao on 08/11/2017.
//  Copyright © 2017 iosclub. All rights reserved.
//

#include <iostream>
#include <cfloat>
#include <cmath>
#include <string>
#include <numeric>

// Ratio list
const double ARM_RATIO = 2;
const double MASS_RATIO = 0.5;
const double ENGINE_RATIO = 3;
const double BATTERY_RATIO = 3;

// Weight list
const double ARM_WEIGHT = 1;
const double BASE_WEIGHT = 2;
const double ENGINE_WEIGHT = 1;
const double BATTERY_WEIGHT = 0.5;

// Package parameters
const double LOAD_TIME = 2;
const double DISTENCE = 10;
const double PACKAGE_WEIGHT = 20;

const int BREAKER = 3;
int LOGER_TYPE = 1;

void robotLogger(double arm, double engine, double battery) {
    if (LOGER_TYPE == 0) {
        std::cout << arm << ", " << engine << ", " << battery << ", " << DBL_MAX << std::endl;
        return;
    }
    
    std::cout   << "Testing robot: "
                << arm << " arm, "
                << engine << " engine "
                << battery << " battery, failed!"
                << std::endl;
}

void robotLogger(double arm, double engine, double battery, double finished_time) {
    if (LOGER_TYPE == 0) {
        std::cout << arm << ", " << engine << ", " << battery << ", " << finished_time << std::endl;
        return;
    }
    
    std::cout   << "Testing robot: "
                << arm << " arm, "
                << engine << " engine, "
                << battery << " battery, "
                << "finished at time:" << finished_time
                << std::endl;
}

void robotLogger(std::string prefix,double arm, double engine, double battery, double finished_time) {
    if (LOGER_TYPE == 0) {
        return;
    }
    
    std::cout   << prefix << std::endl
                << "Best robot: "
                << arm << " arm, "
                << engine << " engine, "
                << battery << " battery, "
                << "finished at time: " << finished_time
                << std::endl;
}

double timeCalculation(double arm, double engine, double battery) {
    // Error value
    if (arm < 1 || arm > 9) { robotLogger(arm, engine, battery); return DBL_MAX; }
    if (engine < 1 || engine > 9) { robotLogger(arm, engine, battery); return DBL_MAX; }
    if (battery < 1 || battery > 9) { robotLogger(arm, engine, battery); return DBL_MAX; }
    
    // Calculating velocity
    double v_inbound = engine * ENGINE_RATIO - (
                         arm * ARM_WEIGHT +
                         engine * ENGINE_WEIGHT +
                         battery * BATTERY_WEIGHT +
                         BASE_WEIGHT) * MASS_RATIO;
    
    double v_outbound = engine * ENGINE_RATIO - (
                         arm * (ARM_WEIGHT + ARM_RATIO) +
                         engine * ENGINE_WEIGHT +
                         battery * BATTERY_WEIGHT +
                         BASE_WEIGHT) * MASS_RATIO;
    
    // Incorrect velocity
    if (v_inbound <= 0 || v_outbound <= 0) {
        robotLogger(arm, engine, battery);
        return DBL_MAX;
    }
    
    // Calculating time
    double t_inbound = DISTENCE / v_inbound;
    double t_outbound = DISTENCE / v_outbound;
    double t_total = t_inbound + t_outbound + LOAD_TIME;
    
    // How many times does the robot need to work
    int times = ceil(PACKAGE_WEIGHT / (arm * ARM_RATIO));
    double finish_time = times * t_total;
    
    // Check time if longer than battery could provide
    if (finish_time > battery * BATTERY_RATIO) {
        robotLogger(arm, engine, battery);
        return DBL_MAX;
    }
    
    robotLogger(arm, engine, battery, finish_time);
    
    return finish_time;
}

void darwinApproach() {
    // Switch to full log mode
    LOGER_TYPE = 1;
    
    int buffer[3] = {5, 5, 5};
    int best[3] = {0, 0, 0};
    double minTime = DBL_MAX;
    
    int ratio = 1;
    
    // Init buffer
    int direction[3] = {0, 0, 0};
    while (ratio < BREAKER) {
        // Adjust direction
        for (int i = 0; i < 3; i++) {
            buffer[i] += direction[i];
            best[i] = buffer[i];
            direction[i] = 0;
        }
        
        // Find direction
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                for (int z = -1; z <= 1; z++) {
                    double time = timeCalculation(buffer[0] + x * ratio, buffer[1] + y * ratio, buffer[2] + z * ratio);
                    if (time < minTime) {
                        minTime = time;
                        direction[0] = x * ratio;
                        direction[1] = y * ratio;
                        direction[2] = z * ratio;
                        robotLogger("---> New minimum time found! ", buffer[0] + x, buffer[1] + y, buffer[2] + z, time);
                        ratio = 1;
                    }
                }
            }
        }
        
        if (std::accumulate(std::begin(direction), std::end(direction), 0, std::plus<int>()) == 0) ratio += 1;
    }
    robotLogger("---> Calculation finished!", best[0], best[1], best[2], minTime);
}

void enumeration() {
    // Switch to csv log mode
    LOGER_TYPE = 0;
    
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            for (int k = 1; k < 10; k++)
                timeCalculation(i, j, k);
}

int main(int argc, const char * argv[]) {
    darwinApproach();
    // Uncomment this line for csv output
    // enumeration();
    return 0;
}
