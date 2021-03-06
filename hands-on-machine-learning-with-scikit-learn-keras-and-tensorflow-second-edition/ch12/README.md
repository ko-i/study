# 第12章 使用TensorFlow自定义模型和训练

---

### 练习题
---

###### 1. 如何用一句话形容TensorFlow？他的主要特点是什么？你可以说出其它流行的深度学习库吗？
> TensorFlow是一个用于数值计算的开源库，很适合大规模机器学习并对其进行微调。他的主要特点是支持GPU，分布式计算，计算图分析和优化功能。其它有pytorch，mxnet，theano，caffe2之类
---
###### 2. TensorFlow是否可以简单代替NumPy？两者之间的主要区别是什么？
> 不能简单替代，有些函数行为是不相同的，函数命名方式也不一样。代表有矩阵的转置操作。
---
###### 3. 使用tf.range(10)和tf.constant(np.arange(10))是否会得到相同的结果？
> 前者是32位整数，后者是64位整数。
---
###### 4. 除了常规张量之外，你还能说出TensorFlow中可用的其它6个数据结构吗？
> 稀疏张量，张量数组，参差不齐的张量，队列，字符串张量，集合
---
###### 5. 可以通过编写函数或继承keras.losses.Loss类来自定义损失函数。你何时会使用哪个方法？
> 通常都可以用常规python函数。但是如果要支持某些超参数，则应该继承。
---
###### 6. 同样，自定义指标可以在函数中定义或者在keras.metrics.Metric子类中定义。你何时会使用哪种方法？
> 这个也跟上一题一样。
---
###### 7. 什么时候应该自定义图而不是自定义模型？
> 应该将模型与层区分开。
---
###### 8. 有哪些示例需要编写你自己的自定义循环训练？
> 确定有需要的时候，当现有fit()无法满足要求时。
---
###### 9. 自定义Keras组件可以包含任意Python代码，还是必须转换为TF函数？
> 应该转换为TF函数。
---
###### 10. 如果要将函数转换为TF函数，应遵循哪些主要规则？
> 略。
---
###### 11. 你何时需要创建动态Keras模型？你是怎样做的？为什么不让所有模型都动态化？
> 创建动态keras模型对调试很有用，并且可以使用任何python调试器来调试代码。在创建模型时设置dynamic = True或者在调用模型时compile中参数设置run_eagerly = True。动态模型会降低训练和推理的速度。
---