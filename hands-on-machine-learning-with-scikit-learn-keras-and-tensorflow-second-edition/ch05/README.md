# 第5章 支持向量机

---

### 练习题
---

###### 1. 支持向量机的基本思想是什么？
> 是为了寻找两个分类之间最大的间隔。
---

###### 2. 什么是支持向量？
> 落在间隔内或间隔分界线上的实例，关键实例。
---

###### 3. 使用SVM时，对输入值进行缩放为什么重要？
> 这样的话支持向量就会忽略那些数值较小的特征。
---

###### 4. SVM分类器在对实例进行分类时，会输出信心分数吗？概率呢？
> 都不会。
---

###### 5. 如果训练集有成百万个实例和几百个特征，你应该使用SVM原始问题还是对偶问题来训练模型？
> 用原始问题。
---

###### 6. 假设你用RBF核训练了一个SVM分类器，看起来似乎对训练集欠拟合，你应该提升还是降低gamma的值？C呢？
> 提升gamma或（和）C。
---

###### 7. 如果使用现成二次规划求解器，你应该如何设置QP参数（H，f，A和b）来解决软间隔线性SVM分类问题？
> 这个有些困难。
---

###### 8. 9. 10.略
> 
---