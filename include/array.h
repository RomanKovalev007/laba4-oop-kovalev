#pragma once

#include "figure.h"
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <memory>

template<class FigureType>
concept Arrayable = std::is_base_of_v<Figure<typename FigureType::value_type>, FigureType>;

template<Arrayable FigureType>
class Array {
public:
    using value_type = FigureType;
    
    Array() = default;
    
    Array(size_t cap){
        size = 0;
        capacity = (cap == 0) ? 1 : (cap * 2);
        figures = std::make_unique<std::shared_ptr<FigureType>[]>(capacity);
        std::fill_n(figures.get(), capacity, nullptr);
    };

    Array(std::initializer_list<std::shared_ptr<FigureType>> list) {
        size = list.size();
        capacity = (size == 0) ? 1 : (size * 2);
        figures = std::make_unique<std::shared_ptr<FigureType>[]>(capacity);
        std::fill_n(figures.get(), capacity, nullptr);
        std::copy(list.begin(), list.end(), figures.get());
    };

    Array(Array&& other) noexcept
        : figures(std::move(other.figures)), size(other.size), capacity(other.capacity) {
        other.size = 0;
        other.capacity = 0;
    };
    
    Array(const Array& other) {
        size = other.size;
        capacity = other.capacity;
        figures = std::make_unique<std::shared_ptr<FigureType>[]>(capacity);
        std::fill_n(figures.get(), capacity, nullptr);
        for (size_t i = 0; i < size; ++i) {
            if (other.figures[i]) {
                auto cloned = other.figures[i]->clone();
                figures[i] = std::shared_ptr<FigureType>(
                    dynamic_cast<FigureType*>(cloned.release())
                );
            }
        }
    };

    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        Array temp(other);
        swap(temp);
        return *this;
    };

    Array& operator=(Array&& other) noexcept {
        if (this == &other) return *this;
        figures = std::move(other.figures);
        size = other.size;
        capacity = other.capacity;

        other.size = 0;
        other.capacity = 0;
        return *this;
    };

    ~Array() = default;

    void push(std::shared_ptr<FigureType> figure) {
        if (size >= capacity) {
            resize();
        }
        figures[size++] = figure;
    };

    std::shared_ptr<FigureType>& operator[](size_t index){
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return figures[index];
    };
    
    const std::shared_ptr<FigureType>& operator[](size_t index) const{
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return figures[index];
    };

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            figures[i] = figures[i + 1];
        }
        --size;
        figures[size] = nullptr;
    };

    size_t getSize() const{
        return size;
    };

    size_t getCapacity() const{
        return capacity;
    };

    bool isEmpty() const {
        return size == 0;
    }

    void print(std::ostream& os) const {
        for (size_t i = 0; i < size; ++i) {
            if (figures[i]) {
                os << *figures[i] << std::endl;
            }
        }
    };

    double totalArea() const{
        double total = 0.0;
        for (size_t i = 0; i < size; ++i) {
            if (figures[i]) {
                total += figures[i]->area();
            }
        }
        return total;
    };

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        arr.print(os);
        return os;
    }

private:
    std::unique_ptr<std::shared_ptr<FigureType>[]> figures{nullptr};
    size_t size{0};
    size_t capacity{0};
    
    void resize(){
        capacity = (capacity == 0) ? 1 : capacity * 2;
        auto new_figures = std::make_unique<std::shared_ptr<FigureType>[]>(capacity);
        std::fill_n(new_figures.get(), capacity, nullptr);
        for (size_t i = 0; i < size; ++i) {
            new_figures[i] = figures[i];
        }
        figures = std::move(new_figures);
    };

    void swap(Array& other) noexcept {
        std::swap(figures, other.figures);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    };
};