#ifndef LISTNODE_H
#define LISTNODE_H

#include <memory>

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    explicit ListNode(const int x): val(x), next(nullptr) {}
};

#endif
