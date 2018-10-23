#ifndef __NATASHA_STATICCASCADINGREELS3X5_H__
#define __NATASHA_STATICCASCADINGREELS3X5_H__

#include <assert.h>
#include <map>
#include "../protoc/base.pb.h"
#include "reels.h"

namespace natasha {

class StaticCascadingReels3X5 {
 public:
  // typedef SymbolBlock<SymbolType, Width, Height> SymbolBlockT;
  // typedef BaseReels<SymbolType, Width, Height> BaseReelsT;
  typedef std::vector< ::natashapb::SymbolBlock3X5*> SymbolBlockData;
  typedef std::vector<SymbolBlockData*> SymbolBlockDataList;

 public:
  StaticCascadingReels3X5() : m_maxDownNums(-1) {}
  ~StaticCascadingReels3X5() {}

 public:
  void random(::natashapb::RandomResult* pRandomResult);

  void clear();

  bool isEmpty() const { return m_lst.empty(); }

 public:
  void newRow() { m_lst.push_back(new SymbolBlockData()); }

  void newColumn(int row, const ::natashapb::SymbolBlock3X5& sb);

  int getLength() const { return m_lst.size(); }

  void setMaxDownNums(int maxDownNums) { m_maxDownNums = maxDownNums; }

 protected:
  void randomNew(::natashapb::StaticCascadingRandomResult3X5* pSCRR);

 protected:
  int m_maxDownNums;
  SymbolBlockDataList m_lst;
};

}  // namespace natasha

#endif  // __NATASHA_STATICCASCADINGREELS3X5_H__