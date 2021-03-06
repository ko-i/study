# 第11章 训练深度神经网络

---

### 练习题
---

###### 1. 将所有权重初始化相同的值是否可以（只要该值是使用He初始化随机选择的）？
> 不行，因为权重初始值相同的话就无法破坏其对称性了，在优化或反向传播过程中所有的值也会发生同样的变化，那跟只有一个神经元没有区别。
---
###### 2. 将偏置项初始化为0可以吗？
> 可以，偏置项没什么影响。
---
###### 3. 列举SELU激活函数相比ReLU的三个优点。
> 1. 他可以使用负值，所以相比于使用ReLU，某一给定层的神经元输出平均值更容易接近0，从而有助于缓解梯度消失问题。
> 2. 他总是有一个非零的导数，这样也可以避免影响ReLU单元的单元消失问题。
> 3. 当条件合适时（模型是顺序的，权重使用Lecun初始化，输入被标准化，并且不存在不兼容的层与正则化），SELU激活函数可以确保模型的自归一化，解决了梯度爆炸与梯度消失问题。
---
###### 4. 哪种情况下，那你想使用以下每个激活函数：SELU，leaky ReLU（及其变体）、ReLU、tanh、logistic和softmax？
> SELU作为默认选择不错。如果对神经网络速度要求很高，可以使用leaky ReLU。ReLU简单方便，可以精确输出0，也可以当做首选。当需要输出-1到1之间的数时，tanh可以用，但在隐藏层中使用不多。逻辑激活函数也是在输出层中使用的比较多。softmax是在右输出互斥要求的情况下使用的。
---
###### 5. 如果在使用SGD优化器时将超参数momentum设置的太接近1（例如0.99999），会发生什么情况？
> 算法提速会变高，偏向全局最小值，但动量的范围会超过最小值，最后慢慢降速回落，再提速...会多次震荡后收敛。
---
###### 6. 列举出三种能产生稀疏模型的方法？
> 训练完一个模型后将小于阈值的权重设为0。使用l1正则化。使用tensorflow模型优化工具箱。
---
###### 7. dropout会减慢训练速度吗？他会减慢推理速度（即对新实例的预测）吗？MCdropout呢？
> 会减慢训练速度，通常减少1/2。因为实在训练中打开，所以对推理速度没有影响。MC只会影响推理速度。
---