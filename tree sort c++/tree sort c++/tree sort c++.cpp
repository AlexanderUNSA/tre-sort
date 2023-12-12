#include <iostream>
#include <ctime>
#include <cstdlib>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void in_order_traversal(Node* root, std::vector<int>& sorted_arr) {
    if (root) {
        in_order_traversal(root->left, sorted_arr);
        sorted_arr.push_back(root->key);
        in_order_traversal(root->right, sorted_arr);
    }
}

std::vector<int> tree_sort(std::vector<int>& arr) {
    Node* root = nullptr;

    for (int value : arr) {
        root = insert(root, value);
    }

    std::vector<int> sorted_arr;
    in_order_traversal(root, sorted_arr);

    return sorted_arr;
}

int main() {
    srand(time(0));

    std::vector<int> sizes = { 100, 1000, 2000, 3000, 4000, 5000 };

    for (int size : sizes) {
        // Generate a random list
        std::vector<int> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = rand() % 1000;
        }

        // Measure the time taken to sort
        clock_t start = clock();
        auto sorted_vec = tree_sort(vec);
        clock_t end = clock();

        double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Size: " << size << ", Time: " << elapsed_time << " seconds\n";
    }

    return 0;
}