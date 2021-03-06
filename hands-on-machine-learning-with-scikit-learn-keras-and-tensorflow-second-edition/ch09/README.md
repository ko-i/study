# 第9章 聚类

---

### 练习题
---

###### 1. 如何定义聚类？你能列举几种聚类算法吗？
> 聚类就是把一些距离相近，特征值相近的一些实例归为一类，是一种无监督学习方法。有K-means，DBSCAN，高斯混合模型，贝叶斯高斯混合模型等。
---
###### 2. 聚类算法的主要运用有哪些？
> 可以用来压缩数据，降维数据，运用到半监督学习方法中，异常值检测等。
---
###### 3. 描述两种使用K-means时选择正确数目的集群的技术。
> 计算惯性（肘部算法）和计算轮廓分数。
---
###### 4. 什么是标签传播？为什么要实施它，如何实现？
> 使用较少的标记数据，依据聚类算法来自动标记大量数据。因为手动标记费时费力。先使用聚类算法聚类，然后再在每个聚类中选择最具代表性的实例的标签，将其他实例的标签值都设成这个。
---
###### 5. 你能否说出两种可以扩展到大型数据集的聚类算法？两个寻找高密度区的聚类算法？
> K-means与BIRCH可以扩展到大数据集，DBSCAN和mean-shift可以寻找高密度区。
---
###### 6. 你能想到一个主动学习有用的实例吗？你将如何实施它？
> 在有大量未标记数据的时候可以使用主动学习。
---
###### 7. 异常检测和新颖性检测有什么区别？
> 异常检测是检测训练数据集中的异常，新颖性会假设训练集没有异常，会寻找新数据集中的离群值。
---
###### 8. 什么是高斯混合模型？你可以将其运用于哪些任务？
> 高斯混合模型是一种概率模型，它假定实例是由参数未知的多个高斯分布的混合生成的。换句话说，我们假设数据可以分为有限数量的集群，每个集群具有椭圆的形状，而我们不知道每个实例具体属于哪个簇，该模型可以用于密度估计，聚类和异常值检测。
---
###### 9. 使用高斯混合模型时，你能否列举出两种技术来找到正确数量的集群？
> 使用高斯混合模型时，找到正确数量的集群的一种方法是将贝叶斯信息准则和赤池信息准则作为集群数量的函数绘制出来，然后选择使其最小化的集群数量。另一种技术是使用贝叶斯高斯混合模型，该模型可以自动选择集群数。