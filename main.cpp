#include <iostream>
#include <vector>
#include <cmath>

class BlockSearch {
private:
    std::vector<int> data;     // 存储数据
    std::vector<int> index;    // 索引数组
    int blockSize;             // 块的大小

public:
    BlockSearch(const std::vector<int>& arr) {
        data = arr;
        blockSize = std::sqrt(data.size()); // 一个简单的块大小定义，例如根号下数据量大小
        createIndex();
    }

    // 创建索引
    void createIndex() {
        for (int i = 0; i < data.size(); i += blockSize) {
            index.push_back(data[i]);
        }
    }

    // 分块查找
    int search(int target) {
        int i;
        // 在索引中找到对应的块
        for (i = 0; i < index.size(); ++i) {
            if (target < index[i])
                break;
        }

        // 在确定的块中线性搜索
        int startBlock = (i - 1) * blockSize;
        int endBlock = std::min(startBlock + blockSize, (int)data.size());
        for (int j = startBlock; j < endBlock; ++j) {
            if (data[j] == target)
                return j; // 返回元素在数组中的位置
        }

        return -1; // 未找到
    }

    // 打印索引
    void printIndex() {
        std::cout << "Index:";
        for (int i : index) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> arr = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41};
    BlockSearch blockSearch(arr);

    blockSearch.printIndex();

    int target = 23;
    int index = blockSearch.search(target);

    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
