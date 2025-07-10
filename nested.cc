/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
  int i, j;
  vector<NestedInteger> nestedList;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    i = 0;
    j = 0;
    this->nestedList = nestedList;
  }

  int next() {
    int val;
    if(nestedList[i].isInteger()) {
      val = nestedList[i].getInteger();
      ++i;
      j = 0;
    } else {
      while(!nestedList[i].isInteger() && !nestedList[i].getList().size())
        ++i;
      
      val = nestedList[i].getList()[j].getInteger();
      ++j;
      if(j == nestedList[i].getList().size()) {
        ++i;
        j = 0;
      }
    }
      
    return val;
  }

  bool hasNext() {
    if(!nestedList.size())
      return false;

    if(j == 0) {
      while(i < nestedList.size() && !nestedList[i].isInteger() && !nestedList[i].getList().size())
        ++i;
      if(i == nestedList.size())
        return false;
    }
      
    
    if(i < nestedList.size() - 1)
      return true;
    else if (i == nestedList.size() - 1) {
      if(nestedList[i].isInteger())
        return j == 0;
      else
        return j < nestedList[i].getList().size();
    } else
      return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
