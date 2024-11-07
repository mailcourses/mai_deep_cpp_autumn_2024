#include <iostream>
#include <unordered_map>
#include <vector>

template<class C, class I>
auto get_element(C &arr, I i) -> decltype(arr[i])
{
    // ...
    return arr[i];
}

int main()
{
    std::vector<std::string> arr1(10);
    get_element(arr1, 0);

    std::vector<int> arr2(10);
    get_element(arr2, 6);
    get_element(arr2, 0);

    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> counter;
    // ...
    //std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>::iterator it = d.begin();
    auto it = counter.begin();

    decltype(counter.begin()) it2 = counter.begin();

    for (size_t i = 0; i < arr1.size(); ++i) {
        std::string& elem = arr1[i];
        // ...
    }

    for (std::string& elem : arr1) {

    }

    for (const std::pair<std::string, std::vector<std::pair<int, std::string>>>& elem : counter) {
        //...
    }

    for (const auto& elem : counter) {
        //...
    }

}
