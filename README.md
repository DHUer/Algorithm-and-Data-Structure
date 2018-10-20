# Algorithm-and-Data-Structure
## 好像有人说过:
> the essence of algorithm is compromise of time and space

## 在这里我主要实现的是《计算机算法设计与分析》

*  回溯法主要由四个部分组成
      > 递归回溯:
      ```C
      void Backtrack(int t)
      {
          if(t>n) Output(x);
          else
            for(int i=f(n,t);i<g(n,t);i++)
            {
                x[t]=h[i];
                if(Constraint(t)&&Bound(t))
                    Backtrack(t+1);
            }
      }
      ```
      
      > 迭代回溯:
      ```C
      void IterativeBackTrack(void)
      {

      }
      > 子集树算法框架
      > 排列树算法框架


 