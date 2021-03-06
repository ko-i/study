# 第8章 降维

---

### 练习题
---

###### 1. 减少数据集维度的主要动机是什么？主要缺点是什么？
> 主要动机是为了减缓维度诅咒带来的影响。主要缺点是有可能会损失一些信息。
---
###### 2. 维度的诅咒是什么？
> 地为空间站的彼此距离很近的数据样例在高纬空间中可能非常稀疏，会带来过拟合的风险。
---
###### 3. 一旦降低了数据集的维度，是否可以逆操作？如果可以，怎么做？如果不能，为什么？
> 不能完美的逆转，必将损失一些信息，有的降维算法可以，比如PCA，有些不能，比如t-SNE。
---
###### 4. 可以使用PCA来减少高度非线性数据集的维度吗？
> 如果数据集中存在大量无用的维度的话可以，如果数据集中的维度都是有用的，那就不行了。
---
###### 5. 假设你在1000维的数据集上执行PCA，将可解释方差比设置为95%。结果数据集将具有多少个维度？
> 这个不一定啊，取决于数据集的具体情况。
###### 6. 在什么情况下，你将使用常规PCA？增量PCA？随机PCA或内核PCA？
> 1. 在内存能够支持数据集的情况下一般使用常规PCA。
> 2. 在内存不能支持数据集的情况下使用增量PCA。
> 3. 在内存允许的情况下并且想快速降低维度就用随机PCA。
> 4. 在非线性数据集上运用内核PCA。
---
###### 7. 如何评价数据集中的降维算法的性能？
> 1. 计算重构误差。
> 2. 控制变量，直接观察降维与否在后续算法中表现出来的结果如何。
---
###### 8. 连接两个降维算法是否有意义？
> 有意义，比如先用PCA去除大量无用的维度，再用其它降维算法来降维，这比直接运用其它降维算法来块的多。当然，得在数据集有大量无用算法的情况下。
