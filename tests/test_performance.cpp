#include <gtest/gtest.h>
#include <chrono>
#include "../include/common.hpp"
#include "../include/apriori.hpp"
#include "../include/declat.hpp"

class FIMPerformanceTest : public ::testing::Test {
protected:
    TransactionDB db;

    void SetUp() override {
        // Uncomment when ready to test with real files
        // db = TransactionDB::LoadDatabase("datasets/connect.txt");
    }
};

TEST_F(FIMPerformanceTest, Benchmark_dEclat_Speedup) {
    if(db.transactions.empty()) GTEST_SKIP() << "Dataset not loaded. Skipping performance test.";

    float min_sup = 0.80; // High support to keep Apriori execution reasonable

    auto start_apriori = std::chrono::high_resolution_clock::now();
    auto res_apriori = Apriori::Mine(db, min_sup);
    auto end_apriori = std::chrono::high_resolution_clock::now();
    auto duration_apriori = std::chrono::duration_cast<std::chrono::milliseconds>(end_apriori - start_apriori).count();

    auto start_declat = std::chrono::high_resolution_clock::now();
    auto res_declat = DEclat::Mine(db, min_sup);
    auto end_declat = std::chrono::high_resolution_clock::now();
    auto duration_declat = std::chrono::duration_cast<std::chrono::milliseconds>(end_declat - start_declat).count();

    // Assert functional parity before trusting the speedup
    EXPECT_EQ(res_apriori.size(), res_declat.size());
    
    RecordProperty("Apriori_Time_ms", duration_apriori);
    RecordProperty("dEclat_Time_ms", duration_declat);

    // Expect dEclat to be faster than Apriori on dense datasets
    EXPECT_LT(duration_declat, duration_apriori);
}
