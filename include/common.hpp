#pragma once

#include <vector>
#include <cstdint>
#include <string>

/* --- SYSTEM LIMITS --- */
constexpr size_t MAX_ITEMS_PER_TXN = 1024;
constexpr size_t MAX_TXNS = 100000;

/* --- SHARED DATA STRUCTURES --- */
struct Itemset {
    std::vector<uint32_t> items;
    uint32_t support_count = 0;
};

class TransactionDB {
public:
    std::vector<std::vector<uint32_t>> transactions;
    uint32_t max_item_id = 0;

    size_t num_transactions() const {
        return transactions.size();
    }

    // Static factory method to parse a dataset file
    static TransactionDB LoadDatabase(const std::string& filepath);
};
