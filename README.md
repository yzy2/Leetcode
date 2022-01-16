# Grinding Leetcode

Found this interesting plugin that auto uploads my leetcode solution to github. What a nice way to keep the work!

Also will use this repo to document some notes I have while grinding.

Happy Grinding!

### Guessitmate Accpeted Algo
<pre>
- Size of Input -> Worst accepted algorithm
- [10....11]    -> O(N!) ,O(n^6)
- [15......18]  -> O(2^N*N^2)
- [18......22]  -> O(2^N*N)
- 100           -> O(N^4)
- 400           -> O(N^3)
- 2K            -> O(N^2*logN)
- 10K           -> O(N^2)
- 1M            -> O(N*logN)
- 100M          -> O(N),O(logN)
</pre>

### Memory Access Time
<pre>
- L1 cache reference:                           0.5 ns
- Branch mispredict:                              5 ns 
- L2 cache reference:                             7 ns 
- Mutex lock/unlock:                            100 ns 
- Main memory reference:                        100 ns  
- Compress 1K bytes with Zippy:              10,000 ns 
- Send 2K bytes over 1 Gbps network:         20,000 ns 
- Read 1 MB sequentially from memory:       250,000 ns 
- Round trip within same datacenter:        500,000 ns 
- Disk seek:                             10,000,000 ns 
- Read 1 MB sequentially from network:   10,000,000 ns  
- Read 1 MB sequentially from disk:      30,000,000 ns 
- Send packet CA->Netherlands->CA:      150,000,000 ns
</pre>

