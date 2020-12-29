// Day 1
// -----
// Specifically, they need you to find the two entries that sum to 2020 and then
// multiply those two numbers together.
//
// For example, suppose your expense report contained the following:
//
// 1721 979 366 299 675 1456 In this list, the two entries that sum to 2020 are
// 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the
// correct answer is 514579.
//
// Of course, your expense report is much larger. Find the two entries that sum to
// 2020; what do you get if you multiply them together?

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

int day1(std::vector<int> const& nums) {
    // For each a in nums, calculate b such that a + b = 2020. Store b => a in
    // the map. If b ever appears in nums again, we can immediately return the
    // product, a * b
    std::unordered_map<int, int> targets;
    for (int n : nums) {
        if (auto it = targets.find(n);
                it != targets.end())
        {
            return n * it->second;
        }
        // Don't care if we overwrite
        int target = 2020 - n;
        targets[target] = n;
    }
    throw std::runtime_error("No solution");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        throw std::runtime_error("Path to input file is required");
    }
    std::string ifname = argv[1];
    std::ifstream f(ifname);
    std::vector<int> nums;
    if (f) {
        int n;
        while (f >> n) {
            nums.push_back(n);
        }
    } else {
        throw std::runtime_error("Invalid file : " + ifname);
    }

    std::cout << day1(nums) << std::endl;

    return 0;
}
