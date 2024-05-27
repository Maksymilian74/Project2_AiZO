cmake_minimum_required(VERSION 3.27)
project(Projekt2_AiZO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt2_AiZO main.cpp
        MstAlgorithms.cpp
        MstAlgorithms.h
        Menu.cpp
        Menu.h
        ShortestPathAlgorithms.cpp
        ShortestPathAlgorithms.h
        MaxFlowAlgorithms.cpp
        MaxFlowAlgorithms.h
        FillStructure.cpp
        FillStructure.h
        SimulationSolving.cpp
        SimulationSolving.h
        TestSolving.cpp
        TestSolving.h
        IncidenceMatrix.cpp
        IncidenceMatrix.h
        AdjacencyList.cpp
        AdjacencyList.h)
