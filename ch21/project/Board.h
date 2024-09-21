#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include <random>
#include <utility>
#include <array>
#include <vector>
#include <format>
#include <iostream>

template <int N>
class Board{
private:
    // int size{N};
    int m_freeTile{N*N-1};
    // std::array<std::array<int, N>, N> m_data{};
    std::array<int, N*N> m_data{};

public:
        Board() {
        int counter{ 0 };
        for (int i = 0; i < N*N; ++i) {
            m_data[i] = i+1; 
        }
        auto rd = std::random_device {}; 
        auto rng = std::default_random_engine { rd() };
        std::shuffle(m_data.begin(), m_data.end(), rng);
        m_freeTile = 0; // Initialize m_freeTile to a default value
    }

    // friend std::ostream& operator<<(std::ostream& out, const Board<N>& board){
    //     for (const auto& r : board.m_data) {
    //         for (const auto& val : r) {
    //             out << std::format("{:3}", val);
    //         }
    //         out << "\n";
        
    //     }
    //     return out;
    // }

    friend std::ostream& operator<<(std::ostream& out, const Board<N>& board){
        for (int i{0}; i < N*N; ++i) {
            if ( board.m_data[i] == N*N) {
                out << "  x";
                continue;
            }
            out << std::format("{:3d}", board.m_data[i]);
            if (i % N == N - 1)
                out << '\n';
        }
        
        return out;
    }

};

#endif