#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H

#include <vector>

class MagicalContainer {
private:
    std::vector<int> elements;

public:
    void addElement(int element);
    void removeElement(int element);
    int size() const;
    const std::vector<int> getElements() const;
};
    class AscendingIterator {
    private:
        const MagicalContainer& container;
        std::vector<int> sortedElements;

    public:
        class iterator {
        private:
            std::vector<int>::const_iterator it;

        public:
            iterator(std::vector<int>::const_iterator iter);

            int operator*() const;
            iterator& operator++();
            bool operator!=(const iterator& other) const;
        };

        AscendingIterator(const MagicalContainer& cont);
        iterator begin() const;
        iterator end() const;
    };

    class SideCrossIterator {
    private:
        const MagicalContainer& container;
        std::vector<int> crossOrderElements;

    public:
        class iterator {
        private:
            std::vector<int>::const_iterator it;

        public:
            iterator(std::vector<int>::const_iterator iter);

            int operator*() const;
            iterator& operator++();
            bool operator!=(const iterator& other) const;
        };

        SideCrossIterator(const MagicalContainer& cont);
        iterator begin() const;
        iterator end() const;
    };

    class PrimeIterator {
    private:
        const MagicalContainer& container;
        std::vector<int> primeElements;

        bool isPrime(int number);

    public:
        class iterator {
        private:
            std::vector<int>::const_iterator it;

        public:
            iterator(std::vector<int>::const_iterator iter);

            int operator*() const;
            iterator& operator++();
            bool operator!=(const iterator& other) const;
        };

        PrimeIterator(const MagicalContainer& cont);
        iterator begin() const;
        iterator end() const;
    };

#endif  
