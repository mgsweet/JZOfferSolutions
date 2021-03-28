class LRUCache {
public:
  LRUCache(int capacity) : cache_size_(capacity) {}

  int get(int key) {
    if (cache_.find(key) == cache_.end()) return -1;
    touch(cache_[key]);
    return cache_[key].first;
  }

  void put(int key, int value) {
    if (cache_.find(key) != cache_.end()) {
      touch(cache_[key]);
    } else {
      if (cache_.size() == cache_size_) {
        cache_.erase(used.back());
        used.pop_back();
      }
      used.push_front(key);
    }
    cache_[key] = {value, used.begin()};
  }

public:
  typedef list<int> LI;
  typedef pair<int, LI::iterator> PILI;
  typedef unordered_map<int, PILI> HPILI;

  void touch(PILI &pili) {
    int key = *(pili.second);
    used.erase(pili.second);
    used.push_front(key);
    pili.second = used.begin();
  }

  int cache_size_;
  HPILI cache_;
  LI used;
};