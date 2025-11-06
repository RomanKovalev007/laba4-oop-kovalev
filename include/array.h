#pragma once

#include "figure.h"
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <utility>


template<class Figure>
concept Arrayable = std::is_class_v<Figure>;

template<Arrayable Figure>
class Array {
    public:
        Array() = default;
        
        Array(size_t cap){
            size = 0;
            capacity = (cap == 0) ? 1 : (cap * 2);
            figures = std::make_shared<std::shared_ptr<Figure>[]>(capacity);
            std::fill_n(figures.get(), capacity, nullptr);
        };

        Array(std::initializer_list<std::shared_ptr<Figure>> list) {
            size = list.size();
            capacity = (size == 0) ? 1 : (size * 2);
            figures = std::make_shared<std::shared_ptr<Figure>[]>(capacity);
            std::fill_n(figures.get(), capacity, nullptr);
            std::transform(list.begin(), list.end(), figures,
                        [](Figure* fig) { return (fig ? fig->clone() : nullptr); });
        };

        Array(Array&& other) noexcept
            : figures(other.figures), size(other.size), capacity(other.capacity) {
            other.figures.reset();
            other.size = 0;
            other.capacity = 0;
        };
        

        Array(const Array& other) {
            size = other.size;
            capacity = other.capacity;
            figures = std::make_shared<std::shared_ptr<Figure>[]>(capacity);
            std::fill_n(figures.get(), capacity, nullptr);
            for (size_t i = 0; i < size; ++i) {
                figures[i] = other.figures[i] ? other.figures[i]->clone() : nullptr;
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
            figures.reset();

            figures = other.figures;
            size = other.size;
            capacity = other.capacity;

            other.figures.reset();
            other.size = 0;
            other.capacity = 0;
            return *this;
        };

        ~Array() {
            figures.reset();
        };

        void push(std::shared_ptr<Figure> figure) {
            if (size >= capacity) {
                resize();
            }
            figures[size++] = figure;
        };
        


        std::shared_ptr<Figure>& operator[](size_t index){
        if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return figures[index];
        };
        

        const std::shared_ptr<Figure>& operator[](size_t index) const{
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return figures[index];
        };

        // Функция для удаления фигуры из массива по индексу.
        void remove(size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            figures[index].reset(); // Освобождение shared_ptr.
            for (size_t i = index; i < size - 1; ++i) {
                figures[i] = figures[i + 1]; // Сдвиг элементов влево.
            }
            --size;
            if (size >= 0) figures[size] = nullptr;
        };

        size_t getSize() const{
            return size;
        };

        size_t getCapacity() const{
            return capacity;
        };

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

    private:
        std::shared_ptr<std::shared_ptr<Figure>[]> figures{nullptr};
        size_t size{0};
        size_t capacity{0};
        void resize(){
            capacity = (capacity == 0) ? 1 : capacity * 2;
            std::shared_ptr<std::shared_ptr<Figure>[]> new_figures = std::make_shared<std::shared_ptr<Figure>[]>(capacity);
            std::fill_n(new_figures.get(), capacity, nullptr);
            for (size_t i = 0; i < size; ++i) {
                new_figures[i] = figures[i];
            }
            figures.reset();
            figures = new_figures;
        };

        void swap(Array& other) noexcept {
            std::swap(figures, other.figures);
            std::swap(size, other.size);
            std::swap(capacity, other.capacity);
        };
};