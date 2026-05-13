#include <gtest/gtest.h>
#include "../include/common.hpp"
#include "../include/apriori.hpp"
#include "../include/declat.hpp"

class FIMFunctionalTest : public ::testing::Test {
protected:
    TransactionDB db;

    void SetUp() override {
        // Mocking a database directly in C++
        db.transactions = {
            {1, 3, 4},
            {2, 3, 5},
            {1, 2, 3, 5},
            {2, 5},
            {1, 2, 3, 5}
        };
        db.max_item_id = 5;
    }
};

TEST_F(FIMFunctionalTest, ParityCheck) {
    if(db.transactions.empty()) GTEST_SKIP() << "Database not mocked yet.";
    
    auto apriori_results = Apriori::Mine(db, 0.40);
    auto declat_results = DEclat::Mine(db, 0.40);
    
    // Both algorithms MUST find the exact same number of frequent itemsets
    EXPECT_EQ(apriori_results.size(), declat_results.size());
}
