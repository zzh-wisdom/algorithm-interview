#include <iostream>
#include <string>
#include <atomic>
#include <pthread.h>
#include <thread>

using namespace std;

class PrizePool {
public:
  void send(string input) {
    cout << input;
  }
};

class ReviewEncourage {
  int n_;
  atomic<int> num;
public:
  ReviewEncourage(int n): num(1) { // 构造函数,n为中奖用户数
    n_ = n;
  }
  /*
    PrizePool类仅有一个send方法，实现如下：
    public class PrizePool {
        public void send(String input) {
            System.out.print(input);
        }
    }
  */
  void bonus(PrizePool* prizePool) { // 仅能打印A，表示发放积分
    int tmp;
    while((tmp = num.load()) <= n_) {
      if(tmp&1) {
        prizePool->send("A");
        num.fetch_add(1);
      } else {
        // pthread_yield();
      }
    }
  }
  void coupon(PrizePool* prizePool) { // 仅能打印B，表示发放优惠券
    int tmp;
    while((tmp = num.load()) <= n_) {
      if((tmp&3) == 2) {
        prizePool->send("B");
        num.fetch_add(1);
      } else {
        // pthread_yield();
      }
    }
  }
  void contribution(PrizePool* prizePool) { // 仅能打印C，表示发放贡献值
    int tmp;
    while((tmp = num.load()) <= n_) {
      if((tmp&3) == 0) {
        prizePool->send("C");
        num.fetch_add(1);
      } else {
        // pthread_yield();
      }
    }
  }
};

void bonus(ReviewEncourage* re, PrizePool* prizePool) {
  re->bonus(prizePool);
}

void coupon(ReviewEncourage* re, PrizePool* prizePool) {
  re->coupon(prizePool);
}

void contribution(ReviewEncourage* re, PrizePool* prizePool) {
  re->contribution(prizePool);
}

int main() {
  int n;
  cin >> n;
  ReviewEncourage* re = new ReviewEncourage(n);
  PrizePool* prizePool = new PrizePool();
  thread t1(bonus, re, prizePool); // pass by value
  thread t2(coupon, re, prizePool); // pass by value
  thread t3(contribution, re, prizePool); // pass by value
  t1.join();
  t2.join();
  t3.join();
  delete re;
  delete prizePool;
  return 0;
}