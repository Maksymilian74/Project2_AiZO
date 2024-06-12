cmake_minimum_required(VERSION 3.27)
project(Projekt2_AiZO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt2_AiZO Main/Main.cpp
        Algorithms/Prim.cpp
        Algorithms/Prim.h
        Main/Menu.cpp
        Main/Menu.h
        Algorithms/Dijkstra.cpp
        Algorithms/Dijkstra.h
        Algorithms/BellmanFord.cpp
        Algorithms/BellmanFord.h
        Utils/FillStructure.cpp
        Utils/FillStructure.h
        Submenu/SimulationSolving.cpp
        Submenu/SimulationSolving.h
        Submenu/TestSolving.cpp
        Submenu/TestSolving.h
        Structures/IncidenceMatrix.cpp
        Structures/IncidenceMatrix.h
        Structures/AdjacencyList.cpp
        Structures/AdjacencyList.h
        Algorithms/Kruskal.cpp
        Algorithms/Kruskal.h
        Structures/MinHeap.cpp
        Structures/MinHeap.h
)

set(CMAKE_EXE_LINKER_FLAGS "-static")
