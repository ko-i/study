import sys
from numpy import mat, mean, power

def read_input(file):
    for line in file:
        yield line.rstrip()
       
input = read_input(sys.stdin)

mapperOut = [line.split('\t') for line in input]

cumVal = 0.0
cumSumSq = 0.0
cumN = 0.0
for instance in mapperOut:
    nj = float(instance[0])
    cumN += nj
    cumVal += nj * float(instance[1])
    cumSumSq += nj * float(instance[2])
    
#calculate means
mean = cumVal/cumN
meanSq = cumSumSq/cumN

#output size, mean, mean(square values)
print('%d\t%f\t%f' % (cumN, mean, meanSq))
print(sys.stderr, "report: still alive")