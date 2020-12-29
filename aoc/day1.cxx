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
#include <optional>

std::optional<std::pair<int, int>> day1(std::vector<int> const& nums, int goal = 2020)
{
    // For each a in nums, calculate b such that a + b = 2020. Store b => a in
    // the map. If b ever appears in nums again, we can immediately return the
    // product, a * b
    std::unordered_map<int, int> targets;
    for (int n : nums) {
        if (auto it = targets.find(n);
                it != targets.end())
        {
            return std::make_pair(n, it->second);
        }
        // Don't care if we overwrite
        int target = goal - n;
        targets[target] = n;
    }
    return std::nullopt;
}

// The Elves in accounting are thankful for your help; one of them even offers you
// a starfish coin they had left over from a past vacation. They offer you a
// second one if you can find three numbers in your expense report that meet the
// same criteria.
//
// Using the above example again, the three entries that sum to 2020 are 979, 366,
//       and 675. Multiplying them together produces the answer, 241861950.
//
// In your expense report, what is the product of the three entries that sum to
// 2020?

std::optional<std::tuple<int,int,int>> part2(std::vector<int> const& nums, int goal = 2020)
{
    for (int a : nums) {
        int derivedGoal = goal - a;
        auto res = day1(nums, derivedGoal);
        if (res) {
            // This means there existed b, c in nums such that b + c = 2020 - a
            return std::make_tuple(a, res->first, res->second);
        }
    }
    return std::nullopt;
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

    auto day1Res = day1(nums);
    if (day1Res) {
        int a = day1Res->first;
        int b = day1Res->second;
        std::cout << "Day 1 part 1: "
            << a << " * " << b << " = " << a * b
            << std::endl;
    }
    auto part2Res = part2(nums);
    if (part2Res) {
        int a = std::get<0>(*part2Res);
        int b = std::get<1>(*part2Res);
        int c = std::get<2>(*part2Res);
        std::cout << "Day 1 part 2: "
            << a << " * " << b << " * " << c << " = " << a * b * c
            << std::endl;
    } else {
        throw std::runtime_error("No solution");
    }


    return 0;
}
