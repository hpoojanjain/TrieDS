#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int count = 0;
  Node *childNode[2];
  bool ContainsKey(int ind)
  {
    return childNode[ind] != NULL;
  }
  Node *get(int ind)
  {
    return childNode[ind];
  }
  void put(int ind, Node *curNode)
  {
    childNode[ind] = curNode;
  }
};

class Trie
{
  int N = 31;
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }
  void insert(int x, int y = 1)
  {
    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (!curNode->ContainsKey(bit))
      {
        curNode->put(bit, new Node());
      }
      curNode = curNode->get(bit);
      curNode->count += y;
    }
  }

  void erase(int x, int y = 1)
  {
    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (curNode->ContainsKey(bit))
      {
        curNode = curNode->get(bit);
      }
      else
      {
        return;
      }
      curNode->count -= y;
    }
  }
  int countOccurences(int x)
  {
    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (curNode->ContainsKey(bit))
      {
        curNode = curNode->get(bit);
      }
      else
      {
        return 0;
      }
    }
    return curNode->count;
  }

  int findsmallest(int k = 1)
  {
    int ans = 0;
    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int left = (curNode->ContainsKey(0) ? curNode->get(0)->count : 0);
      if (left >= k)
      {
        curNode = curNode->get(0);
      }
      else
      {
        k -= left;
        curNode = curNode->get(1);
        ans += (1LL << i);
      }
    }
    return ans;
  }

  void eraseSmallest(int k)
  {

    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int left = (curNode->ContainsKey(0) ? curNode->get(0)->count : 0);
      if (left >= k)
      {
        curNode = curNode->get(0);
      }
      else
      {
        k -= left;
        curNode = curNode->get(1);
      }
      curNode->count--;
    }
  }

  int findgreatest(int k = 1)
  {
    int ans = 0;
    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int right = (curNode->ContainsKey(1) ? curNode->get(1)->count : 0);

      if (right >= k)
      {
        curNode = curNode->get(1);
        ans += (1 << i);
      }
      else
      {
        k -= right;
        curNode = curNode->get(0);
      }
    }
    return ans;
  }

  void erasegreatest(int k = 1)
  {

    Node *curNode = root;
    for (int i = N; i >= 0; --i)
    {
      int right = (curNode->ContainsKey(1) ? curNode->get(1)->count : 0);

      if (right >= k)
      {
        curNode = curNode->get(1);
      }
      else
      {
        k -= right;
        curNode = curNode->get(0);
      }
      curNode->count--;
    }
  }

  int countSmaller(int x, int y = 0)
  {
    Node *curNode = root;
    int ans = 0;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (bit == 1 && curNode->ContainsKey(0))
      {
        ans += curNode->get(0)->count;
      }
      if (curNode->ContainsKey(bit) == NULL)
      {
        return ans;
      }
      curNode = curNode->get(bit);
    }
    return ans + (y == 1 ? curNode->count : 0);
  }

  int countGreater(int x, int y = 0)
  {
    Node *curNode = root;
    int ans = 0;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (bit == 0 && curNode->ContainsKey(1))
      {
        ans += curNode->get(1)->count;
      }
      if (curNode->ContainsKey(bit) == NULL)
      {
        return ans;
      }
      curNode = curNode->get(bit);
    }
    return ans + (y == 1 ? curNode->count : 0);
  }

  int maxxor(int x)
  {
    Node *curNode = root;
    int ans = 0;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (curNode->ContainsKey(1 - bit))
      {
        ans += (1 << i);
        curNode = curNode->get(1 - bit);
      }
      else
      {
        curNode = curNode->get(bit);
      }
    }
    return ans;
  }
  int minxor(int x)
  {
    Node *curNode = root;
    int ans = 0;
    for (int i = N; i >= 0; --i)
    {
      int bit = (x >> i) & 1;
      if (curNode->ContainsKey(bit))
      {
        ans += (1 << i);
        curNode = curNode->get(bit);
      }
      else
      {
        curNode = curNode->get(1 - bit);
      }
    }
    return ans;
  }
};
