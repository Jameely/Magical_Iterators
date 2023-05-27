#include "doctest.h"
#include "sources/MagicalContainer.h"

    // Test case 1: Testing the addElement function
    TEST_CASE("Test addElement function") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);

        CHECK_EQ(container.size(), 2);

        const std::vector<int> elements = container.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 10);
    }

    // Test case 2: Testing the removeElement function
    TEST_CASE("Test removeElement function") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.removeElement(10);

        CHECK_EQ(container.size(), 2);

        const std::vector<int>& elements = container.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 15);
    }

    // Test case 3: Testing the AscendingIterator
    TEST_CASE("Test AscendingIterator") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);

        std::vector<int> expectedElements = {2, 5, 10};

        std::vector<int>::size_type index = 0;
        for (int element : AscendingIterator(container)) {
            CHECK_EQ(element, expectedElements[index]);
            ++index;
        }
    }

    // Test case 4: Testing the SideCrossIterator
    TEST_CASE("Test SideCrossIterator") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        std::vector<int> expectedElements = {10, 2, 7, 5};

        std::vector<int>::size_type index = 0;
        for (int element : SideCrossIterator(container)) {
            CHECK_EQ(element, expectedElements[index]);
            ++index;
        }
    }

    // Test case 5: Testing the PrimeIterator
    TEST_CASE("Test PrimeIterator") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);
        container.addElement(9);

        std::vector<int> expectedElements = {5, 2, 7};

        std::vector<int>::size_type index = 0;
        for (int element : PrimeIterator(container)) {
            CHECK_EQ(element, expectedElements[index]);
            ++index;
        }
    }

    // Test case 6: Testing the copy constructor
    TEST_CASE("Test copy constructor") {
        MagicalContainer container1;
        container1.addElement(5);
        container1.addElement(10);

        MagicalContainer container2(container1);

        CHECK_EQ(container2.size(), 2);

        const std::vector<int>& elements = container2.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 10);
    }

    // Test case 7: Testing the assignment operator
    TEST_CASE("Test assignment operator") {
        MagicalContainer container1;
        container1.addElement(5);
        container1.addElement(10);

        MagicalContainer container2;
        container2 = container1;

        CHECK_EQ(container2.size(), 2);

        const std::vector<int>& elements = container2.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 10);
    }

    // Test case 8: Testing self-assignment in assignment operator
    TEST_CASE("Test self-assignment in assignment operator") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);

        container = container; // Self-assignment

        CHECK_EQ(container.size(), 2);

        const std::vector<int>& elements = container.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 10);
    }

    // Test case 9: Testing the move constructor
    TEST_CASE("Test move constructor") {
        MagicalContainer container1;
        container1.addElement(5);
        container1.addElement(10);

        MagicalContainer container2(std::move(container1));

        CHECK_EQ(container2.size(), 2);

        const std::vector<int>& elements = container2.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 10);
    }

    // Test case 10: Testing the move assignment operator
    TEST_CASE("Test move assignment operator") {
        MagicalContainer container1;
        container1.addElement(5);
        container1.addElement(10);

        MagicalContainer container2;
        container2 = std::move(container1);

        CHECK_EQ(container2.size(), 2);

        const std::vector<int>& elements = container2.getElements();
        CHECK_EQ(elements.size(), 2);
        CHECK_EQ(elements[0], 5);
        CHECK_EQ(elements[1], 10);
    }