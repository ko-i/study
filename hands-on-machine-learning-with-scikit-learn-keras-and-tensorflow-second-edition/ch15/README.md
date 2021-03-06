# 第15章 使用RNN和CNN处理序列

---

### 练习题
---

###### 1. 你能想到序列对序列RNN的一些应用吗？序列到向量RNN和向量到序列RNN呢？
> * 对于序列到序列的RNN：预测天气（或任何其它时间序列），机器翻译（使用编码器-解码器结构）、视频字幕、语音到文本、音乐生成（或其它序列生成）、识别歌曲的和弦。
> * 对于从序列到向量的RNN：安音乐流派对音乐样本进行分类、分析书评的情绪、根据脑植入物的读书预测失语症患者正在思考的单词、根据用户的观看记录来预测他们观看一个电影的概率（这是推荐系统协作过滤的许多可能实现之一）
> * 对于向量到序列的RNN：图像字幕、基于当前艺术家来创建音乐播放列表、基于一组参数生成旋律、在图片中定位行人（例如，来自自动驾驶骑车摄像头的视频帧）
---
###### 2. RNN层的输入必须要有多少个维度？每个维度代表什么？他的输出如何？
> RNN的输入层必须具有三维输入：第一维是批量处理的维度（其大小是批处理大小），第二维表示时间（其大小是时间步长数），第三位表示在每个时间步长的输入（其大小事每个时间步长的输入特征的数量）。例如，如果要处理包含5个时间序列（每个10个时间步长）的批处理，每个时间步长有两个值（例如温度和风速）则维度将为[5, 10, 2]，输出也是三维的，前两个维度相同，但最后一个维等于神经元数量。例如，具有32个神经元的RNN层处理了刚才讨论的批处理，则输出维度将为[5, 10, 32]。
---
###### 3. 如果要构建深度序列对序列RNN，则哪个RNN层应具有return_sequences = True？序列到向量RNN呢？
>  如果要使用Keras来构建深度序列到序列的RNN，必须为所有RNN层设置。序列到向量的话只有顶层要设置为False。
---
###### 4. 假设你有一个日常不变的时间序列，并且希望预测接下来的7天。你应该使用哪种RNN架构？
> 最简单的RNN架构是堆叠RNN层，在输出RNN层用7个神经元，然后使用时间序列的随机窗口来训练模型（例如：连续30天的序列作为输入，而包含接下来7天的值的向量作为目标输出）。这是序列到向量的RNN。你也可以在所有RNN层中设置...=True来创建序列到序列的RNN。你可以使用时间序列中的随机窗口来训练该模型，作为目标序列的长度与输入长度相同。每个目标序列的每个时间步长应具有7个值（例如，对于时间步长t，目标应包含时间步长t+1到t+7的值的向量）
---
###### 5. 训练RNN的主要困难是什么？你如何处理他们？
> 训练RNN的主要困难是不稳定的梯度（爆发或消失）和非常有限的短期记忆。当处理长序列时这些会变得很糟。为了解决不稳定梯度的问题，可以使用较小的学习率与饱和的tanh激活函数，并可以在每个时间步长中使用梯度裁剪，层归一化或dropout。要解决短期记忆问题，可以使用LSTM或者GRU。
---
###### 6. 你能勾勒出LSTM的单元的架构吗？
> LSTM单元的架构看起来很复杂，但是如果你了解底层逻辑，实际上并不困难。该单元具有短期状态向量和长期状态向量。在每个时间步长中，输入和先前的短期状态向量被馈送到一个简单的RNN单元和三个门：遗忘门决定从长期状态中删除什么，输入门决定简单RNN单元的输出的哪一部分被加入长期记忆中。然后输出门决定输出长期状态的哪一部分（经过tanh函数激活后）。新的短期状态决定单元输出。
---
###### 7. 为什么要在RNN中使用一维卷积层？
> 一个RNN层基本上是顺序的：为了在时间步长t中计算输出，他必须在所有较早的时间步长中计算输出。这使得不可能并行计算。另一方面，一维卷积层很适合并行化，因为它不包吃时间步长中的状态。换句话说，他没有内存：在任何时间步长的输出都仅基于输入值的一小窗口进行计算，而不必知道所有过去的值。此外，由于一维卷积层不是递归的，因此受到不稳定梯度的影响较小。RNN中的一个或多个一维卷积层可以有效的预处理输入，例如降低其时间分辨率（下采样），从而帮助RNN检验长期模式。实际上，通过构建wavenet架构，可以只使用卷积层。
---
###### 8. 你可以使用哪种神经网络架构对视频进行分类？
> 为了能根据视频的视觉内容对视频进行分类，一种可能的架构是每秒取1帧，然后通过相同的卷积神经网络运行每一帧（例如，预训练的Xveption模型，如果你的数据集不大，可能不需要修改），将CNN的输出序列提供给序列到向量的RNN，最后通过softmax层运行，输出所有类的概率。进行训练时，你可以将交叉熵用作成本函数。如果你还想用音频分类，则可以使用堆叠的一维卷积层将时间分辨率从每秒数千个音频帧降低到每秒一个，并将输出序列连接到序列到向量的RNN输入。
---
