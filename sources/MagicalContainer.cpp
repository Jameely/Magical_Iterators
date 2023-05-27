#include "MagicalContainer.h"
#include "algorithm"

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {}

int MagicalContainer::size() const { return 0; }

const std::vector<int> MagicalContainer::getElements() const {    return this->elements;   }

AscendingIterator::AscendingIterator(const MagicalContainer& cont) : container(cont) { }

AscendingIterator::iterator::iterator(std::vector<int>::const_iterator iter) : it(iter) { }

int AscendingIterator::iterator::operator*() const {   return *it; }

AscendingIterator::iterator& AscendingIterator::iterator::operator++() {    return *this;   }

bool AscendingIterator::iterator::operator!=(const iterator& other) const {    return it != other.it;}

AscendingIterator::iterator AscendingIterator::begin() const {    return iterator(sortedElements.begin());}

AscendingIterator::iterator AscendingIterator::end() const {    return iterator(sortedElements.end());  }

SideCrossIterator::SideCrossIterator(const MagicalContainer& cont) : container(cont) { }

SideCrossIterator::iterator::iterator(std::vector<int>::const_iterator iter) : it(iter) { }

int SideCrossIterator::iterator::operator*() const {    return *it;       }

SideCrossIterator::iterator& SideCrossIterator::iterator::operator++() {    return *this;   }

bool SideCrossIterator::iterator::operator!=(const iterator& other) const {    return it != other.it;}

SideCrossIterator::iterator SideCrossIterator::begin() const {    return iterator(crossOrderElements.begin());}

SideCrossIterator::iterator SideCrossIterator::end() const {    return iterator(crossOrderElements.end());}

bool PrimeIterator::isPrime(int number) {    return false;     }

PrimeIterator::PrimeIterator(const MagicalContainer& cont) : container(cont) { }

PrimeIterator::iterator::iterator(std::vector<int>::const_iterator iter) : it(iter) { }

int PrimeIterator::iterator::operator*() const {    return *it;    }

PrimeIterator::iterator& PrimeIterator::iterator::operator++() {    return *this;    }

bool PrimeIterator::iterator::operator!=(const iterator& other) const {    return it != other.it;    }

PrimeIterator::iterator PrimeIterator::begin() const {    return iterator(primeElements.begin());    }

PrimeIterator::iterator PrimeIterator::end() const {    return iterator(primeElements.end());    }
